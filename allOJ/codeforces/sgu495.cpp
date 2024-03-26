#include<bits/stdc++.h>
#define ll long long
#define reg register int

double f[100100];
int n, m;

int main() {
	f[1] = 1.0;
	scanf("%d %d", &n, &m);
	for (reg i = 2; i <= m; ++i) {
		f[i] = (double(n) - f[i - 1]) / double(n) + f[i - 1];
	}
	printf("%.10lf\n", f[m]);
	return 0;
}
