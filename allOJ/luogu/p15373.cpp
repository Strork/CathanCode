#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x;

int main() {
    cin >> n;
    ll sum = 0;
    while (n--) {
        cin >> x;
        sum += x;
    }
    cout << sum << endl;
    return 0;
}