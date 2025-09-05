#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
int a[1000005];
int b[1000005];
ll ans = 0;

void mergeSort(int l, int r) {
    if (l == r) return;
    int mid = (l+r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++], ans += mid - i + 1;
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l; i <= r; ++i) a[i] = b[i];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    mergeSort(1, n);
    cout << ans << endl;
    return 0;
}