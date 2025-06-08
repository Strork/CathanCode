// #include <bits/stdc++.h>
// using namespace std;
// int a[10][10];
// int n, m;

// int main() {
//     for (int i = 1; i <= 5; ++i) {
//         for (int j = 1; j <= 5; ++j) {
//             cin >> a[i][j];
//         }
//     }
//     cin >> n >> m;
//     for (int j = 1; j <= 5; ++j) {
//         swap(a[n][j], a[m][j]);
//     }
//     for (int i = 1; i <= 5; ++i) {
//         for (int j = 1; j <= 5; ++j) {
//             cout << a[i][j];
//             if (j < 5) cout << ' ';
//             else cout << endl;
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int a[6][6];
int n, m;

int main() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
        }
    }
    cin >> n >> m;
    for (int i = 1; i <= 5; i++) { // 行数
        for (int j = 1; j <= 5; j++) {
            if (i == n) cout << a[m][j] << ' ';
            else if (i == m) cout << a[n][j] << ' ';
            else cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}