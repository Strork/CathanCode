#include<bits/stdc++.h>
using namespace std;
int sa[200100];
int height[200100];
int rank[200100];
char ch[200100];
char s[100100];
int p[200100];
int temp[200100];
int cnt[200100];
bool f[200100];
int n, m;

inline bool rua(int x, int y, int l){
	return rank[x] == rank[y] && rank[x+l] == rank[y+l];
}
void doubling(){
	m = 260;
	for(int i = 1; i <= n; ++i) ++cnt[rank[i] = ch[i]];
	for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
	for(int i = n; i; --i) sa[cnt[rank[i]]--] = i;
	for(int pos = 0, l = 1, i; pos < n; m = pos, l <<= 1){
		for(pos = 0, i = n-l+1; i <= n; ++i) p[++pos] = i;
		for(i = 1; i <= n; ++i) if(sa[i] > l) p[++pos] = sa[i] - l;
		for(i = 1; i <= m; ++i) cnt[i] = 0;
		for(i = 1; i <= n; ++i) ++cnt[rank[i]];
		for(i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
		for(i = n; i; --i) sa[cnt[rank[p[i]]]--] = p[i];
		for(pos = 0, i = 1; i <= n; ++i)
			temp[sa[i]] = rua(sa[i], sa[i-1], l) ? pos : ++pos;
		for(i = 1; i <= n; ++i) rank[i] = temp[i];
	}
}

void get_height(){
	for(int i = 1, k, j = 0; i <= n; ++i){
		if(!(k = sa[rank[i] - 1])){
			j = 0;
			continue;
		}
		if(j) --j;
		while(ch[i+j] == ch[k+j]) ++j;
		height[rank[i]] = j;
	}
}

void solution(){
	int ans = 0;
	for(int i = 2; i <= n; ++i){
		if(height[i] > ans && f[sa[i]] != f[sa[i-1]]) ans = height[i];
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%s",ch+1);
	n = strlen(ch+1);
	for(int i = 1; i <= n; ++i) f[i] = 1;
	scanf("%s",s+1);
	ch[++n] = '#';
	int len = strlen(s+1);
	for(int i = 1; i <= len; ++i) ch[++n] = s[i];
	doubling();
	get_height();
	solution();
	return 0;
}

