#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q; // 小根堆，堆头是最小值
priority_queue<int> Q; // 大根堆，堆顶为最大值
int n;
int ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		q.push(x);
	}
	while (n >= 2) {
		int x = q.top(); 
		q.pop();
		int y = q.top(); //次小数
		q.pop();
		ans += x + y;
		q.push(x + y);
        n--;
	}
	cout << ans << endl;
	return 0;
}