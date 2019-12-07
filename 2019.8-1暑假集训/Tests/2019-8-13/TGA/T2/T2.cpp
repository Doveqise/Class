#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int mod = 998244353;
const int maxn = 5e2+5;
ll mat[maxn][maxn],out[maxn];
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
bool jianyan(ll n,ll x)
{
	for(ll i=1;i<=n;i++)
	{
		ll ans=1;
		for(ll j=1;j<=n;j++)
			ans*=mat[i][j];
		if(ans!=x)
			return 0;
	}
	for(ll j=1;j<=n;j++)
	{
		ll ans=1;
		for(ll i=1;i<=n;i++)
			ans*=mat[i][j];
		if(ans!=x)
			return 0;
	}
	return 1;
}
signed main()
{
	freopen("pj.in","r",stdin);
	freopen("pj.out","w",stdout);
	int x,T;
	scanf("%d%d",&x,&T);
	while(T--)
	{
		ll n;
		scanf("%llu",&n);
		ll q=(n-1)*(n-1);
		//printf("%llu\n",q);
		printf("%llu\n",qpow(2,q));
	}
	return 0;
}
