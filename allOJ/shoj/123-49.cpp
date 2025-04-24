#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int sum[3];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ++sum[a[i]%3];
    }
    cout << min(sum[1], sum[2]) + (sum[0] >> 1) << endl;
    return 0;
}
