#include<bits/stdc++.h>
using namespace std;
const int maxm = 3e4+5;
const int maxn = 2e2+5;
int hd[maxm],nxt[maxm],to[maxm],vis[maxn],isns[maxn],layer[maxn];
int cnt,n,m,laymax;
void add(int u, int v)
{
	nxt[++cnt]=hd[u];
	hd[u]=cnt;
	to[cnt]=v;
}
void dfs(int u,int lay)
{
	layer[u]=max(layer[u],lay);
	for(int i=hd[u];i;i=nxt[i])
	{
		int v=to[i];
		dfs(v,lay+1);
	}
	laymax=max(laymax,u);
	return;
}
void spfa(int s)
{
	//printf("%d\n",s);
	queue<int>q;
	vis[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=hd[u];i;i=nxt[i])
		{
			int v=to[i];
			if(!vis[v])
			{
				vis[v]=1;
				q.push(v);
			}
		}
	}
}
int solve(int x)
{
	int ret=0;
	spfa(x);
	ret++;
	for(int lay=1;lay<=n;lay++)
		for(int i=1;i<=n;i++)
			if(layer[i]==lay&&!vis[i])
			{
				spfa(i);
				ret++;
			}
	return ret;
}
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		isns[v]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!isns[i])
			dfs(i,1);
	}
	for(int i=1;i<=n;i++)
	{
		if(isns[i])continue;
		memset(vis,0,sizeof(vis));
		ans=max(ans,solve(i));
		//printf("Num:%d\n",i);
	}
	printf("%d",ans);
	return 0;
}
