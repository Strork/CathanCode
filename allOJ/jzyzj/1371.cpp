#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll X, Y, M, N, L;
ll a, b, x, y;

ll exgcd(ll ta, ll tb) {
	if (tb == 0) {
		x = 1;
		y = 0;
		return ta;
	}
	ll r = exgcd(tb, ta % tb);
	ll t = x;
	x = y;
	y = t - ta / tb * y;
	return r;
}

ll gcd(ll ta, ll tb) {
	if (tb == 0) return ta;
	else return gcd(tb, ta % tb);
}

int main() {
	cin >> X >> Y >> M >> N >> L;	
	a = M - N;
	b = L;
	ll c = Y - X;
	while (a < 0) a += L;
	while (c < 0) c += L;
	ll d = gcd(a, b);
	if (c % d) cout << "Impossible" << endl;
	else {
		a /= c / d;
		b /= c / d;
		c /= c / d;
		ll r = exgcd(a, b);
		while (x < 0) x += L;
		x = (x * c % L + L) % L;
		cout << x << endl;
	}
	return 0;
}
