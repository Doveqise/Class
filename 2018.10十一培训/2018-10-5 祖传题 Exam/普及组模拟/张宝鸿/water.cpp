#include <fstream>
#include <queue>
using namespace std;
int data[505][505];//data[杯子一中的水][杯子二中的水]=到当前状态的最少步 
int a,b,c;
struct state
{
	int cupa;
	int cupb;
};
queue<state> q;
state temp,temp2;
ifstream fin("water.in");
ofstream fout("water.out");
void pour(int &ca,int &cb,const int a,const int b)
{
	if(ca+cb>a)
	{
		cb-=a-ca;
		ca=a;
	}
	else
	{
		ca+=cb;
		cb=0;
	}
}
int bfs()
{
	int deepth=1;
	while(!q.empty())
	{
		for(register int i=q.size();i>0;--i)
		{
			temp=q.front();
			q.pop();
			if(temp.cupa==c||temp.cupb==c)
				return deepth-1;
			if(!data[temp.cupa][temp.cupb])
				data[temp.cupa][temp.cupb]=deepth;
			else
				continue;
			temp2=temp;
			
			temp2.cupb=b;
				q.push(temp2);
				
			temp2.cupb=0;
				q.push(temp2);
			temp2.cupb=temp.cupb;
			
			temp2.cupa=a;
				q.push(temp2);
				
			temp2.cupa=0;
				q.push(temp2);
			temp2.cupa=temp.cupa;
			{
				pour(temp2.cupa,temp2.cupb,a,b);
				q.push(temp2);
				temp2=temp;
				pour(temp2.cupb,temp2.cupa,b,a);
				q.push(temp2);
			}
		}
		deepth++;
	}
	return -1;
}//-std=c++11
int main()
{
	fin>>a>>b>>c;
	temp.cupa=0;
	temp.cupb=0;
	q.push(temp);
	int ans=bfs();
	if(ans==-1)
		fout<<"impossible"<<endl;
	else
		fout<<ans<<endl;
	return 0;
} 
