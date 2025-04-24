#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    for (int i = 1; i <= n; ++i) a = (a-1)<<1;
    cout << a << endl;
    return 0;
}