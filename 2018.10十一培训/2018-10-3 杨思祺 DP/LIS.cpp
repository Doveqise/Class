#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;

int n, a[MAX_N], f[MAX_N], ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		f[i] = 1;
		for (int j = 0; j < i; ++j)
			if (a[i] > a[j])
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}
