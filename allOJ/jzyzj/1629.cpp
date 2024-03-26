#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int p[1000100];
int tail;
int a[1000100];

int main() {
	cin>>n;
	if (n <= 1) cout<<0<<endl;
	else {
		for (int i = 2;;) {
			if (n % i == 0) {
				p[++tail] = i;
				a[tail] = 0;
				while (n % i == 0) {
					n /= i;
					++a[tail];
				}
			}
			else ++i;
			if (i * i > n && n > 1) {
				p[++tail] = i;
				a[tail] = 1;
				break;
			}
			if (i * i > n) break;
		}
	}
	int ans = 1;
	for (int i = 1; i <= tail; ++i) {
		ans *= (1 + a[i] * 2);
	}
	printf("%d\n", ans / 2);
	return 0;
}
