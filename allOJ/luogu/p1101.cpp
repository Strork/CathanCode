#include <bits/stdc++.h>
using namespace std;
bool out[105][105];
char a[105][105];
int n;
struct start {
    int x, y;
}qd[10005];
int start_cnt;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}; // 从x正轴开始，逆时针八个方向x的坐标变化
int dy[]; // 定义

void dfs(int step) {
    for {
        dfs();
    }
}


int main() {
    cin >> n;
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = getchar();
            if (a[i][j] == 'y') qd[++start_cnt].x = i, qd[start_cnt].y = j;
        }
        getchar();
    }
    // 枚举起点
    return 0;
}