#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+5;
int dp[maxn][maxn],val[maxn],gdd,cnt=0;
signed main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
	{
		if(i!=val[i])
			break;
		if(i==n)
		{
			printf("%d\n",n);
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int l=min(i,val[i]),r=max(i,val[i]);
		if(l==r)
		{
			gdd++;
			for(int l=1,ll=l,rr=i;l<i;l++)
			{
				ll=l,rr=i;
				while(ll>=1&&rr<=n)
				{
					dp[ll][rr]--;
					ll--;
					rr++;
				}
			}
			for(int r=i+1,ll=i,rr=r;r<=n;r++)
			{
				ll=i,rr=r;
				while(ll>=1&&rr<=n)
				{
					dp[ll][rr]--;
					ll--;
					rr++;
				}
			}
		}
		else while(l>=1&&r<=n)
		{
			dp[l][r]++;
			l--,r++;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=max(ans,dp[i][j]);
	printf("%d\n",ans+gdd);
	return 0;
}

