#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main() {
    cin >> a >> b >> c;
    bool f = 1;
    if (a + b + c > 100) f = 0;
    if (b % 5 != 0) f = 0;
    if (c % 7 != 0) f = 0;
    if (a-b <= b-c) f = 0;
    if (f) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}