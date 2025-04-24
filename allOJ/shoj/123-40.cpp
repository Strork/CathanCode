#include<bits/stdc++.h>
using namespace std;
int n;
int sum[3];

int main() {
    cin >> n;
    for (int i = 0; i*i <= n; ++i) {
        sum[0] = i*i;
        for (int j = i; j*j <= n; ++j) {
            sum[1] = sum[0] + j*j;
            if (sum[1] > n) break;
            for (int k = j; k*k <= n; ++k) {
                sum[2] = sum[1] + k*k;
                if (sum[2] > n) break;
                for (int l = k; l*l <= n; ++l)
                    if (sum[2] + l*l == n) 
                        printf("%d %d %d %d\n", i, j, k, l);
            }
        }
    }
    return 0;
}