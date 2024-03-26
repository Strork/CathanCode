#include<bits/stdc++.h>
#define	INF 2100000000
#define int 
using std::cout;
using std::endl;
struct qaq {
	int y, nt, v, id;
}e[1000100];
int lin[10100];
int rev[1000100];
int level[10100];
int head, tail;
int q[10100];
int n, m;

char buf[1<<15], *fs, *ft;
inline char getc(){return (fs==ft && (ft = (fs = buf) + fread(buf, 1, 1<<15, stdin), fs==ft)) ? 0 : *fs++;}
inline int read() {
	int k = 0;
	int f = 1;
	char ch = getc();
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
	e[++len].nt = lin[x]; lin[x] = len; e[len].y = y; e[len].v = v; rev[len] = len + 1;
	e[++len].nt = lin[y]; lin[y] = len; e[len].y = x; e[len].v = v; rev[len] = len - 1;
}

void init() {
	n = read(), m = read();
	for (int i = 1; i <= m; ++i) {
		int x = read(), y = read();
		insert(x, y, 1, i);
		insert(0, x, 1);
		insert(y, n + 1, 1);
	}
}

bool make_level() {
	memset(level, -1, sizeof(level));
	level[0] = 0;
	tail = 0, head = 1;
	q[++tail] = 1;
	while (head <= tail) {
		int x = q[head++];
		for (int i = lin[x]; i; i = e[i].nt) {
			if (e[i].v && level[e[i].y] == -1) {
				q[++tail] = e[i].y;
				level[e[i].y] = level[x] + 1;
			}
		}
	}
	return level[n + 1] >= 0;
}

int max_flow(int k, int flow) {
	
}

void dinic() {
	int sum = 0;
	int d;
	while (make_level())
		while(d = max_flow(1, INF))
			sum += d;
}

int main() {
	init();
	dinic();
	return 0;
}
