// #include <bits/stdc++.h>
// using namespace std;
// string mid, back;

// void find(int x, int y, int l, int r) {
//     if (x > y || l > r) return;
//     for (int i = x; i <= y; ++i) { // 中序遍历找根 i
//         if (mid[i] == back[r]) {
//             cout << mid[i]; // 先序遍历，输出根
//             find(x, i-1, l, l+i-x-1); // 左子树
//             find(i+1, y, r-y+i, r-1); // 右子树
//         }
//     }
// }

// int main() {
//     cin >> mid >> back;
//     find(0, mid.size()-1, 0, back.size()-1);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
string b, c;

void dfs(int l, int r, int x, int y) {
    if (l > r || x > y) return;
    for (int i = l; i <= r; ++i) {
        if (c[y] == b[i]) {
            cout << b[i];
            dfs(l, i - 1, x, x + i - l - 1);
            dfs(i + 1, r, x + i - l, y - 1);
        }
    }
}

int main() {
    cin >> b >> c;
    dfs(0, b.size() - 1, 0, b.size() - 1);    
    return 0;
}