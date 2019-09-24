#include<bits/stdc++.h>
#define reg register int
#define il inline
#define fi first
#define se second
#define mk(a,b) make_pair(a,b)
#define numb (ch^'0')
using namespace std;
typedef long long ll;
template<class T>il void rd(T &x){
    char ch;x=0;bool fl=false;
    while(!isdigit(ch=getchar()))(ch=='-')&&(fl=true);
    for(x=numb;isdigit(ch=getchar());x=x*10+numb);
    (fl==true)&&(x=-x);
}
template<class T>il void output(T x){if(x/10)output(x/10);putchar(x%10+'0');}
template<class T>il void ot(T x){if(x<0) putchar('-'),x=-x;output(x);putchar(' ');}
template<class T>il void prt(T a[],int st,int nd){for(reg i=st;i<=nd;++i) ot(a[i]);putchar('\n');}

namespace Miracle{
const int N=1e6+5;
int n;
struct po{
	int p,v;
	bool friend operator <(po a,po b){
		if(a.p!=b.p) return a.p<b.p;
		return a.v>b.v;
	}
}a[N];
int b[N],tot;
int f[N];
int ans;
void upda(int x,int c){
	for(;x<=tot;x+=x&(-x)) f[x]=max(f[x],c);
}
int query(int x){
	int ret=0;
	for(;x;x-=x&(-x)) ret=max(ret,f[x]);
	return ret;
}
void clear(){
	ans=0;tot=0;
	memset(b,0,sizeof b);
	memset(f,0,sizeof f);
}
int main(){
	int t;
	rd(t);
	while(t--){
		clear();
		rd(n);
		for(reg i=1;i<=n;++i) rd(a[i].p);
		for(reg i=1;i<=n;++i) rd(a[i].v),b[++tot]=a[i].v;
		sort(b+1,b+tot+1);
		tot=unique(b+1,b+tot+1)-b-1;
		sort(a+1,a+n+1);
		for(reg i=1;i<=n;++i){
			a[i].v=lower_bound(b+1,b+tot+1,a[i].v)-b;
		}
		for(reg i=n;i>=1;--i){
			int tmp=query(a[i].v)+1;
			upda(a[i].v,tmp);
			ans=max(ans,tmp);
		}
		cout<<n-ans<<endl;
	}
	return 0;
}

}
signed main(){
	freopen("waterwheel.in","r",stdin);
	freopen("waterwheel.out","w",stdout);
	Miracle::main();
	return 0;
}

/*
   Author: *Miracle*
   Date: 2019/4/21 8:21:20
*/


