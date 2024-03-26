#include<bits/stdc++.h>
using namespace std;
int A, B;
int x, y;

int exgcd(int a, int b) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int r = exgcd(b, a % b);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}

int main() {
	scanf("%d%d", &A, &B);
	int r = exgcd(A, B);
	while (x < 0) x += B;
	cout<<x<<endl;
	return 0;
}
