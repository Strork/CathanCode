#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    string str;
    int repeat = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') { // 读取重复的字符串
            i++;
            str = "";
            while (1) {
                str += s[i];
                i++;
                if (s[i] == ')' && s[i + 1] == '[') break;
            }
        } // 循环停止时，s[i] == )
        i++; // 理应 s[i] == '['
        if (s[i] == '[') { // 统计括号内的次数
            i++; 
            repeat = 0;
            while (s[i] != ']') {
                repeat = repeat * 10 + s[i] - '0';
                i++;
            }
            while (repeat > 0) {
                cout << str; // 输出
                repeat--;
            }
        } // 结束时，s[i] = ']'
    }
    return 0;
}