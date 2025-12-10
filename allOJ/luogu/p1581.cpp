#include <bits/stdc++.h>
using namespace std;
vector<int> a, b, c;
string str;
int p[] = {2, 3, 5, 7, 11, 13};

void add() {
    int i = 0, la = a.size(), lb = b.size();
    bool flag = 0;
    while (i < la && i < lb) {
        c.push_back(a[i] + b[i]);
        if (flag) c[i]++;
        if (c[i] >= p[i]) c[i] -= p[i], flag = 1;
        else flag = 0;
        ++i;
    }
    while (i < la) {
        c.push_back(a[i]);
        if (flag) c[i]++;
        if (c[i] >= p[i]) c[i] -= p[i], flag = 1;
        ++i;
    }
    while (i < lb) {
        c.push_back(b[i]);
        if (flag) c[i]++;
        if (c[i] >= p[i]) c[i] -= p[i], flag = 1;
        ++i;
    }
    if (flag) c.push_back(1);
    for (int i = c.size() - 1; i; --i) printf("%d,", c[i]);
    printf("%d\n", c[0]);
}

int main() {
    cin >> str;
    int k = 0;
    bool flag = 0;
    for (auto ch : str) {
        if (ch == ',') {
            if (flag) b.push_back(k);
            else a.push_back(k);
            k = 0;
        }
        else if (ch == '+') {
            a.push_back(k);
            k = 0;
            flag = 1;
        }
        else k = k * 10 + ch - '0';
    }
    b.push_back(k);
    reverse(a.begin(), a.end());
    // for (auto aa : a) cout << aa << ' '; cout << endl;
    reverse(b.begin(), b.end());
    // for (auto aa : b) cout << aa << ' '; cout << endl;
    add();
    return 0;
}