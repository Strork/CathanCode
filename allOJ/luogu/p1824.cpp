#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000005];
int b[1000005];
int n;
ll ans;

void mergeSort(int s, int t) {
    if (s == t) return; // 一个数不用分d
    int mid = s + t >> 1;
    mergeSort(s, mid); // 拆左半边
    mergeSort(mid + 1, t); // 右半边
    int i = s, j = mid + 1, k = s;
    while (i <= mid && j <= t) { // 判断边界
        if (a[i] <= a[j]) b[k++] = a[i++]; // b[k] = a[i]; i+=1, k+=1;
        else b[k++] = a[j++], ans += mid - i + 1;
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= t) b[k++] = a[j++]; // 谁没取完，执行哪个
    for (int i = s; i <= t; ++i) a[i] = b[i];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    mergeSort(1, n);
    cout << ans << endl;
    return 0;
}