#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[110];
int lmt;

bool mycmp(int x, int y) { return x > y; }

void binary(int l, int r) {
	int mid = (l + r) / 2;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		bool flag = 1;
		int temp = 0;
		for (int i = 1; i <= lmt; ++i) {
			if (a[i] < mid) break;
			temp += a[i] / mid;
		}
		if (temp >= n) l = mid;
		else r = mid;
	}
	int temp = 0;
	for (int i = 1; i <= lmt; ++i) {
		if (a[i] < r) break;
		temp += a[i] / r;
	}
	if (temp >= n) cout << r << endl;
	else cout << l << endl;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int k;
		cin >> k;
		++a[k];
	}
	sort(a + 1, a + 1 + 100, mycmp);
	for (int i = 1; i <= m; ++i) if (a[i]) lmt = i; 
	binary(0, a[1]);
	return 0;
}
