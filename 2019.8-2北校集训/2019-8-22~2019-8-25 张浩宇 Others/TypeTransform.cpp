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
template <typename Type>
	int Print(Type a) {
		printf("%s\n", a);
		return a;
	}
struct _Main {
	_Main() {
		float a;
		double b;
		long double c;
		
		char d;
		short e;
		int f;
		long long g;
		__int128 h;
		
		unsigned char i;
		unsigned short j;
		unsigned k;
		unsigned long long l;
		unsigned __int128 m;
		
		complex<float> n;
		complex<double> o;
		complex<long double> p;
		
		complex<int> q;
		complex<unsigned> r;
		u t = 1u + (-2);
		printf("%u", t);	
//		Print(m + h);
	}
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
