#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	
	int a,b,c,m=0,t=0;
	int temp[2][c];
	scanf("%d%d%d",&a,&b,&c);
	if(b>a){
		t=b;
		b=a;
		a=t;
	}
	if(c>a&&c>b){
		printf("impossible");
		return 0;
	}
	if(a==b){
		printf("impossible");
		return 0;
	}
	if(c==a||c==b){
		printf("1");
		return 0;
	}
	if(a==1){
		if(c>b-c){
			printf("%d",b-c);
			return 0;
		}else{
			printf("%d",c);
			return 0;
		}
	}
	if(c%a==0&&c>a){
		printf("%d",c/a*2);
		return 0;
	}
}
