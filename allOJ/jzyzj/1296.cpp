#include<bits/stdc++.h>
#define ll long long
#define oo 0x7f7f7f7f
#define reg register int
#define up(i, j, k)		for (reg i = j; i <= k; ++i)
#define down(i, j, k)	for (reg i = j; i >= k; --i)

using namespace std;

inline int read() {
	char ch = getchar();
	int f = 1, k = 0;
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

int n, m;
struct qaq {
	int nd, nt, rev;
	int val, flow;
}e[50100];
int lin[10010];
int len = 0;
int st, ed;

inline void insert(int x, int y, int val, int flow, int k) {
	e[++len].nt = lin[x]; lin[x] = len;
	e[len].nd = y; 
	e[len].rev = len + k; 
	e[len].flow = flow;
	e[len].val = -val;
}

void init() {
	n = read(), m = read();
	up(i, 1, n) {
		up(j, 1, m) {
			int x = j + (i - 1) * m;
			int y = n * m + x;
			int v = read();
			insert(x, y, v, 1, 1);
			insert(y, x, -v, 0, -1);
			if (i < n) {
				insert(y, x + m, 0, 1, 1);
				insert(x + m, y, 0, 0, -1);
			}
			if (j < m) {
				insert(y, x + 1, 0, 1, 1);
				insert(x + 1, y, 0, 0, -1);
			}
		}
	}
	st = 1, ed = n * m;
	e[st].flow = 2;
}

int vis[10100];
int head, tail;
int q[101000];
int dis[10100];
int edge[100100], node[10100];
int ans = 0;

bool spfa() {
	head = 1, tail = 0;
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	dis[st] = 0;
	q[++tail] = st;
	vis[st] = 1;
	while (head <= tail) {
		int x = q[head++];
		for (int i = lin[x]; i; i = e[i].nt) {
			int y = e[i].nd;
			if (e[i].flow && dis[x] + e[i].val < dis[y]) {
				dis[y] = dis[x] + e[i].val;
				edge[y] = i, node[y] = x;
				if (!vis[y]) {
					q[++tail] = y;
					vis[y] = 1;
				}
			}
		}
		vis[x] = 0;
	}
	return dis[ed] != int(oo);
}

void agu() {
	//cout << "---------" << endl;
	int flow = oo;
	for (int i = ed; i != st; i = node[i]) 
		if (e[edge[i]].flow < flow)
			flow = e[edge[i]].flow;
	for (int i = ed; i != st; i = node[i]) {
		int te = edge[i];
		e[te].flow -= flow;
		int re = e[te].rev;
		e[re].flow += flow;
		ans += (-e[te].val) * flow;
	}
}

void costflow() {
	while (spfa())
		agu();
	printf("%d\n", ans);
}

int main() {
	//freopen("a.txt", "r", stdin);
	init();
	costflow();	
	return 0;
}
