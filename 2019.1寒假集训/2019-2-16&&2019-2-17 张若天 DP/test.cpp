#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,k;

int a[1000005];
int q[1000005];
int h,t;
// h 队头
// t 队尾后一个元素 
// 队列里存储元素在a[]的下标 

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		// +a[i]
		if(h==t || a[q[t-1]]>a[i]) q[t++]=i;
		else{
			while(h!=t && a[q[t-1]]<=a[i]) t--;
			q[t++]=i;	
		}
		// -a[i-k] 
		if(q[h] == i-k) h++;
		if(i>=k) printf("%d\n", a[q[h]]);
	}
	
	return 0;
}

