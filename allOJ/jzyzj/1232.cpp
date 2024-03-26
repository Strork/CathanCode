#include<bits/stdc++.h>
int tim;
int tail;
int top;
int stak[5010];
int dfn[5010];
int low[5010];
int id[5010];
int sum[5010];
int maxx = 0;
int pst[5010];
int tot = 0;
bool vis[5010];
int n, m;
struct qaq {
	int y, nt;
}e[1001000];
int lin[5010];
int len = 0;
int out[5010];
int ans;

void insert(int x, int y) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++tim;
	vis[stak[++top] = x] = 1;
	for (int i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!dfn[y]) {
			tarjan(y);
			low[x] = std::min(low[x], low[y]);
		}
		else if (vis[y] && dfn[y] < low[x]) low[x] = dfn[y];
	}
	if (low[x] == dfn[x]) {
		int k;
		++tail;
		do {
			k = stak[top--];
			vis[k] = 0;
			id[k] = tail;
			++sum[tail];
			if (sum[tail] > maxx) maxx = sum[tail];
		} while (k != x);
	}
}

void find() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= tot; ++j) {
			if (id[i] == pst[j]) {
				ans = id[i];
				return;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		if (v == 1) {
			insert(x, y);
		}
		else {
			insert(x, y);
			insert(y, x);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) tarjan(i);
	}
	for (int i = 1; i <= tail; ++i) {
		if (sum[i] == maxx) pst[++tot] = i;
	}
	find();
	top = 0;
	for (int i = 1; i <= n; ++i) {
		if (id[i] == ans) out[++top] = i;
	}
	printf("%d\n", top);
	for (int i = 1; i <= top; ++i) {
		printf("%d", out[i]);
		if (i != top) putchar(' ');
		else putchar('\n');
	}
	return 0;
}
