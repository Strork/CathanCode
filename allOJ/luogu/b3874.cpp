#include <bits/stdc++.h>
using namespace std;

void MergeSort(int l, int r) {
    int mid = l + r >> 1;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    int i = l, j = mid + 1;
    while (a[i] > a[j]) b[k++] = a[i++], ans += mid - i + 1;
    else b[k++] = b[j++];
}

int main() {
    
    return 0;
}