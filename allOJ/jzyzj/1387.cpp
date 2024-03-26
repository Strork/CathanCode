#include<bits/stdc++.h>
#define mod 100000000
#define reg register int

using namespace std;

int f[13][1<<13];
bool a[13][13];
int b[13];
int n, m;
int ans = 0;

inline int read() {
	int k = 0, f = 1;
	char ch = getchar();
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

int main() {
	int ax = 2, 3;
	cout << ax << endl;
	n = read();
	m = read();
	int tot = (1 << m);
	for (reg i = 1; i <= n; ++i) {
		int t = m;
		for (reg j = 1; j <= m; ++j) {
			a[i][j] = read();
			if (a[i][j]) b[i] = b[i] | (1 << (t - 1));
			t--;
		}
	}
	f[0][0] = 1;
	for (reg i = 1; i <= n; ++i) {
		for (reg j = 0; j < tot; ++j) {
			if (j & (j << 1)) continue;
			if ((j | b[i]) != b[i]) continue;
			for (int k = 0; k < tot; ++k) {
				if (!(j & k)) f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
			}
		}
	}
	for (int i = 0; i < tot; ++i) {
		ans = (ans + f[n][i]) % mod;
	}
	cout << ans % mod << endl;
	return 0;
}


