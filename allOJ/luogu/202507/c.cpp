#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, x, y;

int main() {
    cin >> n >> x >> y;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (x < a) {
            cout << x;
            return 0;
        }
        x = x - a + b;
        if (x >= y) {
            cout << x;
            return 0;
        }
    }
    cout << x;
    return 0;
}