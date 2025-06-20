#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;
int n;
int ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		q.push(x);
	}
	while (n-- >= 2) {
		int x = q.top();
		q.pop();
		int y = q.top();
		q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans << endl;
	return 0;
}