#include<bits/stdc++.h>
#define mod 10000
using namespace std;
int a[10100];
int b[10100];
int p[10100];
int q[10100];
int temp[10100];
int n;
int m;
int tail = 0;

int fastpower(int x, int y) {
	int t = 1;
	while (y) {
		if (y & 1) t = t * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return t;
}

int main() {
	scanf("%d", &n);
	m = 1;
	for (int i = 1; i <= n; ++i) scanf("%d%d", &p[i], &q[i]);
	for (int i = 1; i <= n; ++i) {
		m = m * fastpower(p[i], q[i]) % mod;
		if (p[i] != 2) temp[++tail] = p[i];
	}
	a[1] = temp[1] - 1;
	b[1] = 1;
	for (int i = 2; i <= tail; ++i) {
		a[i] = (a[i - 1] + b[i - 1] * (temp[i] - 1)) % mod;
		b[i] = (b[i - 1] + a[i - 1] * (temp[i] - 1)) % mod;
	}
	b[tail] -= 1;
	printf("%d\n",(mod + b[tail]) % mod);
	printf("%d\n",(mod + a[tail]) % mod);
	printf("%d\n",(mod + mod + (m - 1) - a[tail] - b[tail]) % mod);
	return 0;
}
