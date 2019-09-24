#include<cstdio>
using namespace std;
int n,m,x;
int p[15];
int f[15][5000];
int mod=100000000;
bool hefa[5000];
void dfs(int x,int p){// x --> suan wan x
	if(x==m) hefa[p]=1;
	if(x>=m) return;
	if(p&1){
		dfs(x+1,p<<1);
	}else{
		dfs(x+1,p<<1);
		dfs(x+1,(p<<1)+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&x);
			if(!x) p[i]|=1<<j;
		}
	}
	dfs(1,0);dfs(1,1);
	for(int i=0;i<1<<m;i++){
		if(hefa[i]&&(!(i&p[0]))){
			f[0][i]=1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<1<<m;j++){
			if(hefa[j]&&(!(j&p[i]))){
				for(int k=0;k<1<<m;k++){
					if(hefa[k]&&(!(k&p[i-1]))&&(!(k&j))){
						f[i][j]+=f[i-1][k];
						if(f[i][j]>=mod) f[i][j]%=mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(int j=0;j<1<<m;j++){
		if(hefa[j]&&(!(j&p[n-1]))){
			ans+=f[n-1][j];
			if(ans>=mod) ans%=mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
