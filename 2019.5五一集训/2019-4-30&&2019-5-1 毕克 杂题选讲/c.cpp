#include <bits/stdc++.h>
using namespace std;
long long a = -9223372036854775808;
//long long a = 1e18 + 21;
int mod = 1e9 + 7;
int main() {
	cout << -a << endl;
	cout << abs(a) << endl;
	return 0;
	long double rr = pow(2, 64);
	for (int i = -20; i <= 20; i++) {
		printf("%d %.0Lf\n", i, rr + i);
	}
	return 0;
	double r = pow(2, 53);
	for (int i = -20; i <= 20; i++) {
		printf("%d %.0f\n", i, r + i);
	}
	return 0;
	printf("%.0f\n", 3.5);
	printf("%.0f\n", 2.5);
	printf("%.0f\n", 1.5);
	printf("%.0f\n", 0.5);
	printf("%.0f\n", -0.5);
	printf("%.0f\n", -1.5);
	printf("%.0f\n", -2.5);
	printf("%.0f\n", -3.5);
	return 0;
	printf("%.77f\n", 0.1);
	printf("%.77f\n", 0.2);
	printf("%.77f\n", 0.1 + 0.2);
	printf("%.77f\n", 0.3);
	return 0;
	int n = 100;
	cout << fixed << setprecision(n) << pow(0.5, n) << endl;
	printf("%.*f\n", n, pow(0.5, n));
	return 0;
	printf("%.0Lf\n", pow(2.0L, 15000));
	return 0;
	double b = a;
	long double c = a;
	printf("%lld\n", a);
	printf("%.0f\n", b);
	printf("%.0f\n", sqrt(b));
	printf("%.60Lf\n", c);
	printf("%.60Lf\n", sqrt(c));
	printf("%.0f\n", 0.0);
	printf("%.0f\n", -0.0);
	printf("%d\n", (-0.0) == (0.0));
	return 0;
}
