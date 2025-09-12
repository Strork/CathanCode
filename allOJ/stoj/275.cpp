#include <bits/stdc++.h>
using namespace std;
int a[230], b[230], c[230], lenc, lst;

string add(string x, string y) {
    for (int i = 0; i < x.size(); ++i) a[x.size() - i] = x[i] - '0';
    for (int i = 0; i < y.size(); ++i) b[y.size() - i] = y[i] - '0';
    lenc = 1;
    while (lenc <= x.size() || lenc <= y.size()) {
        c[lenc] = a[lenc] + b[lenc] + lst;
        lst = c[lenc] / 10;
        c[lenc] %= 10;
        ++lenc;
    }
    c[lenc] = lst;
    if (!c[lenc]) --lenc;
    string ans;
    for (int i = lenc; i >= 1; --i) ans += char(c[i] + '0');
    return ans;
}

int main() {
    string x, y;
    cin >> x >> y;
    cout << add(x, y);
    return 0;
}