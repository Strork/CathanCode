#include<bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    while (n >= 2) {
        bool endpoint = false;
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) {
                printf("%d ", i);
                n /= i;
                endpoint = true;
                break;
            }
        }
        if (!endpoint) {
            cout << n << endl;
            break;
        }
    }
    return 0;
}
