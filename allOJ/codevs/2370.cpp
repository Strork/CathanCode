#include<bits/stdc++.h>
#define ll long long
#define reg register int
#define oo 0x7f7f7f7f

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

struct qaq{
	int y, v, nt, x;
}tree[101000], e[151000];
int Len = 0, len = 0;
int lin[50100], Lin[75100];

int n, m;
int father[50100];
bool vis[50100];
int dis[50100];
int q[50100];
int head, tail;

inline void insert(int x, int y, int v) {
	tree[++len].nt = lin[x];
	lin[x] = len;
	tree[len].y = y;
	tree[len].v = v;
}

inline void Insert(int x, int y) {
	e[++Len].nt = Lin[x];
	Lin[x] = Len;
	e[Len].y = y;
	e[Len].x = x;
} 

inline int getfather(int x) {
	int y = x;
	while (father[y] != y) y = father[y];
	while (x != y) {
		int fa = father[x];
		father[x] = y;
		x = fa;
	}
	return y;
}

void dfs(int x) {
	vis[x] = 1;
	for (reg i = lin[x]; i; i = tree[i].nt) {
		int y = tree[i].y;
		if (!vis[y]) {
			dfs(y);
			father[y] = x;
		}
	}
	for (reg i = Lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (vis[y]) {
			e[i].v = getfather(y);
			if (i & 1) e[i + 1].v = e[i].v;
			else e[i - 1].v = e[i].v;
		}
	}
}

void bfs(int st) {
	memset(vis, 0, sizeof(vis));
	int head = 1, tail = 0;
	q[++tail] = st;
	dis[st] = 0;
	while (head <= tail) {
		int x = q[head++];
		//if (vis[x]) continue;
		vis[x] = 1;
		for (reg i = lin[x]; i; i = tree[i].nt) {
			int y = tree[i].y;
			if (!vis[y]) {
				dis[y] = dis[x] + tree[i].v;
				q[++tail] = y;
			}
		}
	}
}

void init() {
	n = read();
	father[0] = 0;
	for (reg i = 1; i < n; ++i) {
		int x = read();
		int y = read();
		int v = read();
		insert(x, y, v);
		insert(y, x, v);
		father[i] = i;
	}
	m = read();
	for (reg i = 1; i <= m; ++i) {
		int x = read();
		int y = read();
		Insert(x, y);
		Insert(y, x);
	}
}

int main() {
	init();
	dfs(0);
	bfs(0);
	for (int i = 1; i <= (m << 1); i += 2) {
		int x = e[i].x;
		int y = e[i].y;
		//printf("%d\n", getfather(x));
		int ans = dis[x] + dis[y] - (dis[e[i].v] << 1);
		printf("%d\n", ans);
	}
	return 0;
}
