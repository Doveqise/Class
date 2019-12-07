#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define ll unsigned long long
const int maxk = 2e2+5;
const int mod = 998244353;
int k;
struct mat
{
    int mt[maxk][maxk];
}
bs,dw,jz,li;
mat operator *(mat a,mat b)
{
    mat ret=li;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            ll now=0;
            for(int w=1;w<=k;w++)
            {
            	//printf("%d %d\n",a.mt[i][w],b.mt[w][j]);
                now=(now+(a.mt[i][w]%mod)*(b.mt[w][j]%mod))%mod;
            }
            ret.mt[i][j]=now;
        }
    }
    return ret;
}
ll qpow(ll a,ll b)
{
	ll base = a,ans = 1;
	while(b)
	{
		if(b & 1)
			ans = (ans%mod) * (base%mod) % mod;
		base = (base%mod) * (base%mod) % mod;
		b >>= 1;
	}
	return ans;
}
mat qpowm(int b)
{
    mat base=bs,ans=dw;
    while(b)
    {
        if(b&1)
            ans=base*ans;
        base=base*base;
        b>>=1;
    }
    return ans;
}
mat pow(mat x,mat y)
{
    mat ret;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            ll now=1;
            for(int w=1;w<=k;w++)
            {
            	if(!y.mt[w][j])
            		continue;
                now=now*qpow(x.mt[i][w]%mod,y.mt[w][j]%mod)%mod;
            }
            ret.mt[i][j]=now;
        }
    }
    return ret;
}
signed main()
{
    int n;
    scanf("%llu%llu",&n,&k);
    for(int i=1;i<=k;i++)
        scanf("%llu",&bs.mt[i][1]);
    for(int i=2;i<=k;i++)
        bs.mt[i-1][i]=1;
    for(int i=1;i<=k;i++)
        dw.mt[i][i]=1;
    for(int i=1;i<=k;i++)
        scanf("%llu",&jz.mt[1][i]);
	mat nw=bs*bs*bs;
	nw=nw*bs;
    for(int i=1;i<=k;i++)
    {
    	for(int j=1;j<=k;j++)
    	{
    		printf("%llu ",nw.mt[i][j]);
		}
		printf("\n");
	}
	//nw=nw*bs;
    //printf("%lld\n",pow(jz,bs));
    //printf("%lld",pow(jz,qpowm(n-k+1)));
}
