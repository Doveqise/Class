#include<cstdio>
#include<algorithm>
using namespace std;
#define reg register int
#define ui unsigned int
namespace Maker
{
unsigned int x0,seed;
void init() {scanf("%u%u",&x0,&seed);}
inline unsigned int getnum()
{
	x0=(x0<<3)^x0;
	x0=((x0>>5)+seed)^x0;
	return x0;
}
}
const int N=1e5+5;
int n,m;
ui a[100005];
int lg[100005];
ui f[N][20];
int main()
{
	freopen("simulate_train.in","r",stdin);
	freopen("simulate_train.out","w",stdout);
	int typ;
	scanf("%d%d%d",&n,&m,&typ);
	for(reg i=1; i<=n; ++i) {
		lg[i]=(i>>(lg[i-1]+1))?lg[i-1]+1:lg[i-1];
	}
	for(int i=1; i<=n; ++i) scanf("%u",&a[i]);
	Maker::init();
	for(int i=1; i<=m; ++i)
	{
		int l=Maker::getnum()%n+1,r=Maker::getnum()%n+1;
		unsigned int v=Maker::getnum();
		if(l>r) swap(l,r);
		if(typ==1) l=1;
		int len=(r-l+1);
		f[l][lg[len]]=max(f[l][lg[len]],v);
		f[r-(1<<lg[len])+1][lg[len]]=max(f[r-(1<<lg[len])+1][lg[len]],v);
	}
	for(reg j=19; j>=1; --j) {
		for(reg i=1; i+(1<<j)-1<=n; ++i) {
			f[i][j-1]=max(f[i][j-1],f[i][j]);
			f[i+(1<<(j-1))][j-1]=max(f[i+(1<<(j-1))][j-1],f[i][j]);
		}
	}
	for(reg i=1; i<=n; ++i) {
		printf("%u ",max(f[i][0],a[i]));
	}
	return 0;
}