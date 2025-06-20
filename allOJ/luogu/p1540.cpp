#include <bits/stdc++.h>
using namespace std;
int n, m;
queue<int> q;
bool dict[1005];
int ans;

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (dict[x]) continue;
		++ans;
		q.push(x);
		dict[x] = 1;
		if (q.size() > m) {
			dict[q.front()] = 0;
			q.pop();
		}
	}
	cout << ans;
	return 0;
}