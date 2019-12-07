#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e2+5;
const int maxm = 3e4+5;
int hd[maxn<<1],nxt[maxm<<1],to[maxm<<1],jz[maxn<<1][maxn<<1],cx[maxn<<1],cy[maxn<<1],vis[maxn<<1];
int cnt,n,m;
void add(int x,int y)
{
	hd[x]=++cnt;
	nxt[cnt]=x;
	to[cnt]=y;
	hd[y]=++cnt;
	nxt[cnt]=y;
	to[cnt]=x;
}
void cdbb()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=k&&j!=k)
					jz[i][j]|=jz[i][k]&jz[k][j];
}
void build()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(jz[i][j])
				add(i,j+n);
}
bool find(int u)
{
	for(int v=1;v<=n;v++)
	{
		if(jz[u][v]&&!vis[v])
		{
			vis[v]=1;
			if(cy[v]==-1||find(cy[v]))
			{
				cx[u]=v;
				cy[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int solve()
{
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));
	int ret=0;
	for(int i=1;i<=n;i++)
	{
		if(cx[i]==-1)
		{
			memset(vis,0,sizeof(vis));
			ret+=find(i);
		}
	} 
	return ret;
}
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		jz[u][v]=1;
	}
	cdbb();
	build();
	printf("%d\n",n-solve());
	return 0;
}
