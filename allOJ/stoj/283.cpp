#include <bits/stdc++.h>
using namespace std;
int n;
string A;
int a[10055], b[10055];
int step;

inline int chto_int(char c) {
    if (isdigit(c)) return c - '0';
    return 10 + c - 'A'; 
}

inline char into_char(int c) {
    if (c <= 9) return '0' + c;
    return c - 10 + 'A';
}

int main() {
    cin >> n >> A;
    while (step <= 10) {
        string B = A;
        reverse(B.begin(), B.end());
        if (B == A) {
            printf("STEP=%d", step);
            return 0;
        }
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        a[0] = A.size(), b[0] = B.size();
        for (int i = 1; i <= a[0]; ++i) a[i] = chto_int(A[a[0] - i]);
        for (int i = 1; i <= b[0]; ++i) b[i] = chto_int(B[b[0] - i]);
        for (int i = 1; i <= a[0]; ++i) {
            a[i] += b[i];
            if (a[i] >= n) {
                a[i + 1]++;
                a[i] -= n;
            }
        }
        int k = a[0];
        if (a[a[0] + 1]) k = a[0] + 1;
        step++;
        A = "";
        for (int i = 1; i <= k; ++i) A += into_char(a[i]);
        reverse(A.begin(), A.end());
    }
    cout << "Impossible!" << endl;
    return 0;
}