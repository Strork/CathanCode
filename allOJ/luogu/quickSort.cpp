#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];

void quickSort(int l, int r) {
    int i = l, j = r, mid = a[l + r >> 1];
    while (i <= j) {
        while (a[i] < mid) ++i;
        while (a[j] > mid) --j;
        if (i <= j) swap(a[i++], a[j--]);
    }
    if (l < j) quickSort(l, j);
    if (i < r) quickSort(i, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    quickSort(1, n);
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}

void quickSort(int l, int r) {
    int piv = a[l];
    int i = l, j = r;
    while (i < j) {
        
    }
}