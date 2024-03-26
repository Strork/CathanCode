#include<bits/stdc++.h>
using std::cout;
using std::endl;
int f[1600];
int g[1600];
int n;
struct qaq {
	int y, nt;
}e[20100];
int lin[1600];
int len = 0;
bool leaf[1600];
bool vis[1600];

inline int read() {
	char ch = getchar();
	int f = 1;
	int k = 0;
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

inline void insert(int x, int y) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
}

void buildtree(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	bool flag = 0;
	for (int i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!vis[y]) {
			flag = 1;
			buildtree(y);
		}
	}
	if (!flag) leaf[x] = 1;
}

void dfs(int x) {
	if (vis[x]) return;
	vis[x] = 1;
	if (leaf[x]) {
		f[x] = 1;
		g[x] = 0;
		return;
	}
	for (int i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!vis[y]) {
			dfs(y);
			g[x] += f[y];
			f[x] += std::min(f[y], g[y]);
		}
	}
	++f[x];
}

int main() {
	n = read();
	for (int i = 1; i <= n; ++i) {
		int x = read();
		int t = read();
		while (t--) {
			int y = read();
			insert(x, y);
			insert(y, x);
		}
	}
	memset(vis, 0, sizeof(vis));
	buildtree(1);
	memset(vis, 0, sizeof(vis));
	dfs(1);
	printf("%d\n", std::min(f[1], g[1]));
	return 0;
}
