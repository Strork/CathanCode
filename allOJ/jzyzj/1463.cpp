#include<bits/stdc++.h>
#define reg register int
#define oo 0X7f7f7f7f
#define ll long long

typedef std::pair<int, int> pii;

int dp[100100][55];
bool f[100100][55];
int dis[100100];
struct edge{
	int y, v, nt;
}e[200100], E[200100];
int lin[100100];
int LIN[100100];
int T;
int len;
bool vis[100100];
int n, m;
int p, ad;
int ans;
bool flag;

inline void insert(int x, int y, int v) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
	e[len].v = v;

	E[len].nt = LIN[y];
	LIN[y] = len;
	E[len].y = x;
	E[len].v = v;
}

char buf[1 << 15], *fs, *ft;
inline char getc(){return (fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;}
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
inline void put(int x) {
	if (x == 0) {
		putchar('0');
		putchar('\n');
		return;
	}
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	char ch[25];
	int top = 0;
	while (x) {
		ch[++top] = x % 10 + '0';
		x /= 10;
	}
	while (top) {
		putchar(ch[top--]);
	}
	putchar('\n');
}

void dijkstra() {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
	dis[1] = 0;
	q.push(std::make_pair(dis[1], 1));
	while (!q.empty()) {
		pii temp = q.top();
		q.pop();
		int x = temp.second;
		if(vis[x]) continue;
		vis[x] = 1;
		for (int i = lin[x]; i; i = e[i].nt) {
			if (dis[e[i].y] > dis[x] + e[i].v) {
				dis[e[i].y] = dis[x] + e[i].v;
				q.push(std::make_pair(dis[e[i].y], e[i].y));
			}
		}
	}
}

int dfs(int x, int k) {
	if (flag) return 0;
	if (dp[x][k]) return dp[x][k];
	f[x][k] = 1;
	for (int i = LIN[x]; i; i = E[i].nt) {
		//printf("----------\n");
		int y = E[i].y;
		int v = E[i].v;
		int val = dis[x] + k - v - dis[y];
		if (val < 0) continue;
		if (val > k) continue;
		if (f[y][val]) {
			flag = 1;
			return 0;
		}
		dp[x][k] += dfs(y, val);
		dp[x][k] %= p;
	}
	f[x][k] = 0;
	return dp[x][k];
}

void solution() {
	dp[1][0] = 1;
	int ans = 0;
	for (reg i = 0; i <= ad; ++i) {
		ans += dfs(n, i);
		ans %= p;
	}
	if (!ad) dfs(n, 1);
	if (flag) printf("-1\n");
	else put(ans);
}

int main() {
	freopen("2017park.in", "r", stdin);
	freopen("2017park.out", "w", stdout);
	T = read();
	while (T--) {
		memset(lin, 0, sizeof(lin));
		memset(LIN, 0, sizeof(LIN));
		memset(dp, 0, sizeof(dp));
		memset(f, 0, sizeof(f));
		len = 0;
		flag = 0;
		n = read(); m = read();
		ad = read(); p = read();
		for (reg i = 1; i <= m; ++i) {
			int x = read();
			int y = read();
			int v = read();
			insert(x, y, v);
		}
		dijkstra();
		//printf("%d %d\n", dis[1], dis[2]);
		solution();
	}
	return 0;
}
