#include<windows.h>
using namespace std;
int main(){
	int i=200;
	while(i++){
		Beep(i,300);
		Sleep(300);
	}
	return 0;
}
