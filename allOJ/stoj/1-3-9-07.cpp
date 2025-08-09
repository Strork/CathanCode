#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x11[2005], y11[2005], x22[2005], y22[2005]; // 轰炸坐标
ll x[2005], y[2005]; // 关键点
int cnt[2005]; // 轰炸次数
int last[2005]; // 最后一次轰炸
int n, m;

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> x11[i] >> y11[i] >> x22[i] >> y22[i];
    }
    for (int i = 1; i <= n; ++i) { // i是当前关键点的下标
        cin >> x[i] >> y[i]; // 读入关键点坐标
        // cout << x[i] << y[i] << endl;
        for (int j = 1; j <= m; ++j) { // 检查是否被轰炸, 有m次轰炸
            if (x[i]>=x11[j] && x[i]<=x22[j] && y[i]>=y11[j] && y[i] <= y22[j]) {
                cnt[i]++;
                last[i] = j; // j是递增的
            }
        }
        if (cnt[i] > 0) cout << "YES " << cnt[i] << ' ' << last[i] << endl;//printf("YES %d %d\n", cnt[i], last[i]);
        else cout << "NO\n";
    }
    return 0;
}