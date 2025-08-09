#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
int n;
int suger;

int main() {
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        suger = max(suger+1, x);
        ans += suger;
    }
    cout << ans << endl;
    return 0;
}