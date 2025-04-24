#include<bits/stdc++.h>
using namespace std;
int n;

int main() {
    cin >> n;
    for (int i = n; i >= 1; --i) {
        printf("**");
        for (int j = 1; j <= i; ++j) printf(" ");
        for (int j = 1; j <= i; ++j) printf("*");
        printf("\n");
    }
    printf("***\n");
    for (int i = 1; i <= n; ++i) {
        printf("**");
        for (int j = 1; j <= i; ++j) printf(" ");
        for (int j = 1; j <= i; ++j) printf("*");
        printf("\n");
    }
    return 0;
}