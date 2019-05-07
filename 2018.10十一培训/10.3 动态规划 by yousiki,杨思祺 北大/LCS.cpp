#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;

int n, m, a[MAX_N], b[MAX_N], f[MAX_N][MAX_N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	cin >> m;
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j])
				f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
			f[i][j] = max(f[i][j], f[i - 1][j]);
			f[i][j] = max(f[i][j], f[i][j - 1]);
		}
	cout << f[n][m] << endl;
	return 0;
}
