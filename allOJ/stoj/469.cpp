#include <bits/stdc++.h>
using namespace std;
int y, m, d;

int main() {
    cin >> y >> m >> d;
    if (m <= 12) {
        if (d <= 28) cout << "YES" << endl;
        else if (d >= 32) cout << "NO" << endl;
        else {
            if (m == 2) {
                if ((y%4==0&&y%100!=0 || y%400==0) )
            }
        }
    }
    return 0;
}