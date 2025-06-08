#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[300];
int k;
char trans[20][2];
vector<int> ans;

int main() {
    string num;
    cin >> num >> k;
    for (int i = 1; i <= k; ++i) cin >> trans[i][0] >> trans[i][1];
	for (int i = 0; i < num.size(); ++i) {
		memset(vis, 0, sizeof(vis));
		queue<char> q;
		q.push(num[i]);
		vis[num[i]] = 1;
		while (!q.empty()) {
			char ch = q.front();
			q.pop();
			for (int j = 1; j <= k; ++j) {
				if (trans[j][0] == ch && !vis[trans[j][1]]) {
					vis[trans[j][1]] = 1;
					q.push(trans[j][1]);
				}
			}
		}
		int cnt = 0;
		for (int j = '0'; j <= '9'; ++j) {
			if (vis[j]) cnt++;
		}
		for (size_t j = 0; j < ans.size(); ++j) {
			
		}
	}
    cout << ans;
    return 0;
}