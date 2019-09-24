#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int r,c;
int h[105][105];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int g[105][105];
int f(int x,int y){
	if(g[x][y]) return g[x][y];
	// 从x,y开始 最远滑多远
	int mx = 1;
	for(int k=0;k<4;k++){
		int nx = dx[k]+x;
		int ny = dy[k]+y;
		//
		if(nx<1 || nx >r || ny <1 || ny>c) continue;
		if(h[x][y]<=h[nx][ny]) continue;
		int tmp=f(nx,ny);
		mx = max(mx, tmp+1);
	}
	return g[x][y]=mx;
}

int main(){
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) scanf("%d",&h[i][j]);
	int mx = 0;
	for(int i=1;i<=r;i++) for(int j=1;j<=c;j++) {
		int tmp = f(i,j);
		mx = max(mx,tmp);	
	}
	printf("%d\n",mx);
	
	return 0;
}

// f[i][j] = max(f[k][l]) +1  (h[i][j] > h[k][l], (i,j)(k,l)相邻)


