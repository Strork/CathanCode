#include<bits/stdc++.h>
#define ll long long
#define reg register int

int T;
int L;
char o[10];
bool f[255];
char stk[210];
bool ifn[210];
int top = 0;
char num[10];
bool err;
int noww;
int maxx;
int stop;

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

inline int getnum() {
	int temp = 0;
	int len = strlen(num + 1);
	for (reg i = 1; i <= len; ++i) 
		temp = temp * 10 + num[i] - '0';
	return temp;
}

void work() {
	char ch = getchar(); getchar();
	if (ch == 'E') {
		ch = stk[top--];
		f[ch] = 0;
		if (top == -1) err = 1;
		else if (top == stop - 1 && stop) stop = 0;
		else if (ifn[top + 1]) {
			ifn[top + 1] = 0;
			--noww;
		}
	}
	else {
		ch = getchar();	getchar();
		if (f[ch]) err = 1;
		f[ch] = 1;
		stk[++top] = ch;
		scanf("%s", num + 1); getchar();
		int x = 0, y = 0;
		if (num[1] != 'n') x = getnum();
		scanf("%s", num + 1); getchar();
		if (num[1] != 'n') y = getnum();

		if (x) {
			if (y) {
				if (x > y) {
					if (!stop) stop = top;
				}
			}
			else if (!stop) {
				++noww;
				ifn[top] = 1;
				if (noww > maxx) maxx = noww;
			}
		}
		else {
			if (y) {
				if (!stop) stop = top;
			}
		}
	}
}

int main() {
	//freopen("a.txt", "r", stdin);
	T = read();
	while (T--) {
		err = 0;
		maxx = 0;
		top = 0;
		noww = 0;
		stop = 0;
		memset(f, 0, sizeof(f));
		memset(ifn, 0, sizeof(ifn));
		int n = read();
		//printf("n is %d \n", n);
		scanf("%s", o + 1); getchar();
		for (reg i = 1; i <= n; ++i) work();
		if (top) err = 1;
		if (err) {
			printf("ERR\n");
			continue;
		}
		else {
			if (o[3] == '1') {
				if (!maxx) printf("Yes\n");
				else printf("No\n");
			}
			else {
				int temp = 0;
				for (reg i = 5; ; ++i) {
					if (isdigit(o[i])) 
						temp = temp * 10 + o[i] - '0';
					else break;
				}
				if (temp == maxx) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}
