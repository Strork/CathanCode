#include <bits/stdc++.h>
using namespace std;
int n;
char ans[40];
int len = 0;

int main() {
    cin >> n;
    while (n) {
        ans[++len] = n % 3 + '0';
        n /= 3;
    }
    for (int i = len; i >= 1; --i) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}