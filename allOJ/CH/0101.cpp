#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a, b, p;

int main() {
	cin >> a >> b >> p;
	ll ans = 1;
	ll t = a;
	while (b) {
		if (b & 1) ans = ans * t % p;
		t *= t;
		t %= p;
		b >>= 1;
	}
	cout << ans % p << endl;
	return 0;
}
