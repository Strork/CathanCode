#include<bits/stdc++.h>
#define ll long long
#define reg register int

double f[1010];
int t;
int n;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		f[n] = 0;
		for (reg i = n - 1; i >= 0; --i) {
			f[i] = f[i + 1] + double(n) / double(n - i);
		}
		printf("%.2lf\n", f[0]);
	}
	return 0;
}
