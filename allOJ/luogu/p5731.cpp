#include <bits/stdc++.h>
using namespace std;
int a[15][15]; // 二维数组
int d[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}}; // down left up right

int main() {
    int n;
    cin >> n;
    int x = 1, y = n; // 当前坐标
    int direction = 0; // 从向下开始
    for (int i = 0; i <= n + 1; ++i) { // 四周的边界标记为 1
        a[0][i] = 1;
        a[n + 1][i] = 1;
        a[i][0] = 1;
        a[i][n + 1] = 1;
    }
    for (int num = 1; num <= n * n; ++num) { // 填的数字
        a[x][y] = num;
        int nx = x + d[direction][0], ny = y + d[direction][1]; // 下一步
        if (a[nx][ny] == 0) x = nx, y = ny; // 满足条件向下走
        // 换向
        direction++; direction %= 4;
    }
    return 0;
}