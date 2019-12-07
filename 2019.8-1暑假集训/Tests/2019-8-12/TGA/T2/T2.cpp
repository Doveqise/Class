#include<bits/stdc++.h>
#pragma GCC optimize (3)
#define int long long
using namespace std;
const int maxn = 1e3+5;
int n,m,D;
struct nodep
{
	int x,y;
}
a[maxn];
struct noden
{
	int x,y;
}
b[maxn];
int ping[maxn][maxn][2],nping[maxn][maxn][2],bian[maxn][maxn];
void pingyz(int pin,int nopin)
{
	bian[pin][nopin]=(abs(a[pin].x-b[nopin].x)+abs(a[pin].y-b[nopin].y))>D;
}
signed main()
{
	freopen("mhw.in","r",stdin);
	freopen("mhw.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&D);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);
	for(int i=1;i<=m;i++)
		scanf("%lld%lld",&b[i].x,&b[i].y);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			pingyz(i,j);
	for(int i=1;i<=n;i++)
		for(int j1=1;j1<=m;j1++)
			for(int j2=j1+1;j2<=m;j2++)
				if(bian[i][j1]==1&&bian[i][j2]==0)
					nping[j1][j2][0]++;
				else if(bian[i][j2]==1&&bian[i][j1]==0)
					nping[j1][j2][1]++;
	for(int j=1;j<=m;j++)
		for(int i1=1;i1<=n;i1++)
			for(int i2=i1+1;i2<=n;i2++)
				if(bian[i1][j]==1&&bian[i2][j]==0)
					ping[i1][i2][1]++;
				else if(bian[i2][j]==1&&bian[i1][j]==0)
					ping[i1][i2][0]++;
	int maxxp=-1234567898765,minnp=1234567898765;
	int ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			ans1+=max(maxxp,max(ping[i][j][0],ping[i][j][1]));
			ans2+=min(minnp,min(ping[i][j][0],ping[i][j][1]));
		}
	int maxxn=-1234567898765,minnn=1234567898765;
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
		{
			ans1+=max(maxxn,max(nping[i][j][0],nping[i][j][1]));
			ans2+=min(minnn,min(nping[i][j][0],nping[i][j][1]));
		}
	printf("%lld %lld\n",ans2,ans1);
	return 0;
}
/*
2 2 1
1 2
1 1
3 1
2 2 
*/
