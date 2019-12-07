#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int a[20];
int dp[35][15][3][2][2][2][2][2][2][2][2][2][2][2][2][3][3];
int k,tot;
int dfs(int rem,int now,int col1,int col2,int col3,int col4,int col5,int col6,int col7,int col8,int col9,int col10,int col11,int col12,int col13,int col14,int col15)
{
	int ret=0;
	if(rem==0)
		return 1;
	if(dp[rem][now][col1][col2][col3][col4][col5][col6][col7][col8][col9][col10][col11][col12][col13][col14][col15]&&col1<=1&&col2<=1&&col3<=1&&col4<=1&&col5<=1&&col6<=1&&col7<=1&&col8<=1&&col9<=1&&col10<=1&&col11<=1&&col12<=1&&col13<=1&&col14<=2&&col15<=2)
		return dp[rem][now][col1][col2][col3][col4][col5][col6][col7][col8][col9][col10][col11][col12][col13][col14][col15];
	if(now!=1&&col1!=0)ret=(ret+(dp[rem-1][1][col1-1][col2][col3][col4][col5][col6][col7][col8][col9][col10][col11][col12][col13][col14][col15]=dfs(rem-1,1,col1-1,col2,col3,col4,col5,col6,col7,col8,col9,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=2&&col2!=0)ret=(ret+(dp[rem-1][2][col1][col2-1][col3][col4][col5][col6][col7][col8][col9][col10][col11][col12][col13][col14][col15]=dfs(rem-1,2,col1,col2-1,col3,col4,col5,col6,col7,col8,col9,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=3&&col3!=0)ret=(ret+(dp[rem-1][3][col1][col2][col3-1][col4][col5][col6][col7][col8][col9][col10][col11][col12][col13][col14][col15]=dfs(rem-1,3,col1,col2,col3-1,col4,col5,col6,col7,col8,col9,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=4&&col4!=0)ret=(ret+(dp[rem-1][4][col1][col2][col3][col4-1][col5][col6][col7][col8][col9][col10][col11][col12][col13][col14][col15]=dfs(rem-1,4,col1,col2,col3,col4-1,col5,col6,col7,col8,col9,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=5&&col5!=0)ret=(ret+(dp[rem-1][5][col1][col2][col3][col4][col5-1][col6][col7][col8][col9][col10][col11][col12][col13][col14][col15]=dfs(rem-1,5,col1,col2,col3,col4,col5-1,col6,col7,col8,col9,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=6&&col6!=0)ret=(ret+(dp[rem-1][6][col1][col2][col3][col4][col5][col6-1][col7][col8][col9][col10][col11][col12][col13][col14][col15]=dfs(rem-1,6,col1,col2,col3,col4,col5,col6-1,col7,col8,col9,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=7&&col7!=0)ret=(ret+(dp[rem-1][7][col1][col2][col3][col4][col5][col6][col7-1][col8][col9][col10][col11][col12][col13][col14][col15]=dfs(rem-1,7,col1,col2,col3,col4,col5,col6,col7-1,col8,col9,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=8&&col8!=0)ret=(ret+(dp[rem-1][8][col1][col2][col3][col4][col5][col6][col7][col8-1][col9][col10][col11][col12][col13][col14][col15]=dfs(rem-1,8,col1,col2,col3,col4,col5,col6,col7,col8-1,col9,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=9&&col9!=0)ret=(ret+(dp[rem-1][9][col1][col2][col3][col4][col5][col6][col7][col8][col9-1][col10][col11][col12][col13][col14][col15]=dfs(rem-1,9,col1,col2,col3,col4,col5,col6,col7,col8,col9-1,col10,col11,col12,col13,col14,col15)))%mod;
	if(now!=10&&col10!=0)ret=(ret+(dp[rem-1][10][col1][col2][col3][col4][col5][col6][col7][col8][col9][col10-1][col11][col12][col13][col14][col15]=dfs(rem-1,10,col1,col2,col3,col4,col5,col6,col7,col8,col9,col10-1,col11,col12,col13,col14,col15)))%mod;
	if(now!=11&&col11!=0)ret=(ret+(dp[rem-1][11][col1][col2][col3][col4][col5][col6][col7][col8][col9][col10][col11-1][col12][col13][col14][col15]=dfs(rem-1,11,col1,col2,col3,col4,col5,col6,col7,col8,col9,col10,col11-1,col12,col13,col14,col15)))%mod;
	if(now!=12&&col12!=0)ret=(ret+(dp[rem-1][12][col1][col2][col3][col4][col5][col6][col7][col8][col9][col10][col11][col12-1][col13][col14][col15]=dfs(rem-1,12,col1,col2,col3,col4,col5,col6,col7,col8,col9,col10,col11,col12-1,col13,col14,col15)))%mod;
	if(now!=13&&col13!=0)ret=(ret+(dp[rem-1][13][col1][col2][col3][col4][col5][col6][col7][col8][col9][col10][col11][col12][col13-1][col14][col15]=dfs(rem-1,13,col1,col2,col3,col4,col5,col6,col7,col8,col9,col10,col11,col12,col13-1,col14,col15)))%mod;
	if(now!=14&&col14!=0)ret=(ret+(dp[rem-1][14][col1][col2][col3][col4][col5][col6][col7][col8][col9][col10][col11][col12][col13][col14-1][col15]=dfs(rem-1,14,col1,col2,col3,col4,col5,col6,col7,col8,col9,col10,col11,col12,col13,col14-1,col15)))%mod;
	if(now!=15&&col15!=0)ret=(ret+(dp[rem-1][15][col1][col2][col3][col4][col5][col6][col7][col8][col9][col10][col11][col12][col13][col14][col15-1]=dfs(rem-1,15,col1,col2,col3,col4,col5,col6,col7,col8,col9,col10,col11,col12,col13,col14,col15-1)))%mod;
	return ret;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		scanf("%d",&k);
		memset(a,0,sizeof(a));
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
			tot+=a[i];
		}
		sort(a+1,a+16);
		int clc=clock();
		int ans=0;
		ans=dfs(tot,0,a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10],a[11],a[12],a[13],a[14],a[15])%mod;
		printf("%d\n",ans);
		//printf("Time:%dms\n",(clock()-clc)*CLOCKS_PER_SEC);
	}
}
