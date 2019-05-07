#include<cstdio>
using namespace std;
int main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	
	int n,h,k,ans,ni,temp;
	int a[2001]={};
	scanf("%d%d%d",&n,&h,&k);
	if(n==1){
		scanf("%d",&ans);
		printf("%d",ans);
		return 0;
	}
	if(h==1){
		printf("1");
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&ni);
		for(int j=0;j<ni;j++){
			scanf("%d",&temp);
			a[temp]++;
		}
	}
	for(int i=0;i<2001;i++){
		if(a[i]){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
