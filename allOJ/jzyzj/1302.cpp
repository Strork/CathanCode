#include<bits/stdc++.h>
using std::cout;
using std::endl;
int fa[100100];
int lin[100100];
struct qaq {
	int y, nt;
}e[200100];
int len = 0;
int val[100100];
int n;
bool vis[100100];
bool lef[100100];
int f[100100];
int g[100100];

inline int read() {
	int k = 0;
	char ch = getchar();
	int f = 1;
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

void insert(int x, int y) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
}

void build_tree(int x) {
	if (vis[x]) return;
	//f[x] = val[x];
	vis[x] = 1;
	bool flag = 1;
	for (int i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!vis[y]) {
			fa[y] = x;
			flag = 0;
			build_tree(y);
		}
	}
	if (flag) lef[x] = 1;
}

void dfs(int x) {
	if (lef[x]) {
		f[x] = val[x];
		g[x] = 0;
		return;
	}
	for (int i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (fa[y] == x) {
			dfs(y);
			f[x] += g[y];
			g[x] += std::max(f[y], g[y]);
		}
	}
	f[x] += val[x];
}

int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) val[i] = read();
	for (int i = 1; i < n; ++i) {
		int x = read();
		int y = read();
		insert(x, y);
		insert(y, x);
	}
	build_tree(1);
	//for (int i = 1; i <= n; ++i) cout<<val[i]<<' ';cout<<endl;
	dfs(1);
	printf("%d\n", std::max(g[1], f[1]));
	return 0;
}
