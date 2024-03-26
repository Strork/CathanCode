#include<bits/stdc++.h>
#define reg register int
#define up(i,j,k)		for (reg i = j; i <= k; ++i)
#define down(i,j,k)		for (reg i = j; i >= k; --i)
#define ll long long

using namespace std;

int n, m;
ll f[10][1 << 10][85];
int a[1 << 10];

void pre() {
	up(i, 0, (1 << n) - 1) {
		int temp = i;
		while (temp) {
			if (temp & 1) ++a[i];
			temp >>= 1;
		}
	}
	up(i, 0, (1 << n) - 1) {
		if (i & (i << 1)) continue;
		f[1][i][a[i]] = 1;
	}
}

int main() {
	cin >> n >> m;
	pre();
	up(i, 2, n) {
		up(j, 0, (1 << n) - 1) {
			if (j & (j << 1)) continue;
			up(k, 0, (1 << n) - 1) {
				if (j & k) continue;
				if ((j << 1) & k) continue;
				if (j & (k << 1)) continue;
				down(x, m, a[j]) f[i][j][x] += f[i - 1][k][x - a[j]];
			}
		}
	}
	ll ans = 0;
	up(i, 0, (1 << n) - 1) ans += f[n][i][m];
	cout << ans << endl;
	return 0;
}
