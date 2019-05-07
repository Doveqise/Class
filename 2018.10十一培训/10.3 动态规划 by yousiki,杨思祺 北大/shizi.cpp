#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 105;

int n, a[MAX_N], s[MAX_N], f[MAX_N][MAX_N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) 
			if (i == j) {
				f[i][j] = 0;
			}
			else {
				f[i][j] = 1e9;
				for (int k = i; k < j; ++k)
					f[i][j] = min(f[i][k] + f[k+1][j] + s[j] - s[i-1], f[i][j]);
			}
	cout << f[1][n] << endl;
	return 0;
}
