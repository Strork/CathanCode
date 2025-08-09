#include <bits/stdc++.h>
using namespace std;
int n;
int height[2005];
int team[2005];
int cnt;

int main() {
    cin >> n;
    for (int i = 0; i <= n-1; ++i) {
        cin >> height[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cnt = i - 1; // 队伍已有的人数
        int id;
        cin >> id;
        int ans = 0;
        for (int j = 0; j <= cnt; ++j) {
            if (height[id] < team[j]) { // 找到加入队伍的位置
                swap(height[id], team[j]);
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}