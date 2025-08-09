#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i+1] != '-') cout << s[i]; // 下一个不是减号， 不处理
        else {
            if (i+2 >= n || s[i] >= s[i+2]) { // 越界 或者 左边>=右边
                cout << s[i];
            }
            else if (s[i] < s[i+2] && s[i+2] - s[i] <= 26) { //不能是左数字右字母
                for (char j = s[i]; j < s[i+2]; ++j) {
                    cout << j; // j = s[i] ~ s[i+2]
                }
                i += 1; // 处理完了，跳过 - 号
            }
            else cout << s[i];
        }
    }
    return 0;
}