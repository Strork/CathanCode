#include<bits/stdc++.h>
using namespace std;
char ch[100100];
char s[200100];
int p[200100];

int init() {
	scanf("%s",ch+1);
	int len = strlen(ch+1);
	s[0] = '!';
	s[1] = '#';
	int t = 2;
	for (int i = 1; i <= len; ++i) {
		s[t++] = ch[i];
		s[t++] = '#';
	}
	s[t] = '\0';
	return t;
}

void manachar() {
	int len = init();
	int ans = -100;
	int mx = 0;
	int id;
	for (int i = 1; i < len; ++i) {
		if (i < mx) p[i] = min(p[2 * id - i], mx - i);
		else p[i] = 1;
		while (s[i + p[i]] == s[i - p[i]]) ++p[i];
		if (mx < i + p[i]) {
			mx = i + p[i];
			id = i;
		}
		ans = max(ans, p[i] - 1);
	}
	for (int i = 1; i < len; ++i) {
		if (p[i] - 1 == ans) {
			id = i;
			break;
		}
	}
	//cout<<id<<endl;
	for (int i = id - p[id] + 1; i <= id + p[id] - 1; ++i)
		if(s[i] != '#') putchar(s[i]);
	putchar('\n');
}

int main() {
	manachar();
	return 0;
}
