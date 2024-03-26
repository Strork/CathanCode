#include<bits/stdc++.h>
using namespace std;
int n;
int a1, a2, b1, b2;

inline int gcd(int a, int b) {
	while (b != 0) {
		int t = a;
		a = b;
		b = t % b;
	}
	return a;
}

inline int lcm(int a, int b) {
	return 1LL * a * b / gcd(a, b);
}

int main() {
	scanf("%d\n", &n);
	while (n--) {
		scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
		int ans = 0;
		for (int i = 1; i * i <= b2; ++i) {
			if (b2 % i != 0) continue;
			int a = gcd(i, a1);
			int b = lcm(i, b1);
			if (a == a2 && b == b2) ++ans;
			int j = b2 / i;
			if (i == j) continue;
			a = gcd(j, a1);
			b = lcm(j, b1);
			if (a == a2 && b == b2) ++ans;
			//cout<<i<<' '<<a<<' '<<b<<endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}
