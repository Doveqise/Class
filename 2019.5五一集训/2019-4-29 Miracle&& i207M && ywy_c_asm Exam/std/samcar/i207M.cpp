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
int n,root;
vector<pair<int,char> >E[N];
ull h1[N][17],dh[N],pw[N];
const uint bas=233;
int fa[N][17],dep[N];
void dfs(int x,int _fa)
{
    fa[x][0]=_fa,dep[x]=dep[_fa]+1;
    for(ri i=1; i<=16&&fa[x][i-1]; ++i)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
        h1[x][i]=h1[x][i-1]*pw[1<<(i-1)]+h1[fa[x][i-1]][i-1];
    }
    for(solid it:E[x])
    {
        const int v=it.fi; const char c=it.se;
        if(v==_fa) continue;
        h1[v][0]=c,dh[v]=dh[x]*bas+c;
        dfs(v,x);
    }
}
int ans[N];
vector<pair<ull,int> >qu[N];
void ask3(int x,const char s[],int id)
{
    ull H=dh[x]; int len=strlen(s+1);
    for(ri i=1; i<=len; ++i)
    {
        H=H*bas+s[i];
        qu[x].pb(mp(H,id));
    }
}
unordered_map<ull,int>rem;
void efs(int x,int _fa)
{
    for(solid it:qu[x])
        ans[it.se]-=rem[it.fi];
    ++rem[dh[x]];
    for(solid it:E[x])
    {
        const int v=it.fi;
        if(v==_fa) continue;
        efs(v,x);
    }
    for(solid it:qu[x])
        ans[it.se]+=rem[it.fi];
    qu[x].clear(),E[x].clear();
}
char s[N]; int len;
ull ph[N],sh[N];
void prework()
{
    for(ri i=1; i<=n; ++i) ph[i]=ph[i-1]*bas+s[i];
    for(ri i=n; i>=1; --i) sh[i]=sh[i+1]*bas+s[i];
}
int ask1(int x)
{
    ull h=0; int l=0;
    for(ri i=16; i>=0; --i)
    {
        if(!fa[x][i]||l+(1<<i)>len) continue;
        ull nh=h*pw[1<<i]+h1[x][i];
        if(nh==ph[l+(1<<i)]) h=nh,l+=1<<i,x=fa[x][i];
    }
    return l;
}
int ask2(int x)
{
    ull h=0; int l=0;
    for(ri i=16; i>=0; --i)
    {
        if(!fa[x][i]||l+(1<<i)>len) continue;
        ull nh=h*pw[1<<i]+h1[x][i];
        if(nh==sh[len-(l+(1<<i))+1]) h=nh,l+=1<<i,x=fa[x][i];
    }
    return l;
}
void clear()
{
    mem(ans,0);
    mem(h1,0),mem(dh,0);
    mem(ph,0),mem(sh,0);
    mem(fa,0),mem(dep,0);
    rem.clear();
}
signed main()
{
#ifdef M207
    freopen("in.in","r",stdin);
    // freopen("ot.out","w",stdout);
#endif
    int T; in(T,T);
    pw[0]=1;
    for(ri i=1; i<N; ++i) pw[i]=pw[i-1]*bas;
    while(T--)
    {
        clear();
        int cq,x,op; static char tc[N];
        in(n,cq,root);
        scanf("%s",s+1); len=strlen(s+1);
        prework();
        for(ri i=1,a,b; i<n; ++i)
        {
            in(a,b); scanf("%s",tc);
            E[a].pb(mp(b,tc[0])),E[b].pb(mp(a,tc[0]));
        }
        dfs(root,0);
        for(ri i=1; i<=cq; ++i)
        {
            in(op,x);
            if(op==1) ans[i]=ask1(x);
            else if(op==2) ans[i]=ask2(x);
            else
            {
                scanf("%s",tc+1);
                ask3(x,tc,i);
            }
        }
        efs(root,0);
        for(ri i=1; i<=cq; ++i) out(ans[i]);
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
