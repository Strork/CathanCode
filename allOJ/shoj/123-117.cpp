#include <bits/stdc++.h>
using namespace std;
int8_t a[100];
int len = 0;

int main() {
    int n;
    cin >> n;
    while (n) {
        a[++len] = n % -2;
        cout << n % -2 << ' ';
        n /= -2;
        if (n % 2) ++n;
    }
    cout << endl;
    for (int i = len; i >= 1; --i) {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
