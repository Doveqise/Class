#include<iostream>
using namespace std;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int a,b,c,temp,ans;
	cin>>a>>b>>c;
	if(a>b){
		temp=a;
		a=b;
		b=temp;
	}
	if(a==b&&b!=c&&(c%a!=0)){
		cout<<"impossible"<<endl;
		return 0;
	}
	if(c>b||c%(b-a)!=0){
		cout<<"impossible"<<endl;
		return 0;
	}
	else {
		if(c%a==0&&c%b!=0){
			ans=2*(c/a);
			cout<<ans<<endl;
			return 0;
		}
		else {
			if (c%b==0){
			ans=1;
			cout<<ans<<endl;
			return 0;
			}
				else{
					ans=2+(c/(b-a)-1)*4;
					cout<<ans<<endl;
					return 0;
				}
			}
		}
	return 0;			
} 
