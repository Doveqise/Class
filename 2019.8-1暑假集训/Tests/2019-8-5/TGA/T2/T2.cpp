#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+5;
const int tims = 2017;
int mp[maxn][maxn],wtg[maxn][maxn],now=tims+1;
signed main()
{
	//freopen("jump.in","r",stdin);
	//freopen("jump.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	for(int a=1;a<=n;a++)
	{
		for(int b=1;b<=m;b++)
		{
			if(a==1)
			{
				if(b==1)
				{
					wtg[n][m]=mp[1][1]>mp[n-1][1]?(mp[1][1]>mp[n][1]?1*tims+1:n*tims+1):(mp[n-1][1]>mp[n][1]?(n-1)*tims+1:n*tims+1);
					wtg[1][m]=mp[n][1]>mp[1][1]?(mp[n][1]>mp[2][1]?n*tims+1:2*tims+1):(mp[1][1]>mp[2][1]?1*tims+1:2*tims+1);
					wtg[2][m]=mp[1][1]>mp[2][1]?(mp[1][1]>mp[3][1]?1*tims+1:3*tims+1):(mp[2][1]>mp[3][1]?2*tims+1:3*tims+1);
				}
				else if(b==m)
				{
					wtg[1][m-1]=mp[1][m]>mp[2][m]?(mp[1][m]>mp[n][m]?1*tims+m:n*tims+m):(mp[2][m]>mp[n][m]?2*tims+m:n*tims+m);
					wtg[2][m-1]=mp[1][m]>mp[2][m]?(mp[1][m]>mp[3][m]?1*tims+m:3*tims+m):(mp[2][m]>mp[3][m]?2*tims+m:3*tims+m);
					wtg[n][m-1]=mp[n][m]>mp[1][m]?(mp[n][m]>mp[n-1][m]?n*tims+m:(n-1)*tims+m):(mp[1][m]>mp[n-1][m]?1*tims+m:(n-1)*tims+m);
				}
				else
				{
					wtg[a][b-1]=mp[a][b]>mp[a+1][b]?(mp[a][b]>mp[n][b]?a*tims+b:n*tims+b):(mp[a+1][b]>mp[n][b]?(a+1)*tims+b:n*tims+b);
					wtg[a+1][b-1]=mp[a+1][b]>mp[a][b]?(mp[a+1][b]>mp[n][b]?(a+1)*tims+b:n*tims+b):(mp[a][b]>mp[n][b]?a*tims+b:n*tims+b);
					wtg[n][b-1]=mp[n][b]>mp[a][b]?(mp[n][b]>mp[a+1][b]?n*tims+b:(a+1)*tims+b):(mp[a][b]>mp[a+1][b]?a*tims+b:(a+1)*tims+b);
				}
			}
			else if(a==n)
			{
				if(b==1)
				{
					wtg[n][m]=mp[1][1]>mp[n][1]?(mp[1][1]>mp[n-1][1]?1*tims+1:(n-1)*tims+1):(mp[n][1]>mp[n-1][1]?n*tims+1:(n-1)*tims+1);
					wtg[n-1][m]=mp[n-1][1]>mp[n][1]?(mp[n-1][1]>mp[n-2][1]?(n-1)*tims+1:(n-2)*tims+1):(mp[n][1]>mp[n-2][1]?n*tims+1:(n-2)*tims+1);
					wtg[1][m]=mp[1][1]>mp[2][1]?(mp[1][1]>mp[n][1]?1*tims+1:n*tims+1):(mp[2][1]>mp[n][1]?2*tims+1:n*tims+1);
				}
				else
				{
					wtg[n][b-1]=mp[n][b]>mp[1][b]?(mp[n][b]>mp[n-1][b]?n*tims+b:(n-1)*tims+b):(mp[1][b]>mp[n-1][b]?1*tims+b:(n-1)*tims+b);
					wtg[n-1][b-1]=mp[n-1][b]>mp[n][b]?(mp[n-1][b]>mp[n-2][b]?(n-1)*tims+b:(n-2)*tims+b):(mp[n][b]>mp[n-2][b]?n*tims+b:(n-2)*tims+b);
					wtg[1][b-1]=mp[1][b]>mp[n][b]?(mp[1][b]>mp[2][b]?1*tims+b:2*tims+b):(mp[n][b]>mp[2][b]?n*tims+b:2*tims+b);
				}
				
			}
			else if(b==1)
			{
					wtg[a][m]=mp[a][1]>mp[a+1][1]?(mp[a][m]>mp[a-1][m]?a*tims+m:(a-1)*tims+m):(mp[a+1][m]>mp[a-1][m]?(a+1)*tims+m:(a-1)*tims+m);
					wtg[a-1][m]=mp[a-1][1]>mp[a][1]?(mp[a-1][1]>mp[a-2][1]?(a-1)*tims+1:(a-2)*tims+1):(mp[a][1]>mp[a-2][1]?a*tims+1:(a-2)*tims+1);
					wtg[a+1][m]=mp[a+1][1]>mp[a][1]?(mp[a+1][1]>mp[a+2][1]?(a+1)*tims+1:(a+2)*tims+1):(mp[a][1]>mp[a+2][1]?a*tims+1:(a+2)*tims+1);
			}
			else
			{
				wtg[a][b-1]=mp[a][b]>mp[a+1][b]?(mp[a][b]>mp[a-1][b]?a*tims+b:(a-1)*tims+b):(mp[a+1][b]>mp[a-1][b]?(a+1)*tims+b:(a-1)*tims+b);
				wtg[a-1][b-1]=mp[a-1][b]>mp[a][b]?(mp[a-1][b]>mp[a-2][b]?(a-1)*tims+b:(a-2)*tims+b):(mp[a][b]>mp[a-2][b]?a*tims+b:(a-2)*tims+b);
				wtg[a+1][b-1]=mp[a+1][b]>mp[a][b]?(mp[a+1][b]>mp[a+2][b]?(a+1)*tims+b:(a+2)*tims+b):(mp[a][b]>mp[a+2][b]?a*tims+b:(a+2)*tims+b);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			printf("%d %d  ",wtg[i][j]/tims,wtg[i][j]%tims);
		printf("\n");
	}
	int Q;
	scanf("%d",&Q);
	string opt;
	for(int ti=1;ti<=Q;ti++)
	{
		cin>>opt;
		if(opt=="move")
		{
			int k;
			scanf("%d",&k);
				for(int i=1;i<=k;i++)
					now=wtg[now/tims][now%tims];
				printf("%d %d\n",now/tims,now%tims);
		}
		else
		{
			int a,b,e;
			scanf("%d%d%d",&a,&b,&e);
			mp[a][b]=e;
			if(a==1)
			{
				if(b==1)
				{
					wtg[n][m]=mp[1][1]>mp[1][m]?(mp[1][1]>mp[1][m-1]?1*tims+1:1*tims+m-1):(mp[1][m]>mp[1][m-1]?1*tims+m:1*tims+m-1);
					wtg[1][m]=mp[n][1]>mp[1][1]?(mp[n][1]>mp[2][1]?n*tims+1:2*tims+1):(mp[1][1]>mp[2][1]?1*tims+1:2*tims+1);
					wtg[2][m]=mp[1][1]>mp[2][1]?(mp[1][1]>mp[3][1]?1*tims+1:3*tims+1):(mp[2][1]>mp[3][1]?2*tims+1:3*tims+1);
				}
				else if(b==m)
				{
					wtg[1][m-1]=mp[1][m]>mp[2][m]?(mp[1][m]>mp[n][m]?1*tims+m:n*tims+m):(mp[2][m]>mp[n][m]?2*tims+m:n*tims+m);
					wtg[2][m-1]=mp[1][m]>mp[2][m]?(mp[1][m]>mp[3][m]?1*tims+m:3*tims+m):(mp[2][m]>mp[3][m]?2*tims+m:3*tims+m);
					wtg[n][m-1]=mp[n][m]>mp[1][m]?(mp[n][m]>mp[n-1][m]?n*tims+m:(n-1)*tims+m):(mp[1][m]>mp[n-1][m]?1*tims+m:(n-1)*tims+m);
				}
				else
				{
					wtg[a][b-1]=mp[a][b]>mp[a+1][b]?(mp[a][b]>mp[n][b]?a*tims+b:n*tims+b):(mp[a+1][b]>mp[n][b]?(a+1)*tims+b:n*tims+b);
					wtg[a+1][b-1]=mp[a+1][b]>mp[a][b]?(mp[a+1][b]>mp[n][b]?(a+1)*tims+b:n*tims+b):(mp[a][b]>mp[n][b]?a*tims+b:n*tims+b);
					wtg[n][b-1]=mp[n][b]>mp[a][b]?(mp[n][b]>mp[a+1][b]?n*tims+b:(a+1)*tims+b):(mp[a][b]>mp[a+1][b]?a*tims+b:(a+1)*tims+b);
				}
			}
			else if(b==1)
			{
				if(a==n)
				{
					wtg[n][m]=mp[1][1]>mp[n][1]?(mp[1][1]>mp[n-1][1]?1*tims+1:(n-1)*tims+1):(mp[n][1]>mp[n-1][1]?n*tims+1:(n-1)*tims+1);
					wtg[n-1][m]=mp[n-1][1]>mp[n][1]?(mp[n-1][1]>mp[n-2][1]?(n-1)*tims+1:(n-2)*tims+1):(mp[n][1]>mp[n-2][1]?n*tims+1:(n-2)*tims+1);
					wtg[1][m]=mp[1][1]>mp[2][1]?(mp[1][1]>mp[n][1]?1*tims+1:n*tims+1):(mp[2][1]>mp[n][1]?2*tims+1:n*tims+1);
				}
				else
				{
					wtg[a][m]=mp[a][1]>mp[a+1][1]?(mp[a][m]>mp[a-1][m]?a*tims+m:(a-1)*tims+m):(mp[a+1][m]>mp[a-1][m]?(a+1)*tims+m:(a-1)*tims+m);
					wtg[a-1][m]=mp[a-1][1]>mp[a][1]?(mp[a-1][1]>mp[a-2][1]?(a-1)*tims+1:(a-2)*tims+1):(mp[a][1]>mp[a-2][1]?a*tims+1:(a-2)*tims+1);
					wtg[a+1][m]=mp[a+1][1]>mp[a][1]?(mp[a+1][1]>mp[a+2][1]?(a+1)*tims+1:(a+2)*tims+1):(mp[a][1]>mp[a+2][1]?a*tims+1:(a+2)*tims+1);
				}
			}
			else
			{
				wtg[a][b-1]=mp[a][b]>mp[a+1][b]?(mp[a][b]>mp[a-1][b]?a*tims+b:(a-1)*tims+b):(mp[a+1][b]>mp[a-1][b]?(a+1)*tims+b:(a-1)*tims+b);
				wtg[a-1][b-1]=mp[a-1][b]>mp[a][b]?(mp[a-1][b]>mp[a-2][b]?(a-1)*tims+b:(a-2)*tims+b):(mp[a][b]>mp[a-2][b]?a*tims+b:(a-2)*tims+b);
				wtg[a+1][b-1]=mp[a+1][b]>mp[a][b]?(mp[a+1][b]>mp[a+2][b]?(a+1)*tims+b:(a+2)*tims+b):(mp[a][b]>mp[a+2][b]?a*tims+b:(a+2)*tims+b);
			}
		}
	}
}
