#include <bits/stdc++.h>
using namespace std;
int a;
string s, b;
int x;

int main() {
    scanf("%d.", &a);
    cin >> s;
    bool flag = 0;
    for (auto c : s) {
        if (c == 'e') {
            flag = 1;
            continue;
        }
        if (!flag)
            b += c;
        else
            x = x * 10 + c - '0';
    }
    if (a == 0)
        cout << "0." << b << endl;
    else {
        cout << a;
        if (x <= b.size()) {
            for (int i = 0; i < x; ++i) cout << b[i];
            int t = x - b.size();
            if (t) cout << '.' << b.substr(x);
        } else {
            cout << b;
            for (int i = 1; i <= x - b.size(); ++i) cout << '0';
        }
    }
    return 0;
}