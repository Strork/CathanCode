#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1050];
bool flag; // 初始值 = false

int main () {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) { // 循环从 1 —— n-1
        for (int j = i+1; j <= n; ++j) {// 求和第i个数后面的所有数字
            int sum = a[i] + a[j];
            if (sum == k) {
                flag = true;
                // cout << "yes" << endl;
                // return 0;
            }
        }
    }
    // cout << "no" << endl;
    if (flag) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}