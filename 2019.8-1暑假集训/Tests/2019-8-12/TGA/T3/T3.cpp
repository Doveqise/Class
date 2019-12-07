#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+5;
int a[maxn][maxn],tong[maxn],num[maxn],id[maxn],vis[maxn];
char ch[maxn];
int n,ans = 0;
bool cmp(int a,int b)
{
	return num[a]>num[b];
}
void solve(int x)
{
	int maxx=0,maxt=0;
	for(int i=1;i<=n;i++)
	{
		if(tong[i]>=maxx&&!vis[i]&&a[x][i])
		{
			maxt=i;
			maxx=tong[i];
		}
	}
	vis[maxt]=1;
	for(int i=1;i<=n;i++)
		tong[i]-=a[x][i];
	if(!maxt)
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				ans++;
				vis[i]=1;
				break;	
			}
	return;
}			
signed main()
{
	freopen("factory.in","r",stdin);
	freopen("factory.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		id[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		int len=strlen(ch+1);
		for(int j=1;j<=len;j++)
			a[i][j]=ch[j]-'0';
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{
				tong[j]+=a[i][j];
				num[i]+=a[i][j];
			}
	sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(!num[i])
		{
			ans+=n-i+1;
			break;
		}
		solve(id[i]);
	}
		
	printf("%d\n",ans);
	return 0;
}
