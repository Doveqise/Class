#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
char opt[10];
struct node
{
	int x,y,val,id;
	bool operator < (const node b) const
	{
		return val<b.val;
	}
}
a[maxn];
signed main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		a[i].id=i;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].val);
	sort(a+1,a+1+n);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",opt);
		if(opt[0]=='S')
		{
			int aa,aaa;
			scanf("%d%d",&aa,&aaa);
			for(int j=1;j<=n;j++)
				if(a[j].id==aa+1)
				{
					aa=j;
					break;
				}
			for(int j=1;j<=n;j++)
				if(a[j].id==aaa+1)
				{
					aaa=j;
					break;
				}
			swap(a[aa].val,a[aaa].val);
			swap(a[aa],a[aaa]);
		}
		else
		{
			int x0,y0,x1,y1,k,prt=0;
			scanf("%d%d%d%d%d",&x0,&y0,&x1,&y1,&k);
			if(x0>x1)swap(x0,x1);
			if(y0>y1)swap(y0,y1);
			for(int i=1;i<=n;i++)
				if(a[i].x>=x0&&a[i].x<=x1&&a[i].y>=y0&&a[i].y<=y1)
				{
					k--;
					if(!k)
					{
						printf("%d\n",a[i].val);
						prt=1;
					}
				}
			if(!prt)
				puts("It doesn't exist.");
		}
	}
}
