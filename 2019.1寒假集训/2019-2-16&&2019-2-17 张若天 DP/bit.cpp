#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int n;
int a[100000];

int lowbit(int x){
	return x&-x;	
}
void modify(int pos,int k){ // k>=a[pos] 
	while(pos<=n){
		a[pos]=max(a[pos],k);
		pos+=lowbit(pos);
	}
}
int ask(int pos){
	int ret = 0;
	while(pos>0){
		ret=max(ret, a[pos]);
		pos-=lowbit(pos);
	}
	return ret;
}
int b[100000];
int f[100000];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	// ÀëÉ¢»¯b[]
	 
	for(int i=1;i<=n;i++){
		f[i] = ask(b[i]-1) +1;
		modify(b[i],f[i]);
	}
	int ans = 0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]);
	printf("%d\n",ans);
	
	
	return 0;
}


