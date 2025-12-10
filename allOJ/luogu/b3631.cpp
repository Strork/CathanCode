#include <bits/stdc++.h>
using namespace std;
int q;
list<int> a; // list<int> a(1, 1);

int main() {
    cin >> q;
    a.push_back(1);
    while (q--) {
        int opt; cin >> opt;
        if (opt == 1) { // 在 x 后面添加元素 y
            int x, y; cin >> x >> y;
            auto it = find(a.begin(), a.end(), x); // 寻找 x 的位置
            a.insert(++it, y); // 在 x 后面添加 y
        }
    }
    return 0;
}