#include<bits/stdc++.h>
#define ll long long
#define reg register int

int n;
double f[200010];
int c[200010];
int t[200010];
int f0;

double dfs(int k) {
	if (f[k] > 0) return f[k];
	for (reg i = 1; i <= n; ++i) {
		if (k > c[i]) f[k] += 1.0 * t[i];
		else f[k] += dfs(k + c[i]) + 1.0;
	}
	f[k] /= 1.0 * n;
	return f[k];
}

int main() {
	while (~scanf("%d %d", &n, &f0)) {
		memset(f, 0, sizeof(f));
		for (reg i = 1; i <= n; ++i) {
			scanf("%d", &c[i]);
			t[i] = (int)((1.0 + std::sqrt(5.0)) / 2.0 * c[i] * c[i]);
		}
		dfs(f0);
		printf("%.3lf\n", f[f0]);
	}
	return 0;
}
