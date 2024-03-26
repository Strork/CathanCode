#include<bits/stdc++.h>
#define ll long long
#define oo 0x7f7f7f7f
#define reg register int

int n, m;
ll a[15][15];
ll maxn;
ll f[15][1<<12];
ll ans = oo;
ll g[1<<12][1<<12];
ll c[15][1<<12];

inline int read() {
	char ch = getchar();
	int k = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return k * f;
}

void init() {
	memset(a, 0x7f, sizeof(a));
	memset(c, 0x7f, sizeof(c));
	memset(f, 0x7f, sizeof(f));
	n = read();
	m = read();
	for (reg i = 1; i <= m; ++i) {
		int x = read(), y = read(), v = read();
		if (v < a[x][y]) {
			a[x][y] = v;
			a[y][x] = v;
		}
	}
}

void work() {
	for (int i = 1; i <= n; ++i) {
		for (int k = 1; k <= maxn; ++k) {
			if (!(k & (1 << (i - 1)))) {
				for (int j = 1; j <= n; ++j) {
					if (k & (1 << (j - 1))) 
						c[i][k] = std::min(c[i][k], a[i][j]);
				}
			}
		}
	}
	for (int s = 1; s <= maxn; ++s) {
		for (int t = s; t; t = s & (t - 1)) {//t belong s
			int x = s ^ t; // x : t -> s point
			for (int i = 1; i <= n; ++i) {
				if (x & (1 << (i - 1))) {
					g[t][s] += c[i][t];
					if (g[t][s] > oo) g[t][s] = oo;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		f[1][1 << (i - 1)] = 0;
	}
	for (int i = 2; i <= n; ++i) {
		for (int s = 1; s <= maxn; ++s) {
			for (int t = s; t; t = (t - 1) & s) {
				int temp;
				if (g[t][s] < oo) temp = g[t][s] * (i - 1);
				else temp = oo;
				if (f[i - 1][t] < oo)
					f[i][s] = std::min(f[i - 1][t] + temp, f[i][s]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) 
		ans = std::min(f[i][maxn], ans);
	printf("%d\n", ans);
}

int main() {
	init();
	maxn = (1 << n) - 1;
	work();
	return 0;
}
