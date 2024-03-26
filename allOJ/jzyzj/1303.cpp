#include<bits/stdc++.h>
using namespace std;
struct qaq {
	int lc, rc;
}tree[110];
bool vis[110];
int a[110][110];
int f[110][110];
int val[110];
int n, q;

void get_tree(int k) {
	if (vis[k]) return;
	vis[k] = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[k][i] != -1 && !vis[i]) {
			if (!tree[k].lc) {
				tree[k].lc = i;
				val[i] = a[k][i];
				get_tree(i);
			}
			else {
				tree[k].rc = i;
				val[i] = a[k][i];
				get_tree(i);
			}
		}
	}
}

void dfs(int x, int k) {
	if (k == 0) {
		f[x][k] = 0;
		return;
	}
	if (!tree[x].lc && !tree[x].rc) {
		f[x][k] = val[x];
		return;
	}
	for (int i = 0; i < k; ++i) {
		if (f[tree[x].lc][i] == 0) dfs(tree[x].lc, i);
		if (f[tree[x].rc][k - i - 1] == 0) dfs(tree[x].rc, k - i - 1);
		f[x][k] = max(f[x][k], f[tree[x].lc][i] + f[tree[x].rc][k - i - 1] + val[x]);
	}
}

int main() {
	memset(a, -1, sizeof(a));
	scanf("%d %d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int x, y, v;
		scanf("%d %d %d", &x, &y, &v);
		a[x][y] = a[y][x] = v;
	}
	get_tree(1);
	dfs(1, q + 1);
	printf("%d\n", f[1][1 + q]);
	return 0;
}


