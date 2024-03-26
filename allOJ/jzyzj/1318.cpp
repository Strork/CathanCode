#include<bits/stdc++.h>
#define oo 2012345678
using namespace std;


char buf[1<<15], *fs, *ft;
inline char getc() {return(fs==ft&&(ft=(fs=buf)+fread(buf,1,1<<15,stdin),fs==ft))?0:*fs++;}
inline int read() {
	int k = 0, f = 1;
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

int n, m;
int a[210][210];
bool flag;
bool vis[210];
int flow;
int ans;

void dfs(int x, int maxflow) {
	vis[x] = 1;
	if (x == n) {
		flag = 1;
		ans += maxflow;
		flow = maxflow;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (a[x][i] > 0 && (!vis[i])) {
			dfs (i, min(a[x][i], maxflow));
			if (flag) {
				a[x][i] -= flow;
				a[i][x] += flow;
				return;
			}
		}
	}
}

int main() {
	//freopen("a.txt", "r", stdin);
	m = read();
	n = read();
	for (int i = 1; i <= m; ++i) {
		int x = read();
		int y = read();
		int val = read();
		a[x][y] += val;
	}
	flag = 1;
	while (flag) {
		flag = 0;
		memset(vis, 0, sizeof(vis));
		dfs(1,oo);
	}
	cout << ans << endl;
	return 0;
}
