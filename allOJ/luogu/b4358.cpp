#include <bits/stdc++.h>
using namespace std;
int n;
int cnt;

int main() {
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        while (x) {
            ++cnt;
            x &= x-1;
        }
    }
    cout << cnt << ' ';
    if (cnt & 1) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}