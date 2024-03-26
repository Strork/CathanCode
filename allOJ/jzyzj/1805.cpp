#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[10100];

void solution() {
	for (int i = 1; i <= m; ++i) {
		int j = n - 1;
		while (j >= 1 && a[j] > a[j + 1]) --j;
		//cout<<j<<endl;
		if (j >= 1) {
			int k = n;
			while (a[k] < a[j]) --k;
			swap(a[j], a[k]);
			for (int x = j + 1, y = n; x < y; ++x, --y) swap(a[x], a[y]);
		}
	}
	for (int i = 1; i < n; ++i) printf("%d ", a[i]);
	printf("%d\n", a[n]);
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	solution();
	return 0;
}
