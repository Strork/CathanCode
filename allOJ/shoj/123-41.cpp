#include<bits/stdc++.h>
using namespace std;
int k;

int main() {
    cin >> k;
    for (int i = 0; ; ++i) {
        int n = i+1;
        int sum = (n * (n+1)) >> 1;
        if (sum >= k) {
            cout << i - (sum - k) << ' ' << sum - k << endl;
            break;
        }
    }
    return 0;
}