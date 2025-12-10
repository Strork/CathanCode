#include <bits/stdc++.h>
using namespace std;
vector<int> a[500005]; // 存树
int fa[500005][26]; // 倍增数组
int depth[500005]; // 深度
int n, m, root;

void dfs(int x, int fa) {
	for (int i = 0; i < a[x].size(); ++i) { //遍历节点x的子节点
		int y = a[x][i]; // 子节点记录为y
		if (y == father) continue; // y是上一个点，跳过
		depth[y] = depth[x] + 1; // 记录y的深度
		fa[y][0] = x; // 初始化，y跳一格到x
		for (int i = 1; i <= log2(depth[y]); ++i) { // 求解y跳2^i格可以到哪里
			int big_jump = fa[y][i-1]; // y先跳2^(i-1)格
			fa[y][i] = fa[big_jump][i-1]; 
		}
		dfs(y, x); // 查找下一个节点
	}
}

int find(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y); // 从x找，所以保证x更深
	while (depth[x] > depth[y]) { // 不是同一深度，向上跳
		int p = log2(depth[x] - depth[y]); // 跳跃的距离是深度差
		x = fa[x][p];
	}
	if (x == y) return x; // 发现y是x的祖先
	for (int p = log2(depth[x]); p >= 0; --p) {
		if (fa[x][p] != fa[y][p]) { // 假如跳之后，还没碰到一起
			x = fa[x][p], y = fa[y][p]; 
		}
	}
	return fa[x][0];
}

int main() {
	//freopen("a.in", "r", stdin);
	cin >> n >> m >> root;
	for (int i = 1; i < n; ++i) { // 读取N-1条边
		int x, y;
		cin >> x >> y;
		a[x].push_back(y); // 记录无向边的过程
		a[y].push_back(x);
	}
	fa[root][0] = 0;
	dfs(root, -1);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		cin >> x >> y;
		cout << find(x, y) << endl;
	}
	return 0;
}