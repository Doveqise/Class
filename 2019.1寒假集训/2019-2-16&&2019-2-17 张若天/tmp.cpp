#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int l,r;

int main(){

	int x=12345;
	char s[20];
	sprintf(s+1,"%d",x);
	// s = ' 12345'
	
	int len = 5;
	for(int i=1;i<=len;i++){
		int x = s[i]-'0';
		s[i] = 0;
		for(int j=0;j<x;j++){
			// s[1..i-1]
			// * pow(10,len-i)
			// + a[len-i]
			
			printf("%s%d\n",s+1,j);
		}
		s[i] = x+'0';
	}
	
	
	return 0;
}

