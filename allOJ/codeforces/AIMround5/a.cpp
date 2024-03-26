#include<bits/stdc++.h>
using namespace std;
char a[120][120];
int n, m;
int r, c;

void work() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == 'B') {
				int x, y;
				for (x = j; x <= m; ++x) if (a[i][x + 1] != 'B') break;
				for (y = i; y <= n; ++y) if (a[y + 1][j] != 'B') break;
				r = i + (y - i) / 2;
				c = j + (x - j) / 2;
				return;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	work();
	cout << r << ' ' << c << endl;
	return 0;
}
