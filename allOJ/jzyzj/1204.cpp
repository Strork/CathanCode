#include<bits/stdc++.h>
using namespace std;
int n;
int a, b, c, d;
int ans = 0;
int mid;

int main() {
	scanf("%d", &n);
	if (n & 1) mid = n / 2 + 1;
	else mid = n / 2;
	for (int i = n / 2 + 1; i < n; ++i) {
		d = n - i;
		for (int j = i - 1; j >= 2; --j) {
			c = i - j;
			if (c > n - n / 2 - 1) break;
			int id = j - 1;
			ans += id;
			if (id >= mid) ans -= 2 * (id - mid + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
