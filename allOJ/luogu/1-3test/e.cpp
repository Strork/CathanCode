#include <bits/stdc++.h>
using namespace std;
int n;
int a[15];
double l, r;

double getx(double x) {
    double sum = 0.0;
    for (int i = n; i >= 0; --i) {
        sum = sum * x + a[i];
    }
    return sum;
}

int main() {
    cin >> n >> l >> r;
    for (int i = n; i >= 0; --i) cin >> a[i];
    while (l + 0.000001 <= r) {
        double mid = (l + r) / 2.0;
        double midl = mid - 0.000001;
        double midr = mid + 0.000001;
        double x = getx(midl);
        double y = getx(mid);
        double z = getx(midr);
        if (x < y && y < z) l = mid;
        else if (x > y && y > z) r = mid;
        else {
            l = mid;
            break;
        }
    }
    printf("%.5lf", l);
    return 0;
}