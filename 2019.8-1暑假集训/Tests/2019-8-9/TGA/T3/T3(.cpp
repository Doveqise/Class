#include<bits/stdc++.h>
#pragma GCC optimize (2)
using namespace std;
const int maxn = 1e4+5;
int dp[maxn][maxn],val[maxn],gdd[maxn],cnt=0;
int find1(int x)
{
	int l=1,r=cnt,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(gdd[mid]==x)
			return mid;
		if(gdd[mid]>x)
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
int find2(int x)
{
	int l=1,r=cnt,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(gdd[mid]==x)
			return mid+1;
		if(gdd[mid]<x)
			l=mid+1;
		else
			r=mid;
	}
	if(gdd[l]==x)
		l++;
	return l;
}
int op(int a,int b)
{
	if(a==b)
		return *lower_bound(gdd+1,gdd+1+cnt,a)==a;
	int l=find1(a),r=find2(b);
	if((a+b+1)%2&&gdd[find1(a+b>>1)]==a+b>>1)
		r--;
	return r-l;
}
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
			gdd[++cnt]=i;
		}
		else while(l>=1&&r<=n)
		{
			dp[l][r]++;
			l--,r++;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ans=max(ans,dp[i][j]-op(i,j));
	printf("%d\n",ans+cnt);
	return 0;
}

