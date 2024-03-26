#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int p[1001000];
int sa[1001000];
char s[1001000];
int cnt[1001000];
char ch[1001000];
int temp[1001000];
int rank[1001000];
int height[1001000];
int t;

inline bool rua(int x, int y, int l) {
	return rank[x] == rank[y] && rank[x + l] == rank[y + l];
}
void doubling() {
	m = 260;
	for (int i = 1; i <= n; ++i) ++cnt[rank[i] = s[i]];
	for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
	for (int i = n; i; --i) sa[cnt[rank[i]]--] = i;
	for (int i, l = 1, pos = 0; pos < n; m = pos, l <<= 1) {
		for (pos = 0, i = n - l + 1; i <= n; ++i) p[++pos] = i;
		for (i = 1; i <= n; ++i) if (sa[i] > l) p[++pos] = sa[i] - l;
		for (i = 1; i <= m; ++i) cnt[i] = 0;
		for (i = 1; i <= n; ++i) ++cnt[rank[i]];
		for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
		for (i = n; i; --i) sa[cnt[rank[p[i]]]--] = p[i];
		for (i = 1, pos = 0; i <= n; ++i) {
			temp[sa[i]] = rua(sa[i], sa[i - 1], l) ? pos : ++pos;
		}
		for (i = 1; i <= n; ++i) rank[i] = temp[i];
	}
}

void get_height() {
	for (int i = 1, j = 0, pos; i <= n; ++i) {
		if (!(pos = sa[rank[i] - 1])) {
			j = 0;
			continue;
		}
		if (j) --j;
		while (s[pos + j] == s[i + j]) ++j;
		height[rank[i]] = j;
	}
}

void solution() {
	
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", s + 1);
	scanf("%s", ch + 1);
	s[n + 1] = '#';
	for (int i = 1; i <= m; ++i) s[i + 1 + n] = ch[i];
	n = n + m + 1;
	doubling();
	get_height();
	solution();
	return 0;
}
