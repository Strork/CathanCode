#include <bits/stdc++.h>
using namespace std;
int cnt[1010];
int n, m;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int id;
        cin >> id;
        if (cnt[id] == 0) m++; // 第一次输入 id
        cnt[id]++; // cnt[id] = 1;
        // if (cnt[id] == 1) m++;
    }
    cout << m << endl;
    for (int i = 1; i <= 1000; ++i) {
        if (cnt[i]) cout << i << " ";
    }
    return 0;
}