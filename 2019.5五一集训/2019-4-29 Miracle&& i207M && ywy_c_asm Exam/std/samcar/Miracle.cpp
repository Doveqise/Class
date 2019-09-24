#include<bits/stdc++.h>
#define reg register int
#define il inline
#define fi first
#define se second
#define mk(a,b) make_pair(a,b)
#define numb (ch^'0')
#define ui unsigned long long
#define pii pair<int,int>
using namespace std;
typedef long long ll;
template<class T>il void rd(T &x){
    char ch;x=0;bool fl=false;
    while(!isdigit(ch=getchar()))(ch=='-')&&(fl=true);
    for(x=numb;isdigit(ch=getchar());x=x*10+numb);
    (fl==true)&&(x=-x);
}
template<class T>il void output(T x){if(x/10)output(x/10);putchar(x%10+'0');}
template<class T>il void ot(T x){if(x<0) putchar('-'),x=-x;output(x);putchar(' ');}
template<class T>il void prt(T a[],int st,int nd){for(reg i=st;i<=nd;++i) ot(a[i]);putchar('\n');}

namespace Miracle{
const int N=1e5+5;
const int base=131;
int n,m,rt;
ui mi[N];
struct node{
    int nxt,to;
    int val;
}e[2*N];
int hd[N],cnt;
void add(int x,int y,int z){
    e[++cnt].nxt=hd[x];
    e[cnt].val=z;
    e[cnt].to=y;
    hd[x]=cnt;
}
map<ui,int>buc;
ui h1[N],h2[N];
int L;
ui h[N][18];
int fa[N][18];
ui dis[N];
char s[N],r[N];
int qs[N];//warning!!! qs is int!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int ptr;
struct question{
    int l,r;
    int id;
}q[N];
int tot;

int ans[N];
void dfs(int x){
    for(reg i=hd[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa[x][0]) continue;
        fa[y][0]=x;
        h[y][0]=e[i].val;
        dis[y]=(dis[x]*base+e[i].val);
        dfs(y);
    }
}
vector<int>mem[N];
void sol(int x){
    ++buc[dis[x]];
    ui tmp;
    for(reg i=0;i<(int)mem[x].size();++i){
        tmp=dis[x];
        int oi=0;
        int lp=mem[x][i];
        for(reg j=q[lp].l;j<=q[lp].r;++j){
            tmp=tmp*base+qs[j];
            oi+=buc[tmp];
        }
        ans[q[lp].id]-=oi;
    }
    for(reg i=hd[x];i;i=e[i].nxt){
        int y=e[i].to;
        if(y==fa[x][0]) continue;
        sol(y);
    }
    for(reg i=0;i<(int)mem[x].size();++i){
        tmp=dis[x];
        int oi=0;
        int lp=mem[x][i];
        for(reg j=q[lp].l;j<=q[lp].r;++j){
            tmp=tmp*base+qs[j];
            oi+=buc[tmp];
        }
        ans[q[lp].id]+=oi;
    }
}
void clear(){
    m=0;rt=0;
    for(reg i=1;i<=n;++i) mem[i].clear();
    n=0;
    cnt=0;
    memset(hd,0,sizeof hd);
    buc.clear();
    memset(fa,0,sizeof fa);
    memset(dis,0,sizeof dis);
    memset(ans,0,sizeof ans);
    tot=0;ptr=0;
}
int main(){
    int haha;
    rd(haha);haha=233;
    int t;rd(t);
    mi[0]=1;
    for(reg i=1;i<=N-3;++i){
        mi[i]=mi[i-1]*base;
    }
    while(t--){
        clear();
        rd(n);rd(m);rd(rt);

        scanf("%s",s+1);
        int len=strlen(s+1);
        L=len;
        ui tmp=0;
        for(reg i=1;i<=len;++i){
            h1[i]=h1[i-1]+mi[i-1]*(s[i]-'a'+1);
            r[i]=s[i];
        }
        reverse(r+1,r+len+1);
        for(reg i=1;i<=len;++i){
            h2[i]=h2[i-1]+mi[i-1]*(r[i]-'a'+1);
        }
        int x,y;char c[233];
        for(reg i=1;i<n;++i){
            rd(x);rd(y);scanf("%s",c);
            add(x,y,c[0]-'a'+1);
            add(y,x,c[0]-'a'+1);
        }
        dfs(rt);
        for(reg j=1;j<=17;++j){
            for(reg i=1;i<=n;++i){
                fa[i][j]=fa[fa[i][j-1]][j-1];
                h[i][j]=(h[i][j-1]+h[fa[i][j-1]][j-1]*mi[1<<(j-1)]);
            }
        }

        int op;
        for(reg i=1;i<=m;++i){
            rd(op);
            ans[i]=0;
            if(op==1){
                rd(x);
                ui hsh=0;
                int lth=0;
                for(reg j=17;j>=0;--j){
                    if(fa[x][j]){
                        ui now=hsh+(h[x][j]*mi[lth]);
                        if(lth+(1<<j)<=L&&h1[lth+(1<<j)]==now){
                            x=fa[x][j];lth+=(1<<j);
                            hsh=now;
                        }
                    }
                }
                ans[i]=lth;
            }else if(op==2){
                rd(x);
                ui hsh=0;
                int lth=0;
                for(reg j=17;j>=0;--j){
                    if(fa[x][j]){
                        ui now=hsh+(h[x][j]*mi[lth]);
                        if(lth+(1<<j)<=L&&h2[lth+(1<<j)]==now){
                            x=fa[x][j];lth+=(1<<j);
                            hsh=now;
                        }
                    }
                }
                ans[i]=lth;
            }else{
                ++tot;
                rd(x);
                scanf("%s",s+1);
                len=strlen(s+1);
                q[tot].l=ptr+1;
                for(reg j=1;j<=len;++j){
                    qs[++ptr]=s[j]-'a'+1;
                }
                q[tot].r=ptr;
                q[tot].id=i;
                mem[x].push_back(tot);
            }
        }
        sol(rt);
        for(reg i=1;i<=m;++i){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

}
signed main(){
    Miracle::main();
    return 0;
}

/*
   Author: *Miracle*
   Date: 2019/4/13 19:58:12
*/

