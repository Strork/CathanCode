#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    bool regular = true;
    while (n > 1) {
        if ((n & 1) == 0) n >>= 1;
        else if (n % 3 == 0) n /= 3;
        else if (n % 5 == 0) n /= 5;
        else {
            regular = false;
            break;
        }
    }
    if (regular) cout << "Regular Number" << endl;
    else cout << "Irregular Number" << endl;
    return 0;
}