#include<bits/stdc++.h>
using namespace std;
int y, w;
int d[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    cin >> y >> w;
    if ((y%4==0 && y%100!=0) || y%400==0) d[2] = 29;
    for (int i = 1; i <= 12; ++i) {
        for (int j = 1; j <= d[i]; ++j) {
            if (j == 13 && w == 5) cout << i << endl;
            ++w;
            if (w == 8) w = 1;
        }
    }
    return 0;
}
