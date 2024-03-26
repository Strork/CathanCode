#include<bits/stdc++.h>
using namespace std;
int n;
int a[100100];
int sum = 0;

void solution() {
	for (int i = 1; i <= n; ++i) {
		int temp = sum;
		temp -= abs(a[i] - a[i - 1]);
		temp -= abs(a[i + 1] - a[i]);
		temp += abs(a[i + 1] - a[i - 1]);
		printf("%d\n", temp);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum += abs(a[i] - a[i - 1]);
	}
	sum += abs(a[n]);
	solution();
	return 0;
}
