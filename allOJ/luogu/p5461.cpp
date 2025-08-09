// #include <bits/stdc++.h>
// using namespace std;
// int a[1030][1030];
// int n;

// void pardon(int x, int y, int l) {
//     if (l <= 0) return;
//     for (int i = x; i <= x + l - 1; ++i) { // 修改左上角
//         for (int j = y; j <= y + l - 1; ++j) {
//             a[i][j] = 0;
//         }
//     }
//     pardon(x + l, y, l / 2);
//     pardon(x, y + l, l / 2);
//     pardon(x + l, y + l, l / 2);
// }

// int main() {
//     cin >> n;
//     n = pow(2, n); // 边长是 2^n 
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             a[i][j] = 1;
//         }
//     }
//     pardon(1, 1, n / 2); // 左上角的坐标（1,1），边长为n
//     for (int i = 1; i <= n; ++i) {
//         for (int j = 1; j <= n; ++j) {
//             cout << a[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int a[1100][1100];

void pardon(int n, int x, int y) {
    // 左上角的方形 赋值为0  i = x; i <= x + n/2 - 1    ，y 也一样
    
    if (n <= 2) return; // 边长小于等于2 无法继续分割
    // 分割剩下三个正方形
    pardon(n/2, x, y + n/2); // 右侧正方形
}

int main() {
    int n; // n 是局部变量
    cin >> n;
    n = pow(2, n);
    // 循环赋值为初始值 1  i = 1->n  j = 1->n
    
    return 0;
}