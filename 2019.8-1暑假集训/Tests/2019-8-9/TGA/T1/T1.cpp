#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e2+5;
const int ms = 503;
int n,m;
char ch,mp[maxn][maxn];
int vis[maxn*maxn],por,nowc,f;
void dfs(int nowc,int dep,int por)
{
	int nowccms=nowc/ms,nowcmms=nowc%ms;
	if(vis[nowc]<=dep&&vis[nowc])
		return;
	if(nowc==f)
	{
		vis[nowc]=dep;
		return;
	}
	vis[nowc]=dep;
	if(mp[nowccms+1][nowcmms]!='#')
		dfs(nowc+ms,dep+1,por);
	if(mp[nowccms-1][nowcmms]!='#')
		dfs(nowc-ms,dep+1,por);
	if(mp[nowccms][nowcmms+1]!='#')
		dfs(nowc+1,dep+1,por);
	if(mp[nowccms][nowcmms-1]!='#')
		dfs(nowc-1,dep+1,por);
		
	if(mp[nowccms+1][nowcmms]=='#')
	{
		if(por==-1)
			por=nowc+ms;
		for(int i=nowccms;i>=1;i--)
			if(mp[i][nowcmms]=='#')
			{
				dfs(i*ms+nowcmms+ms,dep+1,i*ms+nowcmms);
				break;
			}
		for(int i=nowcmms;i>=1;i--)
			if(mp[nowccms][i]=='#')
			{
				dfs(nowc+i-nowcmms+1,dep+1,nowc+i-nowcmms);
				break;
			}
		for(int i=nowcmms;i<=m;i++)
			if(mp[nowccms][i]=='#')
			{
				dfs(nowc+i-nowcmms-1,dep+1,nowc+i-nowcmms);
				break;
			}
	}
	if(mp[nowccms-1][nowcmms]=='#')
	{
		if(por==-1)
			por=nowc+ms;
		for(int i=nowccms;i<=n;i++)
			if(mp[i][nowcmms]=='#')
			{
				dfs(i*ms+(nowcmms)-ms,dep+1,i*ms+(nowcmms));
				break;
			}
		for(int i=nowcmms;i>=1;i--)
			if(mp[nowccms][i]=='#')
			{
				dfs(nowc+i-nowcmms+1,dep+1,nowc+i-nowcmms);
				break;
			}
		for(int i=nowcmms;i<=m;i++)
			if(mp[nowccms][i]=='#')
			{
				dfs(nowc+i-nowcmms-1,dep+1,nowc+i-nowcmms);
				break;
			}
	}
	if(mp[nowccms][nowcmms+1]=='#')
	{
		if(por==-1)
			por=nowc+ms;
		for(int i=nowccms;i>=1;i--)
			if(mp[i][nowcmms]=='#')
			{
				dfs(i*ms+(nowcmms)+ms,dep+1,i*ms+(nowcmms));
				break;
			}
		for(int i=nowccms;i<=n;i++)
			if(mp[i][nowcmms]=='#')
			{
				dfs(i*ms+(nowcmms)-ms,dep+1,i*ms+(nowcmms)+ms);
				break;
			}
		for(int i=nowcmms;i>=1;i--)
			if(mp[nowccms][i]=='#')
			{
				dfs(nowc+i-nowcmms+1,dep+1,nowc+i-nowcmms);
				break;
			}
	}
	if(mp[nowccms+1][nowcmms-1]=='#')
	{
		if(por==-1)
			por=nowc+ms;
		for(int i=nowccms;i>=1;i--)
			if(mp[i][nowcmms]=='#')
			{
				dfs(i*ms+(nowcmms)+ms,dep+1,i*ms+(nowcmms));
				break;
			}
		for(int i=nowccms;i<=n;i++)
			if(mp[i][nowcmms]=='#')
			{
				dfs(i*ms+(nowcmms)-ms,dep+1,i*ms+(nowcmms)+ms);
				break;
			}
		for(int i=nowcmms;i<=m;i++)
			if(mp[nowccms][i]=='#')
			{
				dfs(nowc+i-nowcmms-1,dep+1,nowc+i-nowcmms);
				break;
			}
	}
	return;
}
signed main()
{
	freopen("cell.in","r",stdin);
	freopen("cell.out","w",stdout);
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mp[i][j]=getchar();
			if(mp[i][j]=='C')
				nowc=i*ms+j;
			if(mp[i][j]=='F')
				f=i*ms+j;
		}
		while(ch!='\n')
			ch=getchar();
		ch='\0';
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//			printf("%c",mp[i][j]);
//		printf("\n");
//	}
	dfs(nowc,0,-1);
	if(vis[f])
		printf("%d",vis[f]);
	else
		puts("no");
	return 0;
}
