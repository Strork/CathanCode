#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
using namespace std;
int sa[1000100];
int rank[1000100];
int p[1000100];
int temp[1000100];
char ch[1000100];
int cnt[1000100];
int height[1000100];
int f[1000100];
int n, m;

inline bool rua(int x, int y, int l){
	return rank[x] == rank[y] && rank[x+l] == rank[y+l];
}
void doubling(){
	m = 260;
	memset(cnt,0,sizeof(cnt));
	for(int i = 1; i <= n; ++i) ++cnt[rank[i] = ch[i]];
	for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
	for(int i = 1; i <= n; ++i) sa[cnt[rank[i]]--] = i;
	for(int i, pos = 0, l = 1; pos < n; m = pos, l <<= 1){
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

void getheight(){
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

void ST(int k){
	f[k] = height[k];
	f[k+1] = height[k+1];
	for(int i = k-1; i; --i) f[i] = min(f[i+1], height[i]);
	for(int i = k+2; i <= n; ++i) f[i] = min(f[i-1], height[i]);
	//for(int i = 1; i <= n; ++i) cout<<f[i]<<' ';cout<<endl;
}

void solution(){
	int x = rank[1];
	ST(x);
	for(int k = 1; k <= n; ++k){
		if(n % k != 0) continue;
		int y = rank[k+1];
		int temp = f[y+1];
		if(temp == n - k){
			printf("%d\n",n/k);
			return;
		}
	}
}

int main(){
	//freopen("a.txt","r",stdin);
	while(1){
		scanf("%s",ch+1);
		if(ch[1] == '.') break;
		n = strlen(ch+1);
		doubling();
		getheight();
		solution();
	}
	return 0;
}
