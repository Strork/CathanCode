#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int pg, pz;

int main() {
    cin >> a >> b >> c;
    pg = pz = a;
    while (pz >= b || pg >= c) {
        if (pz >= b) {
            ++a;
            pz -= b-1;
            ++pg;
        }
        if (pg >= c) {
            ++a;
            pg -= c-1;
            ++pz;
        }
    }
    cout << a << endl;
    return 0;
}