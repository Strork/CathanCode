#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#define ll long long
using namespace std;
int T, n, m;
int sa[1010];
int cnt[1010];
int height[1010];
int temp[1010];
int p[1010];
char ch[1010];
int rank[1010];

inline bool rua(int x, int y, int l){
	return rank[x] == rank[y] && rank[x+l] == rank[y+l];
}

void doubling(){
	int m = 265;
	memset(cnt,0,sizeof(cnt));
	for(int i = 1; i <= n; ++i) ++cnt[rank[i] = ch[i]];
	for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
	for(int i = 1; i <= n; ++i) sa[cnt[rank[i]]--] = i;
	for(int i, pos = 0, l = 1; pos < n; m = pos, l <<= 1){
		for(i = n-l+1, pos = 0; i <= n; ++i) p[++pos] = i;
		for(i = 1; i <= n; ++i) if(sa[i] > l) p[++pos] = sa[i] - l;
		for(i = 1; i <= m; ++i) cnt[i] = 0;
		for(i = 1; i <= n; ++i) ++cnt[rank[i]];
		for(i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
		for(i = n; i; --i) sa[cnt[rank[p[i]]]--] = p[i];
		for(pos = 0, i = 1; i <= n; ++i)
			temp[sa[i]] = rua(sa[i], sa[i-1], l) ? pos : ++pos;
		for(i = 1; i <= n; ++i) rank[i] = temp[i];
	}
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
	for(int i = 1; i <= n; ++i){
		ans += n - sa[i] + 1 - height[i];
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",ch+1);
		n = strlen(ch+1);
		doubling();
		solution();
	}
	return 0;
}
