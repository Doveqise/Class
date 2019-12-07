#include<bits/stdc++.h>
using namespace std;
#define int long long
int sqr(int x)
{
	return x*x;
}
signed main()
{
//	freopen("math.in","r",stdin);
//	freopen("math.out","w",stdout);
	int x1,y1,x2,y2;
	while(scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2))
	{
		int lmd1,lmd2,dlt=1000000000000;
		for(lmd1=-101;lmd1<=101;lmd1++)
			for(lmd2=-101;lmd2<=101;lmd2++)
			{
				if(!lmd1&&!lmd2)
					continue;
				dlt=min(dlt,sqr(abs(lmd1*x1+lmd2*x2))+sqr(abs(lmd1*y1+lmd2*y2)));
			}
		printf("%lld\n",dlt);
	}
}
