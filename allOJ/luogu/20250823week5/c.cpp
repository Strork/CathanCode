#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a;
    b = a;
    reverse(b.begin(), b.end());
    int n = a.size();
    int mid;
    if (n & 1) mid = n >> 1;
    else mid = n / 2 - 1;
    bool flag = 0;
    for (int i = mid + 1; i < n; ++i) {
        if (b[i] > a[i]) {
            flag = 1;
            break;
        }
        else if (b[i] < a[i]) {
            flag = 0;
            break;
        }
    }
    if (b == a) flag = 1;
    
    return 0;
}