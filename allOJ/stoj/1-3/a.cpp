#include <bits/stdc++.h>
using namespace std;

int main() {
    string cici, bai;
    int ans = 0; // 统计平局次数
    cin >> cici >> bai; // 斯斯 和 小白 的出拳字符串
    int n = min(bai.size(), cici.size()); // 一个人累了就停，所以看谁小
    for (int i = 0; i < n; ++i) { // 枚举每个位置上的出拳
        if (cici[i] == bai[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}