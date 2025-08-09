#include <bits/stdc++.h>
using namespace std;
string mid, back;

void find(int x, int y, int l, int r) {
    if (x > y || l > r) return;
    for (int i = x; i <= y; ++i) { // 中序遍历找根 i
        if (mid[i] == back[r]) {
            cout << mid[i]; // 先序遍历，输出根
            find(x, i-1, l, l+i-x-1); // 左子树
            find(i+1, y, r-y+i, r-1); // 右子树
        }
    }
}

int main() {
    cin >> mid >> back;
    find(0, mid.size()-1, 0, back.size()-1);
    return 0;
}