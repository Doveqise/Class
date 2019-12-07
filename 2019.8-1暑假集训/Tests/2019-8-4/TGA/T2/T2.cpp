#include<bits/stdc++.h>
#define ll unsigned long long 
using namespace std;
ll qpow(ll a,ll b,ll k)
{
	ll base = a,ans = 1;
	while(b)
	{
		if(b & 1)
			ans = ans * base % k;
		base = base * base % k;
		b >>= 1;
	}
	return ans;
}
signed main()
{
	freopen("division.in","r",stdin);
	freopen("division.out","w",stdout);
	int id,T;
	scanf("%d%d",&id,&T);
	while(T--)
	{
		ll c,m,n=1;
		scanf("%llu%llu",&c,&m);
		for(ll i=1,t;i<=c;i++)
		{
			scanf("%llu",&t);
			n*=t;
		}
		if(m==1)
		{
			printf("%llu\n",n);
			continue;
		}
		else if(c==1)
		{
			printf("%llu\n",2);
			continue;
		}
		ll cnt=0;
		for(ll i=1;i<=n;i++)
		{
			//printf("%d^%d-%d %% %d=%d\n",i,m,i,n,((int)pow(i,m)-i)%n);
			if(qpow(i,m,n)==i%n)
			{
				cnt++;
				cnt%=998244353;
			}
			//printf("Num:%llu %llu\n",++cnt,i);
			//printf("%d\n",qpow(i,m,n));
		}
		printf("%llu\n",cnt);
	}
}
