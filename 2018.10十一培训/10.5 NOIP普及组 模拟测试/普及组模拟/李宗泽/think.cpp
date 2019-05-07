#include<cstdio>
#include<cmath>
using namespace std;
int is_a_vegenum(int n){
	int m=sqrt(n);
	for(int i=2;i<=m;i++){
		if(n%i==0)return 0;}return 1;}
int main(){
	//freopen("think.out","w",stdout);
	int n;scanf("%d",&n);
	int m=n/2;
	for(int i=3;i<m;i+=2){if(is_a_vegenum(i)&&is_a_vegenum(n-i))printf("%d %d\n",i,n-i);}
	//fclose(stdout);
	return 0;}
