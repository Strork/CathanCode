#include<bits/stdc++.h>
using namespace std;
char ch[1000100];
char s[2000100];
int p[2000100];
int T;
int len;

int init() {
	scanf("%s", ch + 1);
	len = strlen(ch + 1);
	int j = 2;
	s[0] = '!';
	s[1] = '#';
	for (int i = 1; i <= len; ++i) {
		s[j++] = ch[i];
		s[j++] = '#';
	}
	s[j] = '\0';
	return j - 1;
}

void manachar() {
	len = init();
	int id;
	int mx = 0;
	for (int i = 1; i <= len; ++i) {
		if (i < mx) p[i] = min(p[2 * id - i], mx - i);
		else p[i] = 1;
		while (s[i + p[i]] == s[i - p[i]]) ++p[i];
		if (mx < i + p[i]) {
			id = i;
			mx = i + p[i]; 
		}	
	}
}

void solution() {
	for(int k = 2;)
}

int main() {
	cin>>T;
	while (T--) {
		manachar();
		solution();
	}
	return 0;
}
