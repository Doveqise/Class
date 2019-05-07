#include<cstdio>
using namespace std;
int main(){
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	
	long long n,k,ans,m;
	scanf("%lld%lld",&n,&k);
	m=2*n;
	if(n<k){
	ans=m;
	}else{
		if(m%k){
			ans=(m-m%k)/k+1;
		}else{
			ans=m/k;
		}
	}
	printf("%lld",ans);
	return 0;
}
