#include<bits/stdc++.h>
using namespace std;
int sa[100100];
int cnt[100100];
int p[100100];
int temp[100100];
int rank[100100];
char ch[100100];
int height[100100];
int n, m = 256;

inline bool rua(int x, int y, int l){return rank[x]==rank[y]&&rank[x+l]==rank[y+l];}
void doubling(){
	for(int i = 1; i <= n; ++i) ++cnt[rank[i] = ch[i]];
	for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
	for(int i = n; i; --i) sa[cnt[rank[i]]--] = i;
	for(int i, l = 1, k = 0; k < n; m = k){
		for(k = 0,i = n-l+1; i <= n; ++i) p[++k] = i;
		for(i = 1; i <= n; ++i) if(sa[i] > l) p[++k] = sa[i] - l;
		for(i = 1; i <= m; ++i) cnt[i] = 0;
		for(i = 1; i <= n; ++i) ++cnt[rank[i]];
		for(i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
		for(i = n; i; --i) sa[cnt[rank[p[i]]]--] = p[i];
		for(i = 1, k = 0; i <= n; ++i)
			temp[sa[i]] = rua(sa[i], sa[i-1], l) ? k : ++k;
		for(i = 1; i <= n; ++i) rank[i] = temp[i];
		l *= 2;
	}
	for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for(int i = 1, k, j = 0; i <= n; ++i){
		if(!(k = sa[rank[i]-1])){
			j = 0;
			continue;
		}
		if(j) --j;
		while(ch[i+j] == ch[k+j]) ++j;
		height[rank[i]] = j;
	}
}

int main(){
	//freopen("a.txt","r",stdin);
	scanf("%d",&n);
	scanf("%s",ch+1);
	doubling();
	int ans = 0;
	for(int i = 1; i <= n; ++i) if(height[i] > ans) ans = height[i];
	printf("%d\n",ans);
	return 0;
}
