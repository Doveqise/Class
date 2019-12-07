#include<bits/stdc++.h>
using namespace std;
const int maxn = 6e4+5;
int n,m;
char opt[10];
struct node
{
	int x,y,z;
	bool operator <(const node b) const
	{
		return x<b.x;
	}
}
a[maxn];
struct pi
{
	int first,second;
	bool operator<(const pi b)const
	{
		return first>b.first;
	}
}
;
int bh[maxn];
void SWAP(int x,int y)
{
	swap(a[x+1].z,a[y+1].z);
	return;
}
void QUERY(int x0,int y0,int x1,int y1,int k)
{
	//priority_queue<int>q;
	priority_queue<pi>q;
	int frm=lower_bound(bh+1,bh+1+n,x0)-bh,to=lower_bound(bh+1,bh+1+n,x1+1)-bh;
	pi p;
	for(int i=frm;i<to;i++)
	{
		p.first=a[i].z;
		p.second=bh[i];
		q.push(p);
	}
	if(q.size()<k)
	{
		puts("It doesn't exist.");
		return;
	}
	for(int i=1;i<k;i++)
		q.pop();
	printf("%d\n",q.top().first);
	while(!q.empty())
 		q.pop();
 	return;
}
signed main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		bh[i]=a[i].x;
	for(int i=1;i<=m;i++)
	{
		scanf("%s",opt);
		if(opt[0]=='Q')
		{
			int xo,yo,xl,yl,k;
			scanf("%d %d %d %d %d",&xo,&yo,&xl,&yl,&k);
			QUERY(xo,yo,xl,yl,k);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			SWAP(x,y);
		}
	}
	return 0;
}
