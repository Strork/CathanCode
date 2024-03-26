#include<bits/stdc++.h>
#define ll long long
#define oo 0x7f7f7f7f
#define reg register int
#define up(i,j,k)	for (int i = j; i <= k; ++i)
#define down(i,j,k)	for (int i = j; i >= k; --i)

using namespace std;

struct qaq {
	int y, v, flow;
	int nt, rev;
}e[1001000];
int lin[1010];
int len = 0;
int q[10100];
int head, tail;
int vis[1010];
int edge[1010], node[1010];
int dis[1010];
int n, m;
int st, ed;

char buf[1<<15], *fs, *ft;
inline char getc() {
	return (fs==ft && (ft = (fs = buf) + fread(buf, 1, 1<<15, stdin), fs==ft)) ? 0 : *fs++;
}
inline int read() {
	char ch = getc();
	int f = 1, k = 0;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getc();
	}
	while (isdigit(ch)) {
		k = k * 10 + ch - '0';
		ch = getc();
	}
	return k * f;
}

inline void insert(int x, int y, int v, int flow, int k) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
	e[len].v = v;
	e[len].flow = flow;
	e[len].rev = len + k;
}

void init() {
	n = read(), m = read();
	up(i, 2, n - 1) {
		insert(i, i + n, 0, 1, 1);
		insert(i + n, i, 0, 0, -1);
	}
	insert(1, 1 + n, 0, oo, 1);
	insert(1 + n, 1, 0, 0, -1);
	insert(n, n + n, 0, oo, 1);
	insert(n + n, n, 0, 0, -1);
	up(i, 1, m) {
		int x = read(), y = read(), v = read();
		insert(x + n, y, v, 1, 1);
		insert(y, x + n, -v, 0, -1);
	}
	st = 1, ed = n;
}

bool spfa() {
	head = 1, tail = 0;
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[st] = 0;
	q[++tail] = st;
	vis[st] = 1;
	while (head <= tail) {
		int x = q[head++];
		for (int i = lin[x]; i; i = e[i].nt) {
			int y = e[i].y;
			if (e[i].flow && dis[x] + e[i].v < dis[y]) {
				dis[y] = e[i].v + dis[x];
				node[y] = x, edge[y] = i;
				if (!vis[y]) {
					q[++tail] = y;
					vis[y] = 1;
				}
			}
		}
		vis[x] = 0;
	}
	return dis[ed] != oo;
}

int agu() {
	int flow = oo;
	int sum = 0;
	for (int i = ed; i != st; i = node[i]) 
		if (e[edge[i]].flow < flow)
			flow = e[edge[i]].flow;
	for (int i = ed; i != st; i = node[i]) {
		int te = edge[i];
		e[te].flow -= flow;
		int re = e[te].rev;
		e[re].flow += flow;
		sum += flow * (e[te].v);
	}
	return sum;
}

void costflow() {
	int cnt = 0, ans = 0;
	while (spfa()) {
		ans += agu();
		++cnt;
	}
	printf("%d %d\n", cnt, ans);
}

int main() {
	//freopen("a.txt", "r", stdin);
	init();
	costflow();
	return 0;
}
