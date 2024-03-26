#include<bits/stdc++.h>
using namespace std;
int m;
int f[30];

int main() {
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= 28; ++i) {
		f[i] = f[i - 2] + f[i - 1];
		cout << f[i] << ' ' << f[i] % 6 << endl;
	}
	return 0;
}
