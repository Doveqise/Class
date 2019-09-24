#include<iostream>
using namespace std;
int main(){
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	long long n,k,ans=0;
	cin>>n>>k;
	if(n<=k) cout<<2;
	else{
		ans=(2*n)/k;
		if(2*n%k==0)cout<<ans<<endl;
		else cout<<ans+1;
	}
	return 0;
}
