#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn],tong[maxn];
bool judge(int l,int r)
{
	memset(tong,0,sizeof(tong));
	int minn=123456789,maxx=0;
	for(int i=l;i<=r;i++)
	{
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
		tong[a[i]]=1;
	}
	for(int i=minn;i<=maxx;i++)
	{
		if(!tong[i])
			return 0;
	}
	return 1;
}
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(int ti=1;ti<=m;ti++)
	{
		int l,r,flg=0,ansl=1,ansr=n;
		scanf("%d%d",&l,&r);
		for(int i=l;i>=1;i--)
		{
			for(int j=r;j<=n;j++)
			{
				if(judge(i,j))
				{
					flg=1;
					ansl=i,ansr=j;
					break;
				}
				if(flg)
				break;
			}
			if(flg)
				break;
		}
		printf("%d %d\n",ansl,ansr);
	}
}
