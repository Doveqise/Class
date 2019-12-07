#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6+5;
const int mod = 1e9+7;
int row[maxn],line[maxn],rowbs[maxn],linebs[maxn];
signed main()
{
	int n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		row[i]=i;
		rowbs[i]=m;
	}
	for(int i=1;i<=m;i++)
	{
		line[i]=i-1;
		linebs[i]=n;
	}
	for(int i=1;i<=k;i++)
	{
		char opt;
		int x,y;
		scanf("%c %lld %lld",&opt,&x,&y);
		if(opt=='R')
		{
			row[x]=row1[x]*y%mod;
			
		}
	}
}
