#include<bits/stdc++.h>
using namespace std;

int main() {
    // 9 8 7 6 5 11 17 16 15 14 13 12 18 24 23 22 21 20 19
    int n;
    cin >> n;
    int week = 3;
    int kz = 9;
    for (int i = 1; i <= 2000; ++i) {
        if (kz == n) {
            cout << i << endl;
            break;
        }
        week = week % 7 + 1;
        if (week <= 2) kz += 6;
        else --kz;
    }
    return 0;
}
