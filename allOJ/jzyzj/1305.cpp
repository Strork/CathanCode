#include<bits/stdc++.h>
using std::cout;
using std::endl;
int val[510];
int bro[510];
int chd[510];
int f[510][510];
bool vis[510][510];
bool ans[510];
int n, m;

inline int read() {
	int k = 0;
	int f = 1;
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

void dfs(int x, int y) {
	if (vis[x][y]) return;
	vis[x][y] = 1;
	if (!x || !y) return;
	dfs(bro[x], y);
	f[x][y] = f[bro[x]][y];
	for (int i = 0; i < y; ++i) {
		dfs(bro[x], i);
		dfs(chd[x], y - i - 1);
		if (f[x][y] < f[bro[x]][i] + f[chd[x]][y - i - 1] + val[x])
			f[x][y] = f[bro[x]][i] + f[chd[x]][y - i - 1] + val[x];
	}
	//cout<<x<<' '<<y<<' '<<f[x][y]<<endl;
}

void path(int x, int y) {
	if (vis[x][y]) return;
	if (!x || !y) return;
	vis[x][y] = 1;
	if (f[x][y] == f[bro[x]][y]) {
		ans[x] = 0;
		path(bro[x], y);
	}
	for (int i = 0; i < y; ++i) {
		if (f[x][y] == f[bro[x]][i] + f[chd[x]][y - i - 1] + val[x]) {
			//cout<<x<<' '<<f[x][y]<<' '<<bro[x]<<' '<<chd[x]<<endl;
			ans[x] = 1;
			path(bro[x], i);
			path(chd[x], y - i - 1);
		}
	}
}

int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) {
		int x = read(), y = read();
		val[i] = y;
		if (x == 0) x = n + 1;
		bro[i] = chd[x];
		chd[x] = i;
	}
	//for (int i = 1; i <= n + 1; ++i) cout<<i<<' '<<chd[i]<<' '<<bro[i]<<endl;cout<<endl;
	dfs(chd[n + 1], m);
	printf("%d\n", f[chd[n + 1]][m]);
	memset(vis, 0, sizeof(vis));
	path(chd[n + 1], m);
	for (int i = 1; i <= n; ++i) if (ans[i]) printf("%d\n", i);
	return 0;
}
