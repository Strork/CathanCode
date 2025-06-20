#include <bits/stdc++.h>
using namespace std;
int n;
struct student {
    int id;
    int base;
    int ex;
    int score;
    int getSum() {
        return base + ex;
    }
}a[1005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].id >> a[i].base >> a[i].ex;
        a[i].score = a[i].base * 7 + a[i].ex * 3;
        if (a[i].getSum() > 140 && a[i].score >= 800) cout << "Excellent" << endl;
        else cout << "Not excellent" << endl;
    }
    return 0;
}