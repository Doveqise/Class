#include <fstream>
using namespace std;
int dp[3000][3000];//�߶�Ϊ�� 
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
		for(register int i=0;i<n;++i)//ͬһ�����ϣ�������ϵ��²��������Դ�ͬһ����k�߶��Ϸ�ת�Ʋ���ȴ�1�߶��Ϸ�ת�Ƹ��š������Բ���������һ���½�kò�Ʋ��ÿ��ǣ��� 
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
