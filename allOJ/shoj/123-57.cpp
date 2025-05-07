#include<bits/stdc++.h>
using namespace std;
string s;
// sign num dot other
int f[7][4] = {
    {1, 2, 3, 6}, // 0 start
    {6, 2, 3, 6}, // 1 sign
    {6, 2, 4, 6}, // 2 num
    {6, 5, 6, 6}, // 3 dot
    {6, 5, 6, 6}, // 4 num-dot
    {6, 5, 6, 6}, // 5 dot-num
    {6, 6, 6, 6},// invalid
};

int getEvent(char c) {
    if (c == '+' || c == '-') return 0;
    if (c >= '0' && c <= '9') return 1;
    if (c == '.') return 2;
    return 3;
}

int main() {
    cin >> s;
    int sta = 0;
    for (auto i : s) {
        sta = f[sta][getEvent(i)];
    }
    if (sta == 2 || sta == 4 || sta == 5) cout << "Valid" << endl;
    else cout << "Invalid" << endl;
    return 0;
}
