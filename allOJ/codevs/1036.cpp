#include<bits/stdc++.h>
#define reg register int

struct qaq{
	int y, nt, v, x;
}e[60100];
int lin[30100];
int len = 0;
qaq a[100100];
int li[100100];
int le = 0;

int n, m;
bool vis[30100];
int dis[30010];
int q[30010];
int head, tail;
int father[30100];

inline void insert(int x, int y) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
}

inline void inset(int x, int y) {
	a[++le].nt = li[x];
	li[x] = le;
	a[le].y = y;
	a[le].x = x;
}

inline int getfather(int x) {
	int y = x;
	while (y != father[y]) 
		y = father[y];
	while (x != y) {
		int fa = father[x];
		father[x] = y;
		x = fa;
	}
	return y;
}

void init() {
	scanf("%d", &n);
	father[n] = n;
	for (reg i = 1; i < n; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		insert(x, y);
		insert(y, x);
		father[i] = i;
	}
	scanf("%d", &m);
	int x = 1;
	for (reg i = 1; i <= m; ++i) {
		int y;
		scanf("%d", &y);
		inset(x, y);
		inset(y, x);
		x = y;
	}
}

void tarjan(int x) {
	vis[x] = 1;
	for (reg i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!vis[y]) {
			tarjan(y);
			father[y] = x;
		}
	}
	for (reg i = li[x]; i; i = a[i].nt) {
		int y = a[i].y;
		if (vis[y]) {
			a[i].v = getfather(y);
			if (i & 1) a[i + 1].v = a[i].v;
			else a[i - 1].v = a[i].v;
		}
	}
}

void bfs(int k) {
	memset(vis, 0, sizeof(vis));
	head = 1, tail = 0;
	q[++tail] = k;
	dis[k] = 0;
	while (head <= tail) {
		int x = q[head++];
		vis[x] = 1;
		for (reg i = lin[x]; i; i = e[i].nt) {
			int y = e[i].y;
			if (!vis[y]) {
				dis[y] = dis[x] + 1;
				q[++tail] = y;
			}
		}
	}
}

void solution() {
	int ans = 0;
	for (reg i = 1; i <= le; i += 2) {
		int lca = a[i].v;
		int x = a[i].x;
		int y = a[i].y;
		ans += dis[x] + dis[y] - (dis[lca] << 1);
	}
	printf("%d\n", ans);
}

int main() {
	init();
	tarjan(1);
	bfs(1);
	solution();
	return 0;
}
