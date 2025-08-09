#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a, b;

int main() {
    cin >> n >> a >> b;
    cout << min(n*a, b);
    return 0;
}