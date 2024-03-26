#include<bits/stdc++.h>
using namespace std;
int f[1<<20];
int n;

inline int read() {
	char ch = getchar();
	int k = 0, f = 1;
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return k * f;
}

int main() {
	n = read();
	for (int i = 1; i < (1 << n); ++i)
		f[i] = read();
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = (i - 1) & i; j; j = (j - 1) & i)
			f[i] = max(f[i], f[j] + f[i - j]);
	}
	printf("%d\n", f[(1 << n) - 1]);
	return 0;
}

