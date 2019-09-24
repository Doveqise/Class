#include <bits/stdc++.h>
using namespace std;
int n, q, x;
unsigned a[1048577];
unsigned b[1048577];
unsigned c[1048577];
unsigned d[1048577];
int main() {
	cin >> n >> q;
	int m = 20;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 1 << m; j++) {
			if (j >> i & 1) {
				a[j] += a[j ^ (1 << i)];
			}
		}
	}
	for (int i = 0; i < 1 << m; i++) {
		a[i] = a[i] * (a[i] - 1) / 2;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 1 << m; j++) {
			if (j >> i & 1) {
				a[j] -= a[j ^ (1 << i)];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 1 << m; j++) {
			if (j >> i & 1) {
				a[j ^ (1 << i)] += a[j];
			}
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> x;
		cout << a[x] << endl;
	}
	return 0;
}
