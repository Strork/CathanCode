#include<bits/stdc++.h>
using namespace std;
int fa[6010];
int n, m, p;

int getfa(int x) {
	int y = x;
	while (fa[y] != y) y = fa[y];
	while (x != y) {
		int temp = fa[x];
		fa[x] = y;
		x = temp;
	}
	return y;
}

int main() {
	cin>>n>>m>>p;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = getfa(x);
		y = getfa(y);
		fa[x] = y;
	}
	for (int i = 1; i <= p; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		x = getfa(x);
		y = getfa(y);
		if(x == y) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
