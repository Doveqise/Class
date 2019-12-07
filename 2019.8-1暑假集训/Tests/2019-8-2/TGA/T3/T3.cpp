#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n;
struct node
{
	int x,y;
	bool operator < (const node b) const
	{
		return x==b.x?y>b.y:x<b.x;
	}
}
a[maxn];
int dist(node a,node b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int dist(node a,node b,node c)
{
	return dist(a,b)+dist(b,c)+dist(a,c);
}
signed main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n);
	int disma=0,dismi=10000000;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
			{
				disma=max(disma,dist(a[i],a[j],a[k]));
				dismi=min(dismi,dist(a[i],a[j],a[k]));
			}
	printf("%d\n%d\n",disma,dismi);
	return 0;
}
