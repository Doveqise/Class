#include<bits/stdc++.h>
using namespace std;
const int maxn = 15;
int h,n,m;
int a[maxn][maxn][maxn],bz[maxn][maxn][maxn],vis[maxn][maxn][maxn],ans[maxn][maxn],K[maxn];
void dfs(int nowh,int nowx,int nowy,int cost,int hbz)
{
	vis[nowh][nowx][nowy]=1;
	if(hbz==K[nowh])
	{
		if(nowh==h)
		{
			if(ans[nowx][nowy])
				ans[nowx][nowy]=min(ans[nowx][nowy],cost);
			else
			 	ans[nowx][nowy]=cost;
			return;
		}
		dfs(nowh+1,nowx,nowy,cost+vis[nowh+1][nowx][nowy]?0:a[nowh+1][nowx][nowy],0);
		return;
	}
	if(nowx+1<=n)
	{
		if(nowy+1<=m)
			dfs(nowh,nowx+1,nowy+1,cost+vis[nowh][nowx+1][nowy+1]?0:a[nowh][nowx+1][nowy+1],hbz+vis[nowh][nowx][nowy]?0:bz[nowh][nowx][nowy]);
		if(nowy>=1)
			dfs(nowh,nowx+1,nowy-1,cost+vis[nowh][nowx+1][nowy-1]?0:a[nowh][nowx+1][nowy-1],hbz+vis[nowh][nowx][nowy]?0:bz[nowh][nowx][nowy]);
		dfs(nowh,nowx+1,nowy,cost+vis[nowh][nowx+1][nowy]?0:a[nowh][nowx+1][nowy],hbz+vis[nowh][nowx][nowy]?0:bz[nowh][nowx][nowy]);
	}
	if(nowx>=1)
	{
		if(nowy+1<=m)
			dfs(nowh,nowx-1,nowy+1,cost+vis[nowh][nowx-1][nowy+1]?0:a[nowh][nowx-1][nowy+1],hbz+vis[nowh][nowx][nowy]?0:bz[nowh][nowx][nowy]);
		if(nowy>=1)
			dfs(nowh,nowx-1,nowy-1,cost+vis[nowh][nowx-1][nowy+1]?0:a[nowh][nowx-1][nowy+1],hbz+vis[nowh][nowx][nowy]?0:bz[nowh][nowx][nowy]);
		dfs(nowh,nowx-1,nowy,cost+vis[nowh][nowx+1][nowy]?0:a[nowh][nowx+1][nowy],hbz+vis[nowh][nowx][nowy]?0:bz[nowh][nowx][nowy]);
	}
	if(nowy+1<=m)
		dfs(nowh,nowx,nowy+1,cost+vis[nowh][nowx][nowy+1]?0:a[nowh][nowx][nowy+1],hbz+vis[nowh][nowx][nowy]?0:bz[nowh][nowx][nowy]);
	if(nowy>=1)
		dfs(nowh,nowx,nowy-1,cost+vis[nowh][nowx][nowy-1]?0:a[nowh][nowx][nowy-1],hbz+hbz+vis[nowh][nowx][nowy]?0:bz[nowh][nowx][nowy]);
}
signed main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d%d",&h,&n,&m);
	for(int i=1;i<=h;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				scanf("%d",&a[i][j][k]);
	for(int i=1;i<=h;i++)
	{
//		puts("WTF");
		scanf("%d",&K[i]);
		for(int j=1,x,y;j<=K[i];j++)
		{
			scanf("%d%d",&x,&y);
			bz[i][x][y]=1;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dfs(1,i,j,a[1][i][j],bz[1][i][j]);
	int out=10000000;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			out=min(out,ans[i][j]?ans[i][j]:out);
	printf("%d\n",out);
	return 0;
}
