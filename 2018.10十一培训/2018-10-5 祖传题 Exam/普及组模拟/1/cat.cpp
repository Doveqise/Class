#include <bits/stdc++.h>
using namespace std;
int n,h,k;
int a,b;
int Max;
int main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	int count=0,Max=0;
	scanf("%d%d%d",&n,&h,&k);
	if(h==1){
		printf("1");
		return 0;
	}
	if(n==1){
		int x;
		scanf("%d",&x);
		printf("%d",x);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		for(int j=1;j<=a;j++){
			scanf("%d",&b);
		}
		Max=max(Max,a);
	}
	printf("%d",Max);
	return 0;
}
