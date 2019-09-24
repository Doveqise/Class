#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define ri register int
#define il inline
#define uint unsigned int
namespace Maker
{
unsigned int x0,seed;
void init() {scanf("%u%u",&x0,&seed);}
inline uint getnum()
{
	x0=(x0<<3)^x0;
	x0=((x0>>5)+seed)^x0;
	return x0;
}
}
#define N 100005
il void ckmax(uint &x,const uint v) {x<v?x=v:0;}
int n,m;
int lg[N];
uint st[N][17];
void prework()
{
	for(ri i=2; i<=n; ++i) lg[i]=lg[i>>1]+1;
}
il void upd(int l,int r,uint v)
{
	const int k=lg[r-l+1];
	ckmax(st[l][k],v),ckmax(st[r-(1<<k)+1][k],v);
}
il void solve()
{
	for(ri j=16; j>=1; --j)
		for(ri i=1; i+(1<<j)-1<=n; ++i)
		{
			ckmax(st[i][j-1],st[i][j]),ckmax(st[i+(1<<(j-1))][j-1],st[i][j]);
		}
}
int main()
{
#ifdef M207
	freopen("in.in","r",stdin);
	// freopen("ot.out","w",stdout);
#else
	freopen("simulate_train.in","r",stdin);
	freopen("simulate_train.out","w",stdout);
#endif
	int typ;
	scanf("%d%d%d",&n,&m,&typ);
	for(int i=1; i<=n; ++i) scanf("%u",&st[i][0]);
	prework();
	Maker::init();
	for(int i=1; i<=m; ++i)
	{
		int l=Maker::getnum()%n+1,r=Maker::getnum()%n+1;
		unsigned int v=Maker::getnum();
		if(l>r) swap(l,r);
		if(typ==1) l=1;
		upd(l,r,v);
	}
	solve();
	for(ri i=1; i<=n; ++i) printf("%u ",st[i][0]);
	return 0;
}
