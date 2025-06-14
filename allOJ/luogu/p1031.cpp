#include <bits/stdc++.h>
using namespace std;
int n;
int a[105];
int ans, sum, target;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    target = sum / n;
    sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < target) {
            ++ans;
            int de = a[i] - target;
            a[i+1] += de;
            a[i] = target;
        } else if (a[i] > target) {
            ++ans;
            int de = a[i] - target;
            a[i+1] += de;
            a[i] = target;
        }
    }
    cout << ans;
    return 0;
}