#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int fa[211111],size[211111];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy)return ;
	if(size[fx]>size[fy])fa[fy]=fx,size[fx]+=size[fy];
	else fa[fx]=fy,size[fy]+=size[fx];
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) && (n||m)){
		for(int i=1;i<=n;i++)fa[i]=i,size[i]=1;
		for(int i=1;i<=m;i++){
			int a,b;scanf("%d",&b);
			if(!b)continue;
			b--;scanf("%d",&a);a++;
			while(b--){
				int c;scanf("%d",&c);c++;
				merge(a,c);
			}
		}
		cout<<size[find(1)]<<endl;
	}
	return 0;
}

