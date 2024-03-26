#include<bits/stdc++.h>
#define ll long long
#define oo 2123456789
#define reg register
#define up(i,j,k)	for (reg int i = j; i <= k; ++i)
#define down(i,j,k)	for (reg int i = j; i >= k; --i)
using namespace std;

struct qaq {
	int nt, nd, val, rev;
}e[1000000];
int len = 0;
int lin[101000];

int n, m;
int st, ed;
int ans;

char buf[1<<15], *fs, *ft;
inline char getc() {
	return (fs==ft && (ft = (fs = buf) + fread(buf, 1, 1<<15, stdin), fs==ft)) ? 0 : *fs++;
}
inline int read() {
	char ch = getc();
	int k = 0, f = 1;
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

inline void insert(int x, int y, int v) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].val = v;
	e[len].rev = len + 1;
	e[len].nd = y;
	
	e[++len].nt = lin[y];
	lin[y] = len;
	e[len].val = 0;
	e[len].rev = len - 1;
	e[len].nd = x;
}

int q[101000];
int tail, head;
int level[101000];

bool make_level() {
	tail = 0, head = 1;
	q[++tail] = st;
	memset(level, -1, sizeof(level));
	level[st] = 0;
	while (head <= tail) {
		int x = q[head++];
		for (int i = lin[x]; i; i = e[i].nt) {
			if (e[i].val && level[e[i].nd] == -1) {
				q[++tail] = e[i].nd;
				level[e[i].nd] = level[x] + 1;
			}
		}
	}
	return level[ed] >= 0;
}

int getflow(int x, int flow) {
	if (x == ed) return flow;
	int maxflow = 0;
	int k = 0;
	for (int i = lin[x]; i && (maxflow < flow); i = e[i].nt) {
		if (level[e[i].nd] == level[x] + 1 && e[i].val) {
			if (k = getflow(e[i].nd, std::min(flow - maxflow, e[i].val))) {
				maxflow += k;
				e[i].val -= k;
				e[e[i].rev].val += k;
			}
		}
	}
	if (!maxflow) level[x] = -1;
	return maxflow;
}

int dinic() {
	int flow;
	int sum = 0;
	while (make_level()) {
		while (flow = getflow(st, oo))
			sum += flow;
	}
	return sum;
}

int main() {
	n = read();
	m = read();
	st = 0, ed = n + m + 1;
	up(i, 1, n) {
		int temp = read();
		insert(i + m, ed, temp);
	}
	up(i, 1, m) {
		int a = read(), b = read(), c = read();
		insert(i, a + m, oo);
		insert(i, b + m, oo);
		insert(st, i, c);
		ans += c;
	}
	int flow = dinic();
	ans -= flow;
	printf("%d\n", ans);
	return 0;
}

