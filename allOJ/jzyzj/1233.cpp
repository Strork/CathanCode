#include<bits/stdc++.h>
int tim;
int top;
int n, m;
int stack[50100];
bool vis[50100];
int dfn[50100];
int low[50100];
int point_num;
int point[50100];
int ans = 0;
struct qaq {
	int y, nt;
}e[1000100];
int lin[50100];
int len = 0;

int read() {
	int k = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) {
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return k;
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
		++point_num;
		do {
			k = stack[top--];
			point[k] = point_num;
		} while (k != x);
	}
}

int du[50100];
void solution() {
	int cnt = 0;
	for (int x = 1; x <= n; ++x) {
		for (int i = lin[x]; i; i = e[i].nt) {
			int y = e[i].y;
			if (point[y] != point[x]) ++du[point[x]];
		}
	}
	int id;
	for (int i = 1; i <= point_num; ++i) {
		if (!du[i]) ++cnt, id = i;
	}
	if (!cnt || cnt >= 2) {
		printf("0\n");
		return;
	}
	else {
		for (int i = 1; i <= n; ++i) {
			if (point[i] == id) ++ans;
		}
		printf("%d\n", ans);
	}
}

int main() {
	n = read();
	m = read();
	for (int i = 1; i <= m; ++i) {
		int x = read();
		int y = read();
		insert(x, y);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) tarjan(i);
	}
	solution();
	return 0;
}

