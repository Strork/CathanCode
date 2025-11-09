#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    int m = k;
    while (1) {
        bool wrong_kill = 0;
        int id = 0;
        for (int i = 0; i < k; ++i) { // kill
            id = (id + m) % (2 * k - i);
            if (id < k) {
                wrong_kill = 1;
                break;
            }
        }
        if (wrong_kill) ++m;
        else break;
    }
    cout << m + 1 << endl;
    return 0;
}