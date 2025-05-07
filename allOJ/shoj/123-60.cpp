#include<bits/stdc++.h>
using namespace std;
int a, b;

int main() {
    cin >> a >> b;
    int ans = 0;
    if (b & 1) --b, ++ans;
    while (a < b) {
        int a2 = a << 1;
        int b2 = b >> 1;
        
    }
    return 0;
}