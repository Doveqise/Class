#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;
const int MAX_M = 1005;

int n, m, w[MAX_N], v[MAX_N], f[MAX_M];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> w[i] >> v[i];
	for (int i = 0; i < n; ++i)
		for (int j = m; j >= w[i]; --j)
			f[j] = max(f[j], f[j - w[i]] + v[i]);
	cout << f[m] << endl;
	return 0;
}
