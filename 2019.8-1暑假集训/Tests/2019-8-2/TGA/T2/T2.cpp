#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
const double eps = 1e-7;
double dp[maxn][25][10];
int n,r,q,s;
bool solve(double p)
{
	memset(dp,0,sizeof(dp));
	double sc=0;
	//dp[1][0][q]=1;
	for(int i=0;i<n;i++)
	{
		int limj=min(i,r);
		for(int j=0;j<=limj;j++)
		{
			for(int k=1;k<=q;k++)
				if((!i)||dp[i][j][k]&&(i+j>=k)&&(i>=j))
					dp[i+1][min(j+1,r)][min(k+1,q)]+=(dp[i][j][k]+min(j+1,r))*p;
			for(int k=q;k>=1;k--)
				
				dp[i+1][0][k-1]+=dp[i][j][k]*(1-p);
				//dp[i][0][k]+=dp[i-1][j][k+1]*(1-p);
				//dp[i][j][k]+=(dp[i-1][j-1][k-1]+j)*p;
		}
	}
//	for(int i=0;i<n;i++)
//		sc+=dp[i][0][0];
	for(int j=0;j<=r;j++)
		for(int k=0;k<=q;k++)
		sc+=dp[n][j][k];
//	for(int i=0;i<=n;i++)
//		for(int j=0;j<=r;j++)
//			for(int k=0;k<=q;k++)
//				printf("dp[%d][%d][%d]=%0.6lf\n",i,j,k,dp[i][j][k]);
//		printf("%0.6lf %0.6lf\n",p,sc);
//		exit(0);
	if(sc>=(double)s)
		return 1;
	return 0;
}
double bound()
{
	double l=0,r=1,mid;
	if(!solve(r))
	{
		puts("Impossible.");
		exit(0);
	}
	while(r-l>=eps)
	{
		mid=(l+r)/2;
		if(solve(mid))
			r=mid;
		else
			l=mid;
	}
	return l;
}
signed main()
{
	scanf("%d%d%d%d",&n,&r,&q,&s);
	printf("%0.6lf",bound());
	return 0;
}
