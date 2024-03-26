#include<bits/stdc++.h>
using namespace std;
int prime[40100];
bool f[40100];
int tail = 0;
int ans = 0;
int n;

void get_prime() {
	memset(f, 1, sizeof(f));
	f[0] = f[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (f[i]) {
			prime[++tail] = i;
			int temp = i + i;
			while (temp <= n) f[temp] = 0, temp += i;
		}
	}
}

void euler() {
	for (int i = 1; i < n; ++i) {
		int temp = i;
		for (int j = 1; j <= tail; ++j) {
			if (prime[j] > temp) break;
			if (i % prime[j] == 0) {
				temp = temp * (prime[j] - 1) / prime[j];
			}
		}
		ans += temp;
	}
}

int main() {
	scanf("%d", &n);
	get_prime();
	euler();
	printf("%d\n", ans * 2 + 1);
	return 0;
}
