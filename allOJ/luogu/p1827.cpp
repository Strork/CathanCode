#include <bits/stdc++.h>
using namespace std;
string s1, s2;

void dfs(int x, int y, int a, int b) {
    if (x > y || a > b) return;
    for (int i = x; i <= y; i++) {
        if (s1[i] == s2[a]) { // 在中序遍历中找根
            dfs(x, i - 1, a + 1, a + i - x); // 左
            dfs(i + 1, y, a + i - x + 1, b); // 右
            cout << s1[i]; // 根
        }
    }
}

int main() {
    cin >> s1 >> s2; // 中，前
    dfs(0, s1.size(), 0, s2.size());
    return 0;
}