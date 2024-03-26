#include<bits/stdc++.h>
#define reg register int
#define oo 0x7f7f7f7f
#define ll long long
#define cl(x) memset(x, 0, sizeof(x));

struct qaq{
	int y, v, nt, x;
}e[600100], a[600100];
int lin[300100];
int li[300100];
int len = 0, le = 0;

int n, m;
int w[300100];
int dis[300100];
int father[300100];
int sum[300100];
int add[600100];
int val[300100];
std::vector<int> f[300100];
std::vector<int> f1[300100];
std::vector<int> f2[300100];
int ans[300100];
int q[300100];
bool vis[300100];
int tail, head;

inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

inline void insert(int x, int y) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
}

inline void inser(int x, int y) {
	a[++le].nt = li[x];
	li[x] = le;
	a[le].y = y;
	a[le].x = x;
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
			int fa = getfather(y);
			a[i].v = fa;
			if (i & 1) a[i + 1].v = a[i].v;
			else a[i - 1].v = a[i].v;
		}
	}
}

void init() {
	n = read(), m = read();
	for (reg i = 1; i < n; ++i) {
		int x = read();
		int y = read();
		insert(x, y);
		insert(y, x);
	}
	for (reg i = 1; i <= n; ++i) {
		father[i] = i;
		w[i] = read();
	}
	for (reg i = 1; i <= m; ++i) {
		int s = read();
		int t = read();
		inser(s, t);
		inser(t, s);
	}
}

void get_dis(int s) {
	dis[s] = 0;
	head = 1, tail = 0;
	q[++tail] = s;
	while (head <= tail) {
		int x = q[head++];
		vis[x] = 1;
		for (reg i = lin[x]; i; i = e[i].nt) {
			int y = e[i].y;
			if (!vis[y]) {
				q[++tail] = y;
				dis[y] = dis[x] + 1;
			}
		}
	}
}

void dfs(int x) {
	vis[x] = 1;
	int now = dis[x] + w[x];
	int temp = now <= n ? sum[now] : 0;
	for (reg i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!vis[y]) {
			dfs(y);
		}
	}
	sum[dis[x]] += val[x];
	if (now <= n) ans[x] += sum[now] - temp;
	for (reg i = 0, lmt = f[x].size(); i < lmt; ++i) --sum[dis[f[x][i]]];
}

void DFS(int x) {
	vis[x] = 1;
	int now = dis[x] - w[x];
	now += n;
	int temp = add[now];
	for (reg i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!vis[y]) {
			DFS(y);
		}
	}
	for (int i = 0, lmt = f1[x].size(); i < lmt; ++i) ++add[n + f1[x][i]];
	ans[x] += add[now] - temp;
	for (int i = 0, lmt = f2[x].size(); i < lmt; ++i) --add[n + f2[x][i]];
}

void solution() {
	for (reg i = 1; i <= m * 2; i += 2) {
		++val[a[i].x];
		f[a[i].v].push_back(a[i].x);
	}
	cl(vis);
	dfs(1);
	
	for (reg i = 1; i <= m * 2; i += 2) {
		int temp = dis[a[i].x] + dis[a[i].y] - (dis[a[i].v] << 1);
		f1[a[i].y].push_back(dis[a[i].y] - temp);
		f2[a[i].v].push_back(dis[a[i].y] - temp);
	}
	cl(vis);
	DFS(1);

	for (reg i = 1; i <= m * 2; i += 2) {
		if (dis[a[i].x] - dis[a[i].v] == w[a[i].v]) --ans[a[i].v];
	}
	for (reg i = 1; i < n; ++i) printf("%d ", ans[i]);
	printf("%d\n", ans[n]);
}

int main() {
	init();
	cl(vis);
	tarjan(1);
	cl(vis);
	get_dis(1);
	solution();
	return 0;
}
