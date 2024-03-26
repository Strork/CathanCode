#include<bits/stdc++.h>
#define ll long long
#define reg register int
#define up(i,j,k)	for(reg i = j; i <= k; ++i)
#define down(i,j,k)	for(reg i = j; i >= k; --i)

int n;
struct qaq {
	int x, y;
}star[60100];

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

void init() {
	n = read();
	up(i, 1, n) {
		star[i].x = read();
		star[i].y = read();
	}
}

int main() {
	init();
	
	return 0;
}
