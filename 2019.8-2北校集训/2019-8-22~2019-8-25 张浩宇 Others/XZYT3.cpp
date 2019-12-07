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
const lld MOD = 73939133;
const int MXN = 12;
struct _Main {
	int n, m, Qn;
	int mx;
	lld dp[MXN];
	char color[MXN];
	void dfs(int nd) {
		if (nd == n + 1) {
			++dp[mx];
			return;
		}
		for (int i = 1; i <= mx; i++) {
			char flag = 0;
			for (int e = head[nd], t; e; e = edge[e][NXT]) {
				if (color[t = edge[e][DST]] == i) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				color[nd] = i;
				dfs(nd + 1);
			}
		}
		color[nd] = ++mx;
		dfs(nd + 1);
		--mx;
		color[nd] = 0;
	}
	int head[MXN], edge[35][2], eidx;
	void add(int a, int b) {
		++eidx;
		edge[eidx][DST] = b;
		edge[eidx][NXT] = head[a];
		head[a] = eidx;
	}
	lld fastpower(lld base, lld pow) {
		lld ret = 1;
		while (pow) {
			if (pow & 1) ret = (ret * base) % MOD;
			if (pow >>= 1) base = (base * base) % MOD;
		}
		return ret;
	}
	lld com(int n, int m) {
		lld ret = n - m + 1;
		for (int i = n - m + 2; i <= n; i++) {
			ret = ret * i % MOD;
		}
		return ret;
	}
	void calc(int k) {
		lld ans = 0;
		for (int i = 1; i <= k && i <= n; i++) {
			ans = (ans + dp[i] * com(k, i)) % MOD;
		}
		printf("%lld\n", ans);
	}
	lld fact[11];
	lld factr[11];
	_Main() {
		read(n); read(m); read(Qn);
		for (int i = 1; i <= m; i++) {
			int u, v;
			read(u); read(v);
			add(u, v); add(v, u);
		}
		mx = 0;
		dfs(1);
		fact[0] = 1;
		for (int i = 1; i <= n; i++) {
			fact[i] = fact[i - 1] * i;
		}
		for (int i = 0; i <= n; i++) {
			factr[i] = fastpower(fact[i], MOD - 2);
		}
		for (int Q = 1, k; Q <= Qn; Q++) {
			read(k);
			calc(k);
		}
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
