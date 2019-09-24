
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f[];
int ans;
void dfs(int x,int fa){
	// f[x]初始值 
	f[x] = 1;
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i]; // 边i 指向的点
		if(y==fa) continue;
		// 
		dfs(y,x); 
		// f[y] 合并到 f[x]
		ans = max(ans,f[x] + f[y]);
		f[x] = max(f[y]+1,f[x]);
	}
	// 
	ans = max(ans,f[x]);
}
int main(){
	
	// root 1
	dfs(1, 0);
	
	
	return 0;
}

