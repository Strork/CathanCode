#include <bits/stdc++.h>
using namespace std;
int f[305][305]; // 第一维度：根 第二维度：选了多少课（体积）
vector<int> a[305];
int grade[305];
int n, m;

int dfs(int x) {
    f[x][1] = grade[x]; // 选自己这门课获得的学分
    int p = 1; // 子节点数量（包括自己）
    for (auto y : a[x]) {
        int child = dfs(y); // 其实子节点就是课程数量(V)
        for (int i = 1; i <= child; ++i) { // 子树中选了 i 节课
            for (int j = min(p, m+1); j > i; --j) { // 最少你要把这门课选了吧 
                f[x][j] = max(f[x][j], f[x][j-i] + f[y][i]);
            }
        }
        p += child;
    }
    return p;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k >> grade[i];
        a[k].push_back(i);
    }
    dfs(0);
    cout << f[0][m+1] << endl;
    return 0;
}