// #include <bits/stdc++.h>
// using namespace std;
// int f[10005];
// int w[505], v[505];
// int n, l;

// int main() {
//     memset(f, 0x3f, sizeof(f));
//     f[0] = 0;
//     cin >> n >> l;
//     int sum = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> v[i] >> w[i];
//         if (w[i] > l) w[i] = l; // 我最多需要 l 毫升的饮料
//         sum += w[i];
//     }
//     if (sum < l) {
//         cout << "no solution" << endl;
//         return 0;
//     }
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 2*l; j >= w[i]; --j) {
//             f[j] = min(f[j], f[j-w[i]] + v[i]);
//         }
//     }
//     int ans = 0x3f3f3f3f;
//     for (int i = l; i <= 2*l; ++i) {
//         ans = min(ans, f[i]);
//     }
//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int w[505], v[505];
int n, l;

int main() {
    cin >> n >> l;
    int sumw = 0;
    int money = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
        sumw += w[i];
        money += v[i];
    }
    if (sumw < l) cout << "no solution" << endl;
    else {
        for (int i = 1; i <= n; ++i) {
            for (int j = min(money,1000000); j >= v[i]; --j) {
                f[j] = max(f[j], f[j-v[i]] + w[i]);
            }
        }
    }
    for (int i = 0; i <= money; ++i) { // 二分答案
        if (f[i] >= l) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}