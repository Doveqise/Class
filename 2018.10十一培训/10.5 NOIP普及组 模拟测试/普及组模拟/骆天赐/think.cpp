#include<iostream>
#include<cmath>
using namespace std;
bool b[100001];
int main(){
	freopen("think.in","r",stdin);
	freopen("think.out","w",stdout);
	int n,s,ans=0;
	cin>>n;
	for(int i=2;i<=n;i++){
		s=sqrt(i);
		for(int j=2;j<=s;j++){
			if(i%j==0&&i/j!=0) ans++;
		}
		if(ans==0) b[i]=1;
		ans=0;
	}
	for(int i=2;i<=(n+10)/2;i++){
		if(b[i]==1&&b[n-i]==1&&i<=n-i&&i%2==1)
			cout<<i<<" "<<n-i<<endl;		
	}
	return 0;
}
