#include <cstdio>
using namespace std;
int a,b,c;
int main(){
	//freopen("water.in","r",stdin);
	//freopen("water.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	if(c==a || c==b){
		printf("1");
		return 0;
	}
	if(c>a && c>b){
		printf("impossible");
		return 0;
	}
	if(a==b && c!=a){
		printf("impossible");
		return 0;
	}
	if(a-b==1 || a-b==-1){
		if(c==1){
			printf("2");
			return 0;
		}
		if(c==2){
			printf("7");
		}
	}
	if(a-b==2 || a-b==-2){
		if(c==1){
			printf("2");
			return 0;
		}
		if(c==2){
			printf("7");
			return 0;
		}
	}
	printf("impossible");
	return 0;
}
