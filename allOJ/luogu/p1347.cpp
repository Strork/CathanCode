#include <bits/stdc++.h>
using namespace std;
int base_rd[30], rd[30];
vector<int> a[30];
int ans[30];
int n, m;

int topSort() {
    stack<int> s;
    int cnt = 0, isp = 0, level = 0;
    bool equal_level = 0;
    for (int i = 1; i <= n; ++i) {
        rd[i] = base_rd[i];
        if (!rd[i]) s.push(i), ans[++cnt] = i, ++level; // 起点集合
    }
    if (level >= 2) equal_level = 1; // 如果同一层有多个节点，说明顺序不严格
    while (s.size()) {
        int x = s.top();
        s.pop();
        level = 0;
        for (auto y : a[x]) {
            --rd[y];
            if (!rd[y]) s.push(y), ans[++cnt] = y, ++isp, ++level; 
            // 统计除了起点之外的 节点关系
        }
        if (level >= 2) equal_level = 1; // 如果同一层有多个节点，说明顺序不严格
    }
    if (isp == n - 1 && !equal_level) return 1; // 有严格的顺序
    if (cnt != n) return 2; // 出现错误：环
    return 3; // 没法判断
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        string str;
        cin >> str;
        int x = str[0] - 'A' + 1, y = str[2] - 'A' + 1;
        a[x].push_back(y);
        ++base_rd[y];
        if (topSort() == 1) {
            printf("Sorted sequence determined after %d relations: ", i);
            for (int i = 1; i <= n; ++i) cout << char('A' + ans[i] - 1);
            cout << '.';
            return 0;
        } else if (topSort() == 2) {
            printf("Inconsistency found after %d relations.", i);
            return 0;
        } else if (i == m && topSort() == 3) {
            printf("Sorted sequence cannot be determined.");
            return 0;
        }
    }
    return 0;
}