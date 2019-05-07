// luogu-judger-enable-o2
#pragma region
#include <bits/stdc++.h>
using namespace std;
#define ri register int
#define il inline
#define LL long long
#define uint unsigned int
#define ull unsigned long long
#define solid const auto &
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>
#define fi first
#define se second
#define gm int mid((l+r)/2)
#define space putchar(' ')
#define enter putchar('\n')
#define rd() ({ri t;in(t);t;})
#define Size(x) ((int)x.size())
#define mem(x,y) memset(x,y,sizeof(x))
template<class T>il void in(T &x)
{
    x=0; char c=getchar(); bool f=0;
    while(!isdigit(c)) f|=(c=='-'),c=getchar();
    while(isdigit(c)) x=x*10+(c^'0'),c=getchar();
    f?x=-x:0;
}
template<class T>il void out(T x,const char c='\n')
{
    static short st[30]; short m=0;
    if(x<0) putchar('-'),x=-x;
    do st[++m]=x%10,x/=10; while(x);
    while(m) putchar(st[m--]|'0');
    putchar(c);
}
template<class T,class ...Args>il void in(T &x,Args &...args) {in(x); in(args...);}
template<class T,class ...Args>il void out(const T &x,const Args &...args) {out(x,' '); out(args...);}
template<class T>il void prt(T a[],int n) {for(ri i=0; i<n; ++i) out(a[i],i==n-1?'\n':' ');}
template<class T>il void clr(T a[],int n) {memset(a,0,sizeof(T)*n);}
template<class T>il void clr(T *a,T *b) {memset(a,0,sizeof(T)*(b-a));}
template<class T>il bool ckmax(T &a,const T &b) {return a<b?a=b,1:0;}
template<class T>il bool ckmin(T &a,const T &b) {return a>b?a=b,1:0;}
namespace i207M
{
#pragma endregion
#define N 100005
int n;
pii pt[N];
int g[N];
signed main()
{
#ifdef M207
    freopen("in.in","r",stdin);
    // freopen("ot.out","w",stdout);
#endif
    int T; in(T);
    while(T--)
    {
        mem(g,0);
        in(n);
        for(ri i=1; i<=n; ++i) in(pt[i].fi);
        for(ri i=1; i<=n; ++i) in(pt[i].se),pt[i].se=-pt[i].se;
        sort(pt+1,pt+1+n);
        int ans=0;
        for(ri i=1; i<=n; ++i)
        {
            int t=upper_bound(g+1,g+1+n,pt[i].se)-g;
            ckmax(ans,t);
            ckmin(g[t],pt[i].se);
        }
        out(n-ans);
    }
    return 0;
}
#pragma region
}
signed main()
{
    i207M::main();
    return 0;
}
#pragma endregion
