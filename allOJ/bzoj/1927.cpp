#include<bits/stdc++.h>
#define ll long long
#define reg register int
#define oo 0x7f7f7f7f
#define up(i,j,k)	for (reg i = j; i <= k; ++i)
#define down(i,j,k)	for (reg i = j; i >= k; --i)

using namespace std;

struct qaq{
	int y, v, nt;
	int flow, rev;
}e[101000];
int len = 0;
int lin[2010];
int q[10100];
int head, tail;
bool vis[2010];
int node[2010];
int edge[2010];
int dis[2010];
int ans = 0;
int n, m;
int st, ed;

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

inline void insert(int x, int y, int v, int flow, int k) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
	e[len].v = v;
	e[len].flow = flow;
	e[len].rev = len + k;
}

bool spfa() {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	head = 1, tail = 0;
	q[++tail] = st;
	dis[st] = 0;
	vis[st] = 1;
	while (head <= tail) {
		int x = q[head++];
		for (int i = lin[x]; i; i = e[i].nt) {
			int y = e[i].y;
			if (e[i].flow && (dis[x] + e[i].v < dis[y])) {
				dis[y] = dis[x] + e[i].v;
				edge[y] = i; 
				node[y] = x;
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

void agu() {
	int flow = oo;
	for (int i = ed; i != st; i = node[i])
		if (e[edge[i]].flow < flow)
			flow = e[edge[i]].flow;
	for (int i = ed; i != st; i = node[i]) {
		int te = edge[i];
		e[te].flow -= flow;
		int re = e[te].rev;
		e[re].flow += flow;
		int temp = flow * e[te].v;
		ans += temp;
		//cout << temp << endl;
	}
}

void costflow() {
	while (spfa())
		agu();
	printf("%d\n", ans);
}

int main() {
	n = read();
	m = read();
	st = 0, ed = 2 * n + 1;
	up(i, 1, n) {
		int v = read();
		insert(st, i + n, v, 1, 1);
		insert(i + n, st, -v, 0, -1);
		insert(st, i, 0, 1, 1);
		insert(i, st, 0, 0, -1);
		insert(i + n, ed, 0, 1, 1);
		insert(ed, i + n, 0, 0, -1);
	}
	up(i, 1, m) {
		int x = read(), y = read();
		int v = read();
		if (x > y) swap(x, y);
		//cout << x << ' ' << y << endl;
		insert(x, y + n, v, 1, 1);
		insert(y + n, x, -v, 0, -1);
	}
	costflow();
	return 0;
}
