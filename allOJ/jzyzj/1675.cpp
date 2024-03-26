#include<bits/stdc++.h>
#define oo 0x7f7f7f7f
#define ll long long
#define reg register int

struct net_flow{
	int val, flow, nt, y;
	int rev;
}e[101000];
int lin[1010];
int len = 0;
int st, ed;
int n, m, k;
int level[1010];
int q[10100];
int head, tail;
struct input_data{
	int x, y, c, v;
}aa[5010];
int dis[1010];
int edge[1010];
int node[1010];
bool vis[1010];

int read() {
	int k = 0, f = 1;
	char ch = getchar();
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

inline void insert(int x, int y, int val, int flow, int z) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
	e[len].val = val;
	e[len].flow = flow;
	e[len].rev = len + z;
}

void init() {
	n = read(), m = read(), k = read();
	for (reg i = 1; i <= m; ++i) {
		int x = read(), y = read();
		int flow = read(), val = read();
		insert(x, y, 0, flow, 1);
		insert(y, x, 0, 0, -1);
		aa[i].x = x, aa[i].y = y, aa[i].c = flow, aa[i].v = val;
	}
}

bool make_level() {
	memset(level, -1, sizeof(level));
	level[st] = 0;
	head = 1, tail = 0;
	q[++tail] = st;
	while (head <= tail) {
		int x = q[head++];
		for (reg i = lin[x]; i; i = e[i].nt) {
			int y = e[i].y;
			if (e[i].flow && level[y] == -1) {
				level[y] = level[x] + 1;
				q[++tail] = y;
			}
		}
	}
	return level[ed] >= 0;
}

int max_flow(int x, int flow) {
	int maxflow = 0;
	int d = 0;
	if (x == ed) return flow;
	for (reg i = lin[x]; i && maxflow < flow; i = e[i].nt) {
		int y = e[i].y;
		if (level[y] == level[x] + 1 && e[i].flow) {
			if (d = max_flow(y, std::min(flow - maxflow, e[i].flow))) {
				maxflow += d;
				e[i].flow -= d;
				e[e[i].rev].flow += d;
			}
		}
	}
	if (!maxflow) level[x] = -1;
	return maxflow;
}

void dinic() {
	st = 1, ed = n;
	int ans = 0;
	int d = 0;
	while (make_level())
		while (d = max_flow(st, oo))
			ans += d;
	printf("%d ", ans);
}

void re_build() {
	//memset(lin, 0, sizeof(lin));
	st = 0, ed = n;
	//len = 0;
	for (reg i = 1; i <= m; ++i) {
		int x = aa[i].x, y = aa[i].y;
		int flow = k, val = aa[i].v;
		//printf("%d\n", val);
		insert(x, y, val, flow, 1);
		insert(y, x, -val, 0, -1);
	}
	insert(0, 1, 0, k, 1);
	insert(1, 0, 0, 0, -1);
}

bool spfa() {
	//printf("--------\n");
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[st] = 0;
	vis[st] = 1;
	head = 1, tail = 0;
	q[++tail] = st;
	while (head <= tail) {
		int x = q[head++];
		for (reg i = lin[x]; i; i = e[i].nt) {
			int y = e[i].y;
			//printf("%d\n", y);
			if (e[i].flow && dis[x] + e[i].val < dis[y]) {
				dis[y] = dis[x] + e[i].val;
				//printf("%d\n", dis[y]);
				node[y] = x;
				edge[y] = i;
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
	//printf("-------\n");
	int flow = oo;
	int sum = 0;
	for (reg i = ed; i != st; i = node[i]) {
		if (e[edge[i]].flow < flow)
			flow = e[edge[i]].flow;
	}
	for (reg i = ed; i != st; i = node[i]) {
		int te = edge[i];
		e[te].flow -= flow;
		int re = e[te].rev;
		e[re].flow += flow;
		sum += e[te].val * flow;
	}
	return sum;
}

void cost_flow() {
	int ans = 0;
	while (spfa())
		ans += agu();
	printf("%d\n", ans);
}

int main() {
	init();
	dinic();
	re_build();
	cost_flow();
	return 0;
}
