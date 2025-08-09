#include <bits/stdc++.h>
using namespace std;
int x, y;
int ans[2000];
int cnt;

void f(int n) {
    if (n == 1) {
        cout << 'A';
        return;
    }
    f(n-1); // 输出左边的部分
    cout << char('A' + n - 1);
    f(n-1); // 输出右边的部分
}

string st(int n) {
    if (n == 1) return "A";
    return st(n-1) + char('A'+n-1) + st(n-1);
}

int main() {
    int n;
    cin >> n;
    // f(n);
    string a = st(n);
    cout << a << endl;
    return 0;
}