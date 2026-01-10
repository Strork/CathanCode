// #include <bits/stdc++.h>
// using namespace std;
// int bt[100005][2];
// int n;
// char color[100005];
// int opt[100005];

// void dfs(int x) {
//     int l = bt[x][0], r = bt[x][1];
//     if (opt[x]) {
//         int l = bt[x][0], r = bt[x][1];
//         opt[l] ^= 1, opt[r] ^= 1;
//     }
//     if (l) dfs(l);
//     if (r) dfs(r);
// }

// int main() {
//     cin >> n;
//     for (int i = 2; i <= n; ++i) {
//         int fa;
//         cin >> fa;
//         if (!bt[fa][0]) bt[fa][0] = i;
//         else bt[fa][1] = i;
//     }
//     scanf("%s", color + 1);
//     int q;
//     cin >> q;
//     for (int i = 1; i <= q; ++i) {
//         int x;
//         cin >> x;
//         opt[x] ^= 1;
//     }
//     dfs(1);
//     for (int i = 1; i <= n; ++i) {
//         int c = color[i] - '0';
//         if (opt[i]) cout << (c^1);
//         else cout << c;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
vector<int> a[100005];  // 邻接表存树  vector 默认是空
int b[100005][2];       // 结构体（指针存树）  数组默认有一个 0
struct node {
    int l, r;
} c[100005];
int f[100005];
int n;

void dfs(int x) {
    // 把标记传给子节点（从父节点继承标记）
    // 遍历左右节点
    // for (int i = 0; i < a[x].size(); ++i) { int y = a[x][i];
    for (auto y : a[x]) {  // 缺点：没有下标 i，所以不知道是第几次循环
        // 现在，y 就是所有的 x 子节点
        // if (f[x] == 1) f[y] ^= 1;
        f[y] ^= f[x];  // 传递效果
        dfs(y);        // 不会无限调用
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int fa;
        cin >> fa;
        // if (b[fa][0] == 0) b[fa][0] = i; // 左节点空，放左边
        // else b[fa][1] = i;
        // if (c[fa].l == 0) c[fa].l = i;
        a[fa].push_back(i);
    }
    string str;
    cin >> str;
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int x;
        cin >> x;
        f[x] ^= 1;  // 异或 1 表示取反
    }
    dfs(1);
    // 按是否更改输出
    return 0;
}