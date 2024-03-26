#include<bits/stdc++.h>
#define ll long long
using std::endl;
using std::cout;
struct qaq {
	int y, nt;
}e[1000100];
int lin[20100];
int len = 0;
int low[20100];
int dfn[20100];
int n;
int tail = 0;
int tim = 0;
int ans[20100];

inline void insert(int x, int y) {
	e[++len].nt = lin[x];
	lin[x] = len;
	e[len].y = y;
}

int tarjan(int x, int father = 0) {
	int cnt = 0;
	dfn[x] = low[x] = ++tim;
	for (int i = lin[x]; i; i = e[i].nt) {
		int y = e[i].y;
		if (!dfn[y]) {
			tarjan(y, x);
			low[x] = std::min(low[x], low[y]);
			if (low[y] >= dfn[x]) ++cnt;
		}
		else low[x] = std::min(low[x], dfn[y]);
	}
	if (cnt >= 2 || (father && cnt == 1)) ans[++tail] = x;
}

int main() {
	//freopen("a.txt", "r", stdin);
	scanf("%d", &n);
	int x, y;
	while (~scanf("%d%d", &x, &y)) {
		//int x, y;
		//scanf("%d %d", &x, &y);
		insert(x, y);
		insert(y, x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!dfn[i]) tarjan(i);
	}
	printf("%d\n", tail);
	std::sort(ans + 1, ans + 1 + tail);
	for (int i = 1; i <= tail; ++i) printf("%d\n", ans[i]);
	return 0;
}
