#include <bits/stdc++.h>
using namespace std;
int n;
unsigned a[1048577];
unsigned b[1048577];
unsigned c[1048577];
unsigned d[1048577];
int main() {
	cin >> n;
	int m = 0;
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
			d[i & j] += a[i] * b[j];
		}
	}
	reverse(a, a + n);
	reverse(b, b + n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j >> i & 1) {
				a[j] += a[j ^ (1 << i)];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j >> i & 1) {
				b[j] += b[j ^ (1 << i)];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		c[i] = a[i] * b[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j >> i & 1) {
				c[j] -= c[j ^ (1 << i)];
			}
		}
	}
	reverse(c, c + n);
	for (int i = 0; i < n; i++) {
		cout << c[i] << ' ' << d[i] << endl;
	}
	return 0;
}
