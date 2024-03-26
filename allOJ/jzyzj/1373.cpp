#include<bits/stdc++.h>
using namespace std;
int a[5010];
bool f[1000100];
int n;
int id = 1;

void solution() {
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if(!f[a[j] - a[i]]) f[a[j] - a[i]] = 1;
		}
	}
	for (int i = 2; i <= a[n] + 1; ++i) {
		if (f[i]) continue;
		int j = 2;
		while (1) {
			if (f[i * j]) break;
			++j;
			if(i * j > a[n]) {
				printf("%d\n", i);
				return;
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		cout<<1<<endl;
		return 0;
	}
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	solution();
	return 0;
}
