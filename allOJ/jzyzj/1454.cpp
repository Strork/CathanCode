#include<bits/stdc++.h>
#define meset(x) memset(x, 0, sizeof(x));
#define ll long long
#define oo 0x7f7f7f7f
#define reg register int

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

struct tree{
	int y, v, nt;
}e[600100], a[600100];
int lin[300100];
int li[300100];
int len = 0;
int le = 0;

int st[300100];
int ed[300100];
int lca[300100];
bool vis[300100];
int q[300100];
int father[300100];
int val[300100];
int dis[300100];
int sum[300100];
int head, tail;
int n, m;

inline int getfather(int x) {
	int y = x;
	while (y != father[y]) y = father[y];
	while (x != y) {
		int fa = father[x];
		father[x] = y;
		x = fa;
	}
	return y;
}

inline void insert(int x, int y, int v) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
	e[len].v = v;
}

inline void inset(int x, int y) {
	a[++le].nt = li[x];
	li[x] = le;
	a[le].y = y;
}

void get_dis(int k) {
	meset(vis);
	dis[k] = 0;
	head = 1, tail = 0;
	q[++tail] = k;
	while (head <= tail) {
		int x = q[head++];
		vis[x] = 1;
		for (reg i = lin[x]; i; i = e[i].nt) {
			int y = e[i].y;
			if (!vis[y]) {
				q[++tail] = y;
				val[y] = e[i].v;
				dis[y] = dis[x] + e[i].v;
			}
		}
	}
}

void init() {
	n = read(), m = read();
	father[n] = n;
	for (reg i = 1; i < n; ++i) {
		int x = read(), y = read(), v = read();
		insert(x, y, v);
		insert(y, x, v);
		father[i] = i;
	}
	for (reg i = 1; i <= m; ++i) {
		st[i] = read();
		ed[i] = read();
		inset(st[i], ed[i]);
		inset(ed[i], st[i]);
	}
}

void tarjan(int x) {
	vis[x] = 1;
	for (int i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!vis[y]) {
			tarjan(y);
			father[y] = x;
		}
	}
	for (int i = li[x]; i; i = a[i].nt) {
		int y = a[i].y;
		if (vis[y]) {
			int fa = getfather(y);
			a[i].v = fa;
			if (i & 1) a[i + 1].v = a[i].v;
			else a[i - 1].v = a[i].v;
		}
	}
}

void dfs(int x) {
	vis[x] = 1;
	for (reg i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!vis[y]) {
			dfs(y);
			sum[x] += sum[y];
		}
	}
}

bool check(int k) {
	meset(sum);
	int longest = 0;
	int maxx = 0;
	int temp = 0;
	for (reg i = 1; i <= m; ++i) {
		int ds = dis[st[i]] + dis[ed[i]] - (dis[lca[i]] << 1);
		if (ds > k) {
			++temp;
			if (ds > longest) longest = ds;
			++sum[st[i]];
			++sum[ed[i]];
			sum[lca[i]] -= 2;
		}
	}
	meset(vis);
	dfs(1);
	for (reg i = 2; i <= n; ++i) {
		if (sum[i] >= temp) {
			if (val[i] > maxx) {
				maxx = val[i];
			}
		}
	}
	if (longest - maxx > k) return 0;
	return 1;
}

void solution() {
	int l = 0, r = 300000000;
	int mid;
	for (reg i = 2; i <= (m << 1); i += 2) lca[i >> 1] = a[i].v;
	while (l + 1 < r) {
		//printf("%d\n", r);
		mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid;
	}
	if (check(l)) printf("%d\n", l);
	else printf("%d\n", r);
}

int main() {
	//freopen("a.txt", "r", stdin);
	int __size__ = 20 << 20; // 20MB
char *__p__ = (char*)malloc(__size__) + __size__;
__asm__("movl %0, %%esp\n" :: "r"(__p__));
	init();
	get_dis(1);
	meset(vis);
	tarjan(1);
	solution();
	return 0;
}
