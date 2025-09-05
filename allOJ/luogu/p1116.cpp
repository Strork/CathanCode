#include <bits/stdc++.h>
using namespace std;
int a[10005];
int n, cnt;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            if (a[j] > a[j + 1]) { // 如果发生交换
                swap(a[j], a[j + 1]); // 交换位置
                cnt++; // 统计交换次数
            }
        }
    }
    cout << cnt << endl;
    return 0;
}