#include <bits/stdc++.h>
using namespace std;
char ch[205];

int main() {
    cin.getline(ch, sizeof(ch));
    int cnt = 0;
    for (int i = 0; ch[i]; ++i) {
        if (ch[i] == ' ') ++cnt; 
        else {
            cnt = 0; // 不是空格，才会清零
        }
        if (cnt <= 1) cout << ch[i];
    }
    return 0;
}