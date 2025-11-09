#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a = 9;
	cin >> n;
	if (n < 10) {
		cout << n;
		return 0;
	} else {
		for (int i = 10; i <= n; i++) {
			if (i < 100) {
				if (i % 10 == i / 10) {
					a++;
				}
			} else {
				if (i < 1000) {
					if (i % 10 == i / 10 == i / 100) {
						a++;
					}
				} else if (i < 10000) {
					if (i % 10 == i / 10 == i / 100 == i / 1000) {
						a++;
					}
				}
			}
		}
	}
	cout << a;
	return 0;
}