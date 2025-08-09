#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > 0) {
        if (b > 0) cout << "NorthEast" << endl;
        else cout << "NorthWest" << endl;
    }
    else {
        if (b > 0) cout << "SouthEast" << endl;
        else cout << "SouthWest" << endl;
    }
    return 0;
}