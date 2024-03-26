#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
long long f[15][1 << 12];
int n, m;

void dfs(int i, int j, int nw, int nt) {
	if (j == m) {
		//cout<<j<<endl;
		f[i + 1][nt] += f[i][nw];
		return;
	}
	if (((1 << j) & nw) > 0) dfs(i, j + 1, nw, nt);
	if (((1 << j) & nw) == 0) {
		dfs(i, j + 1, nw, nt | (1 << j));
		if (j + 1 < m && ((1 << (j + 1)) & nw) == 0) dfs(i, j + 2, nw, nt);
	}
}

int main() {
	cin >> n;
	cin >> m;
	f[1][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < (1 << m); ++j) {
			//cout<<i<<j<<endl;
			if (f[i][j]) dfs(i, 0, j, 0);
		}
	}
	cout << f[n + 1][0] << endl;
	return 0;
}
