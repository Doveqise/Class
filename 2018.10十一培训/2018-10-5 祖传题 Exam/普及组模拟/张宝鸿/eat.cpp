#include <fstream>
using namespace std;
ifstream fin("eat.in");
ofstream fout("eat.out");
long long n,k;
int main()
{
	fin>>n>>k;
	fout<<(n*2/k+(n*2%k==0?0:1))<<endl;
	return 0;
} 
