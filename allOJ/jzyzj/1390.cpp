#include<bits/stdc++.h>
#define reg register int
#define up(i,j,k) 	for (reg i = j; i <= k; ++i)
#define down(i,j,k)	for (reg i = j; i >= k; --i)

using namespace std;

int n, m;
int x[110];
int sid[65];
int num[65];
int cnt = 0;
int f[110][65][65];

void init() {
	cin >> n >> m;
	up(i, 1, n) {
		up(j, 1, m) {
			char ch;
			cin >> ch;
			if (ch == 'H') x[i] |= 1;
			x[i] <<= 1;
		}
		x[i] >>= 1;
	}
}

void dfs(int a, int b, int c) {
	if (c >= m) {
		sid[++cnt] = a;
		num[cnt] = b;
		return;
	}
	dfs(a, b, c + 1);
	dfs(a + (1 << c), b + 1, c + 3);
}

int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	init();
	dfs(0, 0, 0);
	int ans = 0;
	up(i, 1, cnt) {
		if((sid[i] & x[1]) == 0) {
			f[1][i][1] = num[i];
			//if(i==6) cout<<f[1][i][0]<<endl;
		}
	}
	up(i, 2, n) {
		up(j, 1, cnt) {
			if ((sid[j] & x[i]) != 0) continue;
			up(k, 1, cnt) {
				if (sid[j] & sid[k]) continue;
				//if ((sid[k] | x[i]) != x[i]) continue;
				up(l, 1, cnt) {
					if (sid[j] & sid[l]) continue;
					if (sid[k] & sid[l]) continue;
					f[i][j][k] = max(f[i - 1][k][l] + num[j], f[i][j][k]);
					ans = max(ans, f[i][j][k]);
				}
			}
		}
	}
	cout << ans << endl;
	//cout<<f[2][4][]<<endl;
	/*for (int i = 1; i <= cnt; ++i) {
		int temp = sid[i];
		while (temp) {
			cout<<(temp&1);
			temp>>=1;
		}
		cout<<endl;
	}*/
	return 0;
}
