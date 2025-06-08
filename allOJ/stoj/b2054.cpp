#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int cnt = n;
    while (n--) {
        int t;
        cin >> t;
        sum += t;
    }
    printf("%.2lf\n", sum * 1.0 / cnt);
    string aa;
    aa.substr(3);
    return 0;
}
