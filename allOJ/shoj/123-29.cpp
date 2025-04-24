#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (sum - a[i] <= a[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}