#include<bits/stdc++.h>
using namespace std;
double x;
int n;

double f(int a) {
    if (a == 1) return x/(1+x);
    return x / (a+f(a-1));
}

int main() {
    cin >> x >> n;
    printf("%.2lf", f(n));
    return 0;
}