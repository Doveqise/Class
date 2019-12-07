#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int nxt[maxn<<1],hd[maxn<<1],to[maxn<<1],cnt=0;
int vis[maxn],rt,xid[maxn<<1],id=0,ptn=1,ans=0;
int n,m,son[maxn<<1];
struct dd
{
	int l,r;
	bool operator < (const dd b) const
	{
		return xid[r]==xid[b.r]?xid[l]<xid[b.l]:xid[r]<xid[b.r];
	}
}
pt[maxn];
void add(int u, int v)
{
	nxt[++cnt]=hd[u];
	hd[u]=cnt;
	to[cnt]=v;
}
void dfs(int u)
{
	if(vis[u])
		return;
	vis[u]=1;
	int tim=0;
	for(int i=hd[u];i;i=nxt[i])
	{
		tim++;
		int v=to[i];
		if(!vis[v])
		{
			dfs(v);
		}
	}
	if(tim==1)
	{
		if(rt)
			rt=min(rt,u);
		else
			rt=u;
	}
	return;
}
void giveid(int u)
{
	xid[u]=++id;
	for(int i=hd[u];i;i=nxt[i])
	{
		int v=to[i];
		if(!xid[v])
		{
			//printf("son[%d]=%d\n",u,v);
			son[u]=v;
			giveid(v);
		}
	}
	return;
}
void solve(int u,int ll)
{
	vis[u]=1;
	while(xid[u]>=xid[pt[ptn].r]&&ptn<=m)
	{
		ll=max(ll,xid[pt[ptn].l]);
		ptn++;
	}
	ans+=(xid[u]-ll-1)>0?(xid[u]-ll-1):0;
	//printf("ans[%d]=%d\n",u,ans);
	if(son[u]&&(!vis[son[u]]))
		solve(son[u],ll);
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=m;i++)
		scanf("%d%d",&pt[i].l,&pt[i].r);
	dfs(1);
	giveid(rt);
	for(int i=1;i<=m;i++)
		if(xid[pt[i].l]>xid[pt[i].r])
			swap(pt[i].l,pt[i].r);
	sort(pt+1,pt+1+m);
	memset(vis,0,sizeof(vis));
	solve(rt,0);
	//printf("%d %d\n",xid[pt[1].l],xid[pt[1].r]);
	printf("%d\n",ans);
	return 0;
}
