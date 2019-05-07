#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int l,r;

struct Num{
	int a[10]; //0~9 每个数字出现次数 
	void print(){
		puts("#");
		for(int i=0;i<10;i++){
			printf("%d ",a[i]);
		}
		puts("##");
	}
};
Num operator + (Num a,Num b){
	Num c;
	for(int i=0;i<=9;i++){
		c.a[i] = a.a[i]+b.a[i];
	}
	return c;
}
Num a[15]; // 长度为i 带前导0的数字出现次数 
Num b[15]; // 长度为i 不含前导0的数字出现次数 
int c[15]; // 长度为i 带前导0的11出现次数 
int d[15]; // 长度为i 1开头有多少个数字 
int pow(int a,int b){
	int ret = 1;
	for(int i=0;i<b;i++) ret =ret*a;
	return ret;	
}
int main(){
	for(int i=0;i<=9;i++) a[1].a[i] = 1;
	for(int i=2;i<=8;i++){
		for(int j=0;j<=9;j++){
			a[i].a[j] += pow(10,i-1);
			a[i] = a[i]+a[i-1];
		}
	}
	a[5].print();
	
//	d[2] = 1;
//	d[i] = pow(10,i-1)
	c[2] = 1;
	for(int i=3;i<=8;i++){
		for(int j=0;j<=9;j++){
			c[i] += c[i-1];
			if(j==1){
				c[i] += pow(10,i-2);
			}
		}
	}
	
	// 000~999
	// 00~99  11   1
	// 0,1,2,3..9
	
	
	// 0~999
	
	// 1xx
	// 00~99
	
	b[1] = a[1];
	for(int i=2;i<=8;i++){
		b[i] = b[i-1]; 
		for(int j=1;j<=9;j++){
			b[i].a[j] += pow(10,i-1);
			b[i] = b[i]+a[i-1];
		} 
	}
	// 0~99 + x xx
	b[2].print();
	
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

