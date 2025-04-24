#include<bits/stdc++.h>
using namespace std;
string s;
string ans;

int getDecimal(string str) {
    int resp = 0;
    int t = 1;
    for (int i = 7; i >= 0; --i) {
        if (str[i] == '1') resp += t;
        t = t * 2;
    }
    return resp;
}

int main() {
    cin >> s;
    for (int i = 0; i < 4; ++i) {
        int t = getDecimal(s.substr(i*8, 8));
        if (i <= 2) cout << t << '.';
        else cout << t << endl;
    }
    return 0;
}
