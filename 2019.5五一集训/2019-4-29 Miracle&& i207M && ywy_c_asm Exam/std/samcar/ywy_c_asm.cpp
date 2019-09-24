#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <unordered_map>
#define p1 1000000007
#define p2 998244353
#define int unsigned int
#define ll unsigned long long
using namespace std;
namespace ywy {
inline int get() {
    int n = 0;
    char c;
    while ((c = getchar()) || 23333) {
        if (c >= '0' && c <= '9')
            break;
        if (c == '-')
            goto s;
    }
    n = c - '0';
    while ((c = getchar()) || 23333) {
        if (c >= '0' && c <= '9')
            n = n * 10 + c - '0';
        else
            return (n);
    }
s:
    while ((c = getchar()) || 23333) {
        if (c >= '0' && c <= '9')
            n = n * 10 - c + '0';
        else
            return (n);
    }
}
typedef struct _b {
    int dest;
    int nxt;
    char c;
} bian;
bian memchi[1000001];
int gn = 1, heads[200001], ance[200001][17], deep[200001];
inline void add(int s, int t, char c) {
    memchi[gn].dest = t;
    memchi[gn].c = c;
    memchi[gn].nxt = heads[s];
    heads[s] = gn;
    gn++;
}
ll dk1[200001], dk2[200001], hsh1[200001][17], hsh2[200001][17];
int lg[200001];
void dfs(int pt, int baba) {
    for (register int i = heads[pt]; i; i = memchi[i].nxt) {
        if (memchi[i].dest == baba)
            continue;
        deep[memchi[i].dest] = deep[pt] + 1;
        ance[memchi[i].dest][0] = pt;
        hsh1[memchi[i].dest][0] = hsh2[memchi[i].dest][0] = memchi[i].c;
        dfs(memchi[i].dest, pt);
    }
}
ll ha1[200001], ha2[200001], h1[200001], h2[200001];
int tmp[200001];
typedef struct _p {
    ll a;
    ll b;
    _p(ll i, ll j) {
        a = i;
        b = j;
    }
    friend bool operator<(const _p &a, const _p &b) {
        if (a.a == b.a)
            return (a.b < b.b);
        return (a.a < b.a);
    }
    friend bool operator==(const _p &a, const _p &b) { return (a.a == b.a && a.b == b.b); }
} pair;
int anss[200001];
typedef struct _itst {
    size_t operator()(const pair &a) const { return ((a.a << 32) | a.b); }
} itst;
typedef struct _n {
    int id;
    int l;
    int r;
    _n() { id = l = r = 0; }
} node;
vector<node> vec[200001];
unordered_map<pair, int, itst> mp;
ll s1[200001], s2[200001];
inline void clear(vector<node> &v) {
    vector<node> tmp;
    v = tmp;
}
void efs(int pt, int baba) {
    for (register int i = 0; i < vec[pt].size(); i++) {
        for (register int j = vec[pt][i].l; j <= vec[pt][i].r; j++) {
            pair cjr = _p((ha1[j] * dk1[deep[pt]] + s1[pt]) % p1, (ha2[j] * dk2[deep[pt]] + s2[pt]) % p2);
            tmp[j] = mp[cjr];
        }
    }
    mp[_p(s1[pt], s2[pt])]++;
    for (register int i = heads[pt]; i; i = memchi[i].nxt) {
        if (memchi[i].dest == baba)
            continue;
        s1[memchi[i].dest] = (s1[pt] + dk1[deep[memchi[i].dest]] * memchi[i].c) % p1;
        s2[memchi[i].dest] = (s2[pt] + dk2[deep[memchi[i].dest]] * memchi[i].c) % p2;
        efs(memchi[i].dest, pt);
    }
    for (register int i = 0; i < vec[pt].size(); i++) {
        anss[vec[pt][i].id] = 0;
        for (register int j = vec[pt][i].l; j <= vec[pt][i].r; j++) {
            pair cjr = _p((ha1[j] * dk1[deep[pt]] + s1[pt]) % p1, (ha2[j] * dk2[deep[pt]] + s2[pt]) % p2);
            anss[vec[pt][i].id] += (mp[cjr] - tmp[j]);
        }
    }
    clear(vec[pt]);
}
char str[200001];
ll zheng1[200001], zheng2[200001], fan1[200001], fan2[200001];
inline char cget() {
    char c;
    while ((c = getchar()) || 23333)
        if (c >= 'a' && c <= 'z')
            return (c);
}
inline int sget() {
    int ptr = 1;
    char c;
    while ((c = getchar()) || 23333)
        if (c >= 'a' && c <= 'z')
            break;
    str[ptr] = c;
    ptr++;
    while ((c = getchar()) || 23333) {
        if (c >= 'a' && c <= 'z')
            str[ptr] = c, ptr++;
        else
            return (ptr - 1);
    }
}
void print(int num) {
    if (num >= 10)
        print(num / 10);
    putchar(num % 10 + '0');
}
void ywymain() {
    // freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    int id;
    cin >> id;
    dk1[0] = dk2[0] = 1;
    lg[0] = -1;
    for (register int i = 1; i <= 100000; i++) {
        dk1[i] = (dk1[i - 1] * 233) % p1;
        dk2[i] = (dk2[i - 1] * 233) % p2;
        lg[i] = lg[i - 1];
        if (i == (i & -i))
            lg[i]++;
    }
    int t;
    cin >> t;
    while (t) {
        t--;
        int n = get(), q = get(), r = get();
        memset(ance, 0, sizeof(ance));
        deep[r] = 0;
        gn = 1;
        memset(heads, 0, sizeof(heads));
        s1[r] = s2[r] = 0;
        memset(hsh1, 0, sizeof(hsh1));
        mp.clear();
        memset(hsh2, 0, sizeof(hsh2));
        int m = sget();
        for (register int i = 1; i <= m; i++) {
            zheng1[i] = (zheng1[i - 1] * 233 + str[i]) % p1;
            zheng2[i] = (zheng2[i - 1] * 233 + str[i]) % p2;
            fan1[i] = (fan1[i - 1] * 233 + str[m - i + 1]) % p1;
            fan2[i] = (fan2[i - 1] * 233 + str[m - i + 1]) % p2;
        }
        for (register int i = 1; i < n; i++) {
            int s = get(), t = get();
            char c = cget();
            add(s, t, c);
            add(t, s, c);
        }
        dfs(r, 0);
        for (register int i = 1; i <= 16; i++) {
            for (register int j = 1; j <= n; j++) {
                ance[j][i] = ance[ance[j][i - 1]][i - 1];
                hsh1[j][i] = (hsh1[j][i - 1] * dk1[1 << (i - 1)] + hsh1[ance[j][i - 1]][i - 1]) % p1;
                hsh2[j][i] = (hsh2[j][i - 1] * dk2[1 << (i - 1)] + hsh2[ance[j][i - 1]][i - 1]) % p2;
            }
        }
        int ptr = 1;
        for (register int i = 1; i <= q; i++) {
            int op = get(), x = get();
            if (op == 3) {
                int len = sget();
                int l = ptr;
                for (register int j = 1; j <= len; j++) {
                    h1[j] = (h1[j - 1] + str[j] * dk1[j]) % p1;
                    h2[j] = (h2[j - 1] + str[j] * dk2[j]) % p2;
                    ha1[ptr] = h1[j];
                    ha2[ptr] = h2[j];
                    ptr++;
                }
                node cjr;
                cjr.id = i;
                cjr.l = l;
                cjr.r = ptr - 1;
                vec[x].push_back(cjr);
            }
            if (op == 2) {
                int cur = x;
                ll d1 = 0, d2 = 0;
                for (register int i = lg[deep[x]]; ~i; i--) {
                    if (!ance[cur][i] || deep[x] - deep[ance[cur][i]] > m)
                        continue;
                    if ((d1 * dk1[1 << i] + hsh1[cur][i]) % p1 != fan1[deep[x] - deep[ance[cur][i]]])
                        continue;
                    if ((d2 * dk2[1 << i] + hsh2[cur][i]) % p2 != fan2[deep[x] - deep[ance[cur][i]]])
                        continue;
                    d1 = (d1 * dk1[1 << i] + hsh1[cur][i]) % p1;
                    d2 = (d2 * dk2[1 << i] + hsh2[cur][i]) % p2;
                    cur = ance[cur][i];
                }
                anss[i] = deep[x] - deep[cur];
            }
            if (op == 1) {
                int cur = x;
                ll d1 = 0, d2 = 0;
                for (register int i = lg[deep[x]]; ~i; i--) {
                    if (!ance[cur][i] || deep[x] - deep[ance[cur][i]] > m)
                        continue;
                    if ((d1 * dk1[1 << i] + hsh1[cur][i]) % p1 != zheng1[deep[x] - deep[ance[cur][i]]])
                        continue;
                    if ((d2 * dk2[1 << i] + hsh2[cur][i]) % p2 != zheng2[deep[x] - deep[ance[cur][i]]])
                        continue;
                    d1 = (d1 * dk1[1 << i] + hsh1[cur][i]) % p1;
                    d2 = (d2 * dk2[1 << i] + hsh2[cur][i]) % p2;
                    cur = ance[cur][i];
                }
                anss[i] = deep[x] - deep[cur];
            }
        }
        efs(r, 0);
        for (register int i = 1; i <= q; i++) print(anss[i]), putchar('\n');
    }
}
}  // namespace ywy
signed main() {
    ywy::ywymain();
    return (0);
}