#include<bits/stdc++.h>
using namespace std;
int sa[1000100];
int rank[1000100];
int temp[1000100];
int n, k;
int cnt[1000100];
int ch[1000100];
int height[1000100];
int p[1000100];
int m = 1000100;

inline bool rua(int x, int y, int l){
	return rank[x]==rank[y]&&rank[x+l]==rank[y+l];
}
void doubling(){
	for(int i = 1; i <= n; ++i) ++cnt[rank[i] = ch[i]];
	for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
	for(int i = 1; i <= n; ++i) sa[cnt[rank[i]]--] = i;
	for(int i, l = 1, pos = 0; pos < n; m = pos){
		for(pos = 0, i = n-l+1; i <= n; ++i) p[++pos] = i;
		for(i = 1; i <= n; ++i) if(sa[i] > l) p[++pos] = sa[i] - l;
		for(i = 1; i <= m; ++i) cnt[i] = 0;
		for(i = 1; i <= n; ++i) ++cnt[rank[i]];
		for(i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
		for(i = n; i; --i) sa[cnt[rank[p[i]]]--] = p[i];
		for(i = 1, pos = 0; i <= n; ++i)
			temp[sa[i]] = rua(sa[i], sa[i-1], l) ? pos : ++pos;
		for(i = 1; i <= n; ++i) rank[i] = temp[i];
		l <<= 1;
	}
	for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for(int i = 1, pos, j = 0; i <= n; ++i){
		if(!(pos = sa[rank[i] - 1])){
			j = 0;
			continue;
		}
		if(j) --j;
		while(ch[i+j] == ch[pos+j]) ++j;
		height[rank[i]] = j;
	}
	//for(int i = 1; i <= n; ++i) cout<<height[i]<<' ';cout<<endl;
}

void solution(){
	int l = 0, r = n, sum = 1;
	int mid = (l+r)>>1;
	while(l+1 < r){
		mid = (l+r)>>1;
		sum = 1;
		for(int i = 1; i <= n; ++i){
			if(height[i] >= mid) ++sum;
			else sum = 1;
			if(sum >= k) break;
		}
		//cout<<l<<"  "<<r<<endl;
		if(sum >= k) l = mid;
		else r = mid;
	}
	for(int i = 1; i <= n; i++){
		if(height[i] >= r) ++sum;
		else sum = 1;
		if(sum >= k){
			printf("%d\n",r);
			return;
		}
	}
	for(int i = 1; i <= n; ++i){
		if(height[i] >= l) ++sum;
		else sum = 1;
		if(sum >= k){
			printf("%d\n",l);
			return;
		}
	}
	printf("0\n");
}

int main(){
	//freopen("a.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; ++i) scanf("%d",&ch[i]);
	doubling();
	solution();
	return 0;
}
