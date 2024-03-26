#include<bits/stdc++.h>
using namespace std;
int f[310][310];
int val[310];
int bro[310];
bool vis[310][310];
int chd[310];
int n, m;

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

void dfs(int x, int y) {
	if (vis[x][y]) return;
	vis[x][y] = 1;
	if (!x || !y) return;
	dfs(bro[x], y);
	f[x][y] = f[bro[x]][y];
	for (int i = 0; i < y; ++i) {
		dfs(bro[x], i);
		dfs(chd[x], y - i - 1);
		f[x][y] = max(f[x][y], f[bro[x]][i] + f[chd[x]][y - i - 1] + val[x]);
	} 
}

int main() {
	n = read();
	m = read();
	for (int i = 1; i <= n; ++i) {
		int x = read();
		int y = read();
		if (x == 0) x = n + 1;
		bro[i] = chd[x];
		chd[x] = i;
		val[i] = y;
	}
	dfs(chd[n + 1], m);
	printf("%d\n", f[chd[n + 1]][m]);
	return 0;
}
