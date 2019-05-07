#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1048577];
long long b[1048577];
long long c[1048577];
long long d[1048577];
int m;
void fwt(long long a[]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j >> i & 1) {
				long long u = a[j ^ (1 << i)] + a[j];
				long long v = a[j ^ (1 << i)] - a[j];
				a[j ^ (1 << i)] = u;
				a[j] = v;
			}
		}
	}
}
int main() {
	cin >> n;
	while (1 << m < n) {
		m++;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i ^ j] += a[i] * b[j];
		}
	}
	fwt(a);
	fwt(b);
	for (int i = 0; i < n; i++) {
		c[i] = a[i] * b[i];
	}
	fwt(c);
	for (int i = 0; i < n; i++) {
		cout << c[i] / n << ' ' << d[i] << endl;
	}
	return 0;
}
