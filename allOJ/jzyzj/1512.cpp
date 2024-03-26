#include<bits/stdc++.h>
using std::cout;
using std::endl;
int n, m;
int v[1100];
int w[1100];
int fa[1100];
int nv[1100];
int nw[1100];
int nfa[1100];
int chd[1100];
int bro[1100];
struct qaq {
	int y, nt;
}e[210000];
int lin[1100];
int len = 0;
int dfn[1100];
int low[1100];
int pit[1100];
bool vis[1100];
int stack[1100]; 
int top = 0;
int tim = 0;
int pos = 0;
int f[110][510];

inline int read() {
	int k = 0;
	int f = 1;
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

inline void insert(int x, int y) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++tim;
	vis[stack[++top] = x] = 1;
	for (int i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!dfn[y]) {
			tarjan(y);
			low[x] = std::min(low[x], low[y]);
		}
		else if (vis[y]) {
			low[x] = std::min(low[x], dfn[y]);
		}
	}
	if (low[x] == dfn[x]) {
		int k;
		++pos;
		do {
			k = stack[top--];
			pit[k] = pos;
			vis[k] = 0;
		} while (k != x);
	}
}

void init() {
	n = read();
	m = read();
	for (int i = 1; i <= n; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i) v[i] = read();
	for (int i = 1; i <= n; ++i) {
		fa[i] = read();
		insert(fa[i], i);
	} 
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) tarjan(i);
	}
}

void dfs(int x, int y) {
	//cout<<x<<' '<<y<<endl;
	if (y <= 0) return;
	if (!x || !y) return;
	if (f[x][y]) return;
	dfs(bro[x], y);
	f[x][y] = f[bro[x]][y];
	//cout<<x<<' '<<y<<' '<<f[x][y]<<endl;
	for (int k = 0; k < y; ++k) {
		if (y - k - nw[x] < 0) continue;
		dfs(bro[x], k);
		dfs(chd[x], y - k - nw[x]);
		f[x][y] = std::max(f[x][y], f[bro[x]][k] + f[chd[x]][y - k - nw[x]] + nv[x]);
	}
	//cout<<x<<' '<<y<<' '<<f[x][y]<<endl;
}

void solution() {
	for (int x = 1; x <= n; ++x) {
		//cout<<x<<' '<<pit[x]<<' ';
		nv[pit[x]] += v[x];
		nw[pit[x]] += w[x];
		//cout<<nv[pit[x]]<<' '<<nw[pit[x]]<<endl;
		if (pit[fa[x]] != pit[x]) {
			nfa[pit[x]] = pit[fa[x]];
			//cout<<pit[x]<<' '<<nfa[pit[x]]<<endl;
		}
	}
	for (int i = 1; i <= pos; ++i) {
		int x = nfa[i];
		if (x == 0) x = pos + 1;
		bro[i] = chd[x];
		chd[x] = i;
	}
	//for (int i = 1; i <= pos + 1; ++i) cout<<i<<' '<<chd[i]<<' '<<bro[i]<<endl;
	dfs(chd[pos + 1], m);
	printf("%d\n", f[chd[pos + 1]][m]);
}

int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	init();
	solution();
	return 0;
}
