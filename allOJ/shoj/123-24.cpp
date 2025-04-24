#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 1;
    while (ans * (ans+1) / 2 <= n) ++ans;
    cout << ans-1 << endl;
    return 0;
}