#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
const int maxt = 1e6+5;
int cnt=0;
struct dream
{
	int l,r;
	bool operator < (const dream b)const
	{
		return r==b.r?l<b.l:r<b.r;
	}
}
dr[maxn];
int pt[maxn];
bool judge(int a,int b)
{
	return dr[a].l<=b&&dr[a].r>=b;
}
int n,m;
signed main()
{	
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&dr[i].l,&dr[i].r);
		dr[i].l=min(dr[i].l,maxt);
		dr[i].r=min(dr[i].r,maxt);
	}
	for(int i=1;i<=m;i++)
		scanf("%d",&pt[i]);
	sort(pt+1,pt+1+m);
	sort(dr+1,dr+1+n);
	int dmt=1,ptt=1,ans=0;
	while(dmt<=n&&ptt<=m)
	{
		if(judge(dmt,ptt))
		{
			ptt++;
			ans++;
		}
		dmt++;
	}
	printf("%d\n",ans);
	return 0;
}
