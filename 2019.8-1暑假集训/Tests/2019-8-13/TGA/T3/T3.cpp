#include<bits/stdc++.h>
using namespace std;
const int maxn = 20;
int num[maxn],array[maxn],dp[maxn];
#define ll long long
const int mod = 1e9+7;
ll qpow(ll a,ll b)
{
	ll base=a,ret=1;
	while(b)
	{
		if(b&1)
			ret=(ret*base)%mod;
		base=(base*base)%mod;
		b>>=1;
	}
	return ret;
}
ll solve(int n,int x,int y)
{
	ll lim=qpow(n,n);
	ll ans=0;
	for(int ti=1;ti<=lim;ti++)
	{
		memset(num,0,sizeof(num));
		memset(dp,0,sizeof(dp));
		memset(array,0,sizeof(array));
		for(int i=1;i<=n;i++)
			num[array[i]=ti/qpow(n,i-1)%n]++;
		int flg=1;
		for(int i=1;i<=n;i++)
			if(num[i]!=1)
			{
				flg=0;
				break;
			}
		if(!flg)
			continue;
		for(int i=1;i<=n;i++)
		{
			dp[i]=1;
			for(int j=1;j<i;j++)
				if(array[j]>array[i])
					dp[i]=max(dp[i],dp[j]+1);
		}
		flg=1;
		for(int i=1;i<=n;i++)
			if(dp[i]>2)
				flg=0;
		ans+=array[x]==y&&flg;
	}
	return ans;
}
signed main()
{
	freopen("tg.in","r",stdin);
	freopen("tg.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		printf("%lld\n",solve(n,x,y));
	}
}
