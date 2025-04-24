#include<bits/stdc++.h>
using namespace std;
int a, b;

int main() {
    cin >> a >> b;
    int add = 0;
    int ans = 0;
    while (a || b) {
        if (a % 10 + b % 10 + add >= 10) {
            ++ans;
            add = 1;
        } else {
            add = 0;
        }
        a /= 10;
        b /= 10;
    }
    cout << ans << endl;
    return 0;
}