#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    string ans;
    cin >> ans; // 第一个字符串
    for (int i = 2; i <= n; ++i) {
        string s;
        cin >> s;
        if (s < ans) ans = s; // 如果 s 更小，存下来
    }
    cout << ans << endl;
    return 0;
}