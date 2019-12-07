#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int inf = 1e9+7;
int lastans=0;
int fat[maxn];
struct QQ
{
	int fa,faval;
}
qq[maxn];
int findfa(int x)
{
	return fat[x]==x?x:fat[x]=findfa(fat[x]);
}
int pay_back(int a,int b,int num)
{
	if(findfa(a)!=findfa(b))
		return 0;
	if(qq[a].faval==0)
		return 0;
	if(qq[a].fa!=b)
		return pay_back(qq[a].fa,b,min(num,qq[qq[a].fa].faval));
	if(qq[a].fa==b)
		return num;
	
}
signed main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
		fat[i]=i;
	for(int i=1,opt;i<=m;i++)
	{
		scanf("%d",&opt);
		if(!opt)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			a = (a + lastans) % n + 1;
			b = (b + lastans) % n + 1;
			c = (c + lastans) % n + 1;
			fat[a]=findfa(b);
			qq[a].fa=b;
			qq[a].faval=c;
		}
		else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a = (a + lastans) % n + 1;
			b = (b + lastans) % n + 1;
			lastans=pay_back(a,b,qq[a].faval);
			printf("%d\n",lastans);
		}
	}
}
