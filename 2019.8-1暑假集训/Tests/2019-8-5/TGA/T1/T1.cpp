#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int mod = 1e9+7;
int a[maxn][maxn];
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n,m,k;
	long long ans = 0;
	scanf("%d%d%d",&n,&m,&k);
	int cnt = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=++cnt;
	for(int i=1;i<=k;i++)
	{
		char opt;
		int x,y;
		cin>>opt>>x>>y;
		if(opt=='R')
			for(int i=1;i<=m;i++)
				a[x][i]=a[x][i]*y%mod;
		else
			for(int i=1;i<=n;i++)
				a[i][x]=a[i][x]*y%mod;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans=ans+a[i][j]%mod;
	printf("%lld\n",ans);
	return 0;
}
