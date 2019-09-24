#include <cstdio>
using namespace std;
int main(){
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	long long n,k;
	scanf("%lld%lld",&n,&k);
	long long c;
	n*=2;
	if(n%k!=0)c=n/k+1;
	else c=n/k;
	printf("%lld",c);
	return 0;
} 
