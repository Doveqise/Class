using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>
#include <cassert>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
typedef complex<lf> com;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
struct _Main {
	/*void f(int arr[][][5]) {
	
	}*/
	int b[1000];
	_Main() {
		//int a[2][3][5];
		//f(a);
		memset(b, 0x3f, sizeof(b));
		memset(b, 192, sizeof(b));
		memset(b, -0x3f, sizeof(b));
		memset(b, -0x7f, sizeof(b));
		printf("%d", b[1]);
	}
	
	/*
	void martrix_mul(int a[5][5], int b[5][5]) {
		int ans[5][5];
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < 5; i++) {
			for (int k = 0; k < 5; k++) {
				for (int j = 0; j < 5; j++) {
					ans[i][j] += a[i][k] * b[k][j];
				}
			}
		}
	}
	*/
	
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}
