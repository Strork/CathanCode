#include<bits/stdc++.h>
#define ll long long
#define oo 0x7f7f7f7f

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
int st, ed;
struct qaq {
	int y, nt, v;
	int rev;
}e[2001000];
int level[1010];
int q[10010];
bool vis[1010];
int lin[1010];
int len = 0;
int ans = 0;
int head, tail;

inline void insert(int x, int y, int v, int k) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
	e[len].v = v;
	e[len].rev = len + k;
}

void init() {
	m = read(), n = read();
	for (int i = 1; i <= m; ++i) {
		int x = read(), y = read(), v = read();
		insert(x, y, v, 1);
		insert(y, x, 0, -1);
	}
}

bool make_level() {
	memset(level, -1, sizeof(level));
	head = 1, tail = 0;
	q[++tail] = st;
	level[st] = 0;
	while (head <= tail) {
		int x = q[head++];
		for (int i = lin[x]; i; i = e[i].nt) {
			if (e[i].v && level[e[i].y] == -1) {
				level[e[i].y] = level[x] + 1;
				q[++tail] = e[i].y;
			}
		}
	}
	return level[ed] >= 0;
}

int max_flow(int k, int flow) {
	if (k == ed) return flow;
	int maxflow = 0;
	int d = 0;
	for (int i = lin[k]; i && maxflow < flow; i = e[i].nt) {
		if (level[e[i].y] == level[k] + 1 && e[i].v) {
			if (d = max_flow(e[i].y, min(flow - maxflow, e[i].v))) {
				maxflow += d;
				e[i].v -= d;
				e[e[i].rev].v += d;
			}
		}
	}
	if (!maxflow) level[k] = -1;
	return maxflow;
}

void dinic() {
	int d = 0;
	while (make_level())
		if (d = max_flow(st, oo))
			ans += d;
	printf("%d\n", ans);
}

int main() {
	init();
	st = 1, ed = n;
	dinic();
	return 0;
}
