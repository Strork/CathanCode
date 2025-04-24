#include<bits/stdc++.h>
using namespace std;
string tower1 = " /\\ ";
string tower2 = "/__\\";
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= ((n-i)<<1); ++j) putchar(' ');
        for (int j = 1; j <= i; ++j) cout << tower1;
        putchar('\n');
        for (int j = 1; j <= ((n-i)<<1); ++j) putchar(' ');
        for (int j = 1; j <= i; ++j) cout << tower2;
        putchar('\n');
    }
    return 0;
}