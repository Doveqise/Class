#include <fstream>
using namespace std;
int dp[3000][3000];//高度为序 
int arr[2005][2005];
int n,h,k;
int t;
ifstream fin("cat.in");
ofstream fout("cat.out");
int main()
{
	fin>>n>>h>>k;
	//dp[h][i]=max(dp[h+k][0-n(not i)],dp[h+1][i]);
	//dp[h][0-n]=arr[h][0-n];
	for(register int i=0;i<n;++i)
	{
		fin>>t;
		for(register int f=t;f>0;--f)
		{
			fin>>t;
			arr[t][i]++;
			//arr[t][n+1]=max(arr[t][n+1],arr[t][i]);
		}
	}
	for(register int f=h;f>=0;--f)
	{
		for(register int i=0;i<n;++i)//同一棵树上，收益从上到下不减，所以从同一棵树k高度上方转移不会比从1高度上方转移更优。（所以不能沿着树一次下降k貌似不用考虑？） 
		{
			dp[f][i]=max(dp[f+k][n+1],dp[f+1][i])+arr[f][i];
			dp[f][n+1]=max(dp[f][n+1],dp[f][i]);
		}
	}
	/*t=0;
	for(register int i=0;i<n;++i)
		t=max(t,dp[0][i]);*/
	fout<<dp[0][n+1]<<endl;
	return 0;
} 

/*
3 10 2
3 1 4 10
6 3 5 9 7 8 9
5 4 5 3 6 9
*/
