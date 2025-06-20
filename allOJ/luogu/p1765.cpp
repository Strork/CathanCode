#include <bits/stdc++.h>
using namespace std;
int press[256];

int main() {
	char ch = 'a';
	for (int i = 1; i <= 5; ++i) for(int j = 1; j <= 3; ++j) press[ch++] = j;
	for (int i = 1; i <= 4; ++i) press[ch++] = i;
	for (int i = 1; i <= 3; ++i) press[ch++] = i;
	for (int i = 1; i <= 4; ++i) press[ch++] = i;
	string a;
	getline(cin, a);
	int ans = 0;
	for (auto i : a) {
		if (i != ' ') ans += press[i];
		else ans++;
	}
	cout << ans << endl;
	return 0;
}