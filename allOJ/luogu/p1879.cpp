#include<bits/stdc++.h>
#define mod 100000000
#define up(i,j,n)   for (register int i = j; i <= n; ++i)
#define down(i,j,n) for (register int i = j; i >= n; --i)
#define add(x,y) x = (x + y) % mod;

using namespace std;
int f[13][1<<13];
int n, m;
int x[13];

int main() {
	cin >> n >> m;
	up(i, 1, n) {
		up(j, 1, m) {
			int temp;
			scanf("%d", &temp);
			x[i] |= temp;
			x[i] <<= 1;
		}
		x[i] >>= 1;
	}
	f[0][0] = 1;
	int lmt = (1 << m);
	up(i, 1, n) {
		up(j, 0, lmt - 1) {
			if (j & (j << 1)) continue;
			if ((j & x[i]) != j) continue;
			up(k, 0, lmt - 1) {
				if (!(j & k)) add(f[i][j], f[i - 1][k]);
			}
		}
	}
	int ans = 0;
	up(i, 0, lmt - 1) add(ans, f[n][i]);
	cout << ans % mod << endl;
	//cout << x[1] << endl;
	return 0;
}

