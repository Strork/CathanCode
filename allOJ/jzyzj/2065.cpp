#include<bits/stdc++.h>
using namespace std;
int p[200100];
int sa[200100];
char ch[200100];
int cnt[200100];
int temp[200100];
int rank[200100];
int height[200100];
int n, m;
int len;

inline bool rua(int x, int y, int l){
	return rank[x] == rank[y] && rank[x+l] == rank[y+l];
}

void doubling(){
	m = 300;
	memset(cnt,0,sizeof(cnt));
	for(int i = 1; i <= n; ++i) ++cnt[rank[i] = ch[i]];
	for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
	for(int i = n; i; --i) sa[cnt[rank[i]]--] = i;
	for(int pos = 0, i, l = 1; pos < n; m = pos, l <<= 1){
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
	for(int i = 1, j = 0, k; i <= n; ++i){
		if(!(k = sa[rank[i] - 1])){
			j = 0;
			continue;
		}
		if(j) --j;
		while(ch[i+j] == ch[k+j]) ++j;
		height[rank[i]] = j;
	}
}

void solution()
{
	int maxx = 0, id;
	for(int i = 1; i <= n; ++i){
		if(height[i] > maxx) maxx = height[i];
	}
	for(int i = 2; i <= n; ++i){
		if(height[i] == maxx){
			id = min(id, min(sa[i], sa[i-1]));
		} 
	}
	for(int i = id; i <= id+maxx-1; ++i) printf("%c",ch[i]);putchar('\n');
}

int main(){
	scanf("%s",ch+1);
	len = strlen(ch+1);
	int id = len*2+1;
	for(int i = 1; i <= len; ++i) ch[id--] = ch[i];
	ch[len+1] = '#';
	n = len*2+1;
	doubling();
	solution();
	return 0;
}
