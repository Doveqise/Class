#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int mp[6][maxn],dp[6][maxn];
int n,m,q;
void solve(int xs,int ys,int xf,int yf)
{
	memset(dp,0x3f,sizeof(dp));
	dp[xs][ys]=0;
	for(int j=ys;j<=yf;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(!mp[i][j])
				continue;
			if(mp[i][j-1])
				dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
			if(mp[i-1][j])
				dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
			if(mp[i+1][j])
				dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
		}
		for(int i=n;i>=1;i--)
		{
			if(!mp[i][j])
				continue;
			if(mp[i][j-1])
				dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
			if(mp[i-1][j])
				dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
			if(mp[i+1][j])
				dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
		}
	}
	printf("%d\n",dp[xf][yf]==0x3f3f3f3f?-1:dp[xf][yf]);
	return;
}
signed main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	for(int ti=1,opt;ti<=q;ti++)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			mp[x][y]=mp[x][y]?0:1;
		}
		else
		{
			int xs,ys,xf,yf;
			scanf("%d%d%d%d",&xs,&ys,&xf,&yf);
			solve(xs,ys,xf,yf);
		}
	}
}
/*
2 3 5
1 1 1
1 1 1
2 2 1 1 2
2 2 2 1 2
1 1 2
2 1 1 2 2
2 2 1 1 2
*/
