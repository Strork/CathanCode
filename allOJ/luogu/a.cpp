#include <bits/stdc++.h>
using namespace std;

struct node {
	int x, y, step;
	node (int a = 0, int b = 0, int c = 0) {
		x = a, y = b, step = c;
	}
};

char a[305][305];
queue <node> q;
int vis[305][305];
int dis[305][305];
int n, m, nx, ny;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void slide(int &x, int &y ,int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == a[x][y] && (i != x && j != y)) {
				x = i;
				y = j;
				return;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1];
			if (a[i][j] == '@') {
				nx = i;
				ny = j;
			}
		}
	}
	q.push(node(nx, ny, 0));
	vis[nx][ny] = 1;
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		if (a[now.x][now.y] == '=') {
			cout << now.step;
			return 0;
		}
		if (a[now.x][now.y] >= 'A' && a[now.x][now.y] <= 'Z') {
            dis[now.x][now.y]
			slide(now.x, now.y, now.step);
            
		}
		for (int i = 0; i < 4; i++) {
			int tx = now.x + dx[i];
			int ty = now.y + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty]!='#' && !vis[tx][ty]) {
				vis[tx][ty] = 1;
				q.push(node(tx, ty, now.step + 1));
			}
		}
	}
	return 0;
}