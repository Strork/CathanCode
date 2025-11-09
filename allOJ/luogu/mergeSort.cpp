#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int ans;
int n;

void mergeSort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l; // i 是左区间起点，j 是右区间起点，k 是整个区间起点
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k] = a[i], k++, i++;
        else b[k] = a[j], k++, j++, ans += mid - i + 1;
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (int i = l; i <= r; ++i) a[i] = b[i];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    mergeSort(1, n);
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}