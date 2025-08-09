#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    cin >> s; // 由于修改后的字符串只有数字，可以推断出输入没有空格
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'O') cout << '0';
        else if (s[i] == 'l') cout << '1';
        else if (s[i] == 'Z') cout << '2';
        else if (s[i] == 'S') cout << '5';
        else if (s[i] == 'b') cout << '6';
        else if (s[i] == 'B') cout << '8';
        else if (s[i] == 'q') cout << '9';
        else cout << s[i]; // 没错误，输出本来的数字
    }
    return 0;
}