
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int w[200005];
int head[200005],nxt[200005*2],ver[200005*2];
int tot;
void add(int x,int y){
	ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;	
}
int tmp[200005];
int mx;
int sum;

int cnt;
void dfs(int x,int fa){
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		if(y==fa) continue;
		dfs(y,x);
	}
	cnt = 0;
	// dis x 1
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];
		tmp[++cnt]=w[y];
	}

	// tmp
	int premx=0,presum=0;
	for(int i=1;i<=cnt;i++){
		mx = max(mx,premx*tmp[i]);
		sum += presum * tmp[i];
		premx =max(premx,tmp[i]);
		presum += tmp[i];
	}
	
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	
	dfs(1,0); 
	printf("%d %d\n",mx, sum*2);
	
	return 0;
}

