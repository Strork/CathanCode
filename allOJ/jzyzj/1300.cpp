#include<bits/stdc++.h>
#define ll long long
ll f[50][50];
int a[50];
int fa[50][50];
int n;

void find(int x, int y) {
	if (x <= y) {
		printf("%d ", fa[x][y]);
		find(x, fa[x][y] - 1);
		find(fa[x][y] + 1, y);
	}
}

void solution() {
	for (int p = 1; p <= n; ++p) {
		for (int i = 1; i <= n; ++i) {
			int j = i + p;
			if (j > n) break;
			f[i][j] = 0;
			for (int k = i; k <= j; ++k) {
				if (f[i][j] < f[i][k - 1] * f[k + 1][j] + a[k]) {
					f[i][j] = f[i][k - 1] * f[k + 1][j] + a[k];
					fa[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", f[1][n]);
	find(1, n);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= n + 1; ++j) {
			f[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		f[i][i] = a[i];
		fa[i][i] = i;
	}
	solution();
	return 0;
}
