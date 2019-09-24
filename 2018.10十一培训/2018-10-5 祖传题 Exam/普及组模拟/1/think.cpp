#include <cstdio>
using namespace std;
int n;
int su(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
int main(){
	freopen("think.in","r",stdin);
	freopen("think.out","w",stdout);
	scanf("%d",&n);
	for(int i=3;i<=n/2;i=i+2){
		int j=n-i;
		if(su(i)&&su(j))printf("%d %d\n",i,j);
	}
	return 0;
}
