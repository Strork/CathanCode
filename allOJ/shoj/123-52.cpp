#include<bits/stdc++.h>
using namespace std;
int n;
enum numKind {Abundant, Deficient, Perfect};

int main() {
    int sum = -1;
    int ans;
    cin >> n;
    if (n >= 2) sum = 1;
    for (int i = 2; i*i < n; ++i) {
        if (n % i == 0) {
            sum += i;
            sum += n/i;
        }
        if (sum > n) {
            ans = Abundant;
            break;
        }
    }
    int t = sqrt(n);
    if (t*t == n) sum += t;
    if (sum == n) ans = Perfect;
    else if (sum > n) ans = Abundant;
    else ans = Deficient;
    if (ans == Abundant) cout << "Abundant" << endl;
    else if (ans == Perfect) cout << "Perfect" << endl;
    else if (ans == Deficient) cout << "Deficient" << endl;
    return 0;
}
