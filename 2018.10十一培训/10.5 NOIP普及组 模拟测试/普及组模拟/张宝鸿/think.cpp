#include <fstream>
using namespace std;
int arr[20005];
int s[20005];
int n,h;
ifstream fin("think.in");
ofstream fout("think.out");
int main()
{
	fin>>n;
	arr[0]=arr[1]=1;
	for(register int i=2;i<=n;++i)
	{
		for(register int f=2;f<=i;++f)
		{
			arr[i*f]=1;
		}
	}
	for(register int i=3;i<=n-i;++i)
	{
		if(!arr[i])
		{
			s[h++]=i;
			if(!arr[n-i])
				fout<<i<<' '<<n-i<<endl;
		}
	}
	return 0;
}
