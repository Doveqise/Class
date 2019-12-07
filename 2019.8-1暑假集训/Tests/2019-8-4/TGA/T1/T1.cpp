#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7+5;
const int mod = 998244353;
const double eps = 1e-1;
int b[maxn],c[maxn],f[maxn];
//double gl[maxn],dp[maxn];
signed main()
{
	freopen("forging.in","r",stdin);
	freopen("forging.out","w",stdout);
	int n,a,bx,by,cx,cy,p;
	scanf("%d%d%d%d%d%d%d",&n,&a,&bx,&by,&cx,&cy,&p);
	if(n==0)
	{
		printf("%d\n",a);
		return 0;
	}
	if(n==1)
	{
		by++,cy++;
		if(cy<=by)
		{
			printf("%d\n",a);
			return 0;
		}
		else
		{
			int num=2;
			long double now=0,lastans=0,suc=(long double)by/(long double)cy;
			now=num*a*suc;
			num++;
			while(fabs(lastans-now)>=eps)
			{	
				lastans=now;
				now+=num*a*suc*pow(1-suc,num-2);
				num++;
			}
			printf("%0.0Lf\n",now);
			return 0;
		}
	}
	if(p==1)
	{
		f[0]=a,f[1]=2*a;
		for(int i=2;i<=n;i++)
			f[i]=(f[i-1]+f[i-2])%mod;
		printf("%d\n",f[n]);
		return 0;
	}
//	else
//	{
//		f[0]=1,f[1]=2;
//		for(int i=2;i<=n;i++)
//			f[i]=(f[i-1]+f[i-2])%mod;
//		double ans = 0;
//		b[0]=by+1;
//		c[0]=cy+1;
//		gl[0]=1;
//		for(int i=1;i<n;i++)
//		{
//			b[i]=((long long)b[i-1]*bx+by)%p+1;
//			c[i]=((long long)c[i-1]*cx+cy)%p+1;
//		}
//		for(int ti=1;ti<=10000;ti++)
//		{
//			for(int i=0;i<=n;i++)
//			{
//				gl[i]+=c[i]<=b[i-1]?gl[i-1]:(double)b[i-1]/(double)c[i];
//			}
//			for(int i=n;i>=0;i--)
//			{
//				gl[i]+=c[i]>b[i-1]?(double)c[i]/(double)b[i-1]:0;
//			}
//		}
//		printf("%d\n",((long long)gl[n]*f[n])%mod);
//		dp[0]=a,dp[1]=2*a*gl[1];
//		for(int i=2;i<=n;i++)
//			dp[i]=(dp[i-1]+dp[i-2])*gl[i];
//		printf("%d\n",(long long)dp[n]%mod);
//	}
	return 0;
}
