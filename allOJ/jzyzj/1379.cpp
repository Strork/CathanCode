#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a, b1, b2;

int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	while (scanf("%lld%lld%lld", &a, &b1, &b2)) {
		if(!a && !b1 && !b2) break;
		else {
			if (b1 < b2 || a % b1 != 0) printf("0\n");
			else {
				a *= b2;
				if (a % b1 == 0) printf("1 %d\n", a / b1);
				else printf("0\n");
			}
		}
	}
	return 0;
}
