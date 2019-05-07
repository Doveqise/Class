#include<iostream>
using namespace std;
int n,h,k,a[2000][2000];
int main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	cin>>n>>h>>k;
	if(n==1){
		for(int i=1;i<=n;i++){
			cin>>a[i][1];
			for(int j=1;j<=a[i][1];i++){
				cin>>a[i][j+1];
			}
		}	
	}
	cout<<a[1][1];
} 
