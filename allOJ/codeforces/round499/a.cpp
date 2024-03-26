#include<bits/stdc++.h>
using namespace std;
int n, k;
char ch[100];
char str[100];
int len = 0;
int cnt = 0;
int ans = 0;
bool f[100];

int main() {
	cin>>n>>k;
	scanf("%s", ch + 1);
	sort(ch + 1, ch + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (ch[i] != ch[i + 1]) str[++len] = ch[i];
	}
	f[1] = 1;
	++cnt;
	int id = 1;
	for (int i = 2; i <= len; ++i) {
		if (cnt >= k) break;
		if (str[i] - str[id] >= 2) {
			id = i;
			++cnt;
			f[id] = 1;
		}
	}
	for (int i = 1; i <= len; ++i) {
		if (f[i]) ans += str[i] - 'a' + 1;
	}
	if (cnt >= k) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}
