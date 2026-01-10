#include <bits/stdc++.h>
using namespace std;
int cnt[15];

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        int t = i;
        while (t) {
            cnt[t % 10]++;
            t /= 10;
        }
    }
    for (int i = 0; i <= 9; ++i) {
        cout << cnt[i] << ' ';
    }
    return 0;
}