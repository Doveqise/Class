#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
const int maxm = 2e3+5;
ll cc[maxm][maxm];
ll qpow(ll a,ll b)
{
	if(b==-1)
		return 1;
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
ll C(int x,int y)
{
	if(x<=0||y<=0)
		return 0;
	if(x<y)
		swap(x,y);
	if(cc[x][y])
		return cc[x][y];
	cc[x][1]=x;
	for(int i=1;i<=y;i++)
	{
		if(cc[x][i])
			continue;
		cc[x][i]=(cc[x][i-1]*(x-i+1)/i)%mod;
	}
	return cc[x][y];
}
ll solve(ll n,ll m,ll k)
{
	ll ans=0;
	ll yu=n-k;
	ll limm=min(yu,k);
	for(ll i=1;i<=limm;i++)
	{
//		printf("%lld %lld\n",c1,qpow(2,yu-i-1));
		ans=(ans+(C(k,i)*qpow(2,yu-i-1))%mod)%mod;
	}
	printf("%lld\n",ans);
	return ans;
}
signed main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ll ans=0,n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	ans=solve(n,m,k);
//	printf("%lld\n",ans); 
	ll lim=n/m;
	for(ll p=1;p<=lim;p++)
	{
		ll ap=p*m,yu=n-ap;
		ans=(ans-((yu>k-1)?(solve(n-ap,m,k-1)*k):((yu==k-1)?k:0)))%mod;
	}
	printf("%lld",ans);
	return 0;
}
