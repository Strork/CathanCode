#include<bits/stdc++.h>
using namespace std;
int sa[300100];
int cnt[300100];
int p[300100];
int height[300100];
int rank[300100];
int temp[300100];
int n, m;
char s[300100];
int f[300100][35];

bool rua(int x,int y,int l){
	return rank[x] == rank[y] && rank[x+l] == rank[y+l]; 
}

void doubling(){
	m = 260;
	for(int i = 1; i <= n; ++i) ++cnt[rank[i] = s[i]];
	for(int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
	for(int i = n; i; --i) sa[cnt[rank[i]]--] = i;
	for(int i, l = 1, k = 0; k < n; m = k){
		for(k = 0,i = n-l+1; i <= n; ++i) p[++k] = i;
		for(i = 1; i <= n; ++i) if(sa[i] > l) p[++k] = sa[i] - l;
		for(i = 1; i <= m; ++i) cnt[i] = 0;
		for(i = 1; i <= n; ++i) ++cnt[rank[i]];
		for(i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
		for(i = n; i; --i) sa[cnt[rank[p[i]]]--] = p[i];
		for(k = 0, i = 1; i <= n; ++i) 
			temp[sa[i]] = rua(sa[i], sa[i-1], l) ? k : ++k;
		for(i = 1; i <= n; ++i) rank[i] = temp[i];
		l <<= 1;
	}
	for(int i = 1; i <= n; ++i) rank[sa[i]] = i;
	for(int i = 1, j = 0, k; i <= n; ++i){
		if(!(k = sa[rank[i] - 1])){
			j = 0;
			continue;
		}
		if(j) --j;
		while(s[k+j] == s[i+j]) ++j;
		height[rank[i]] = j;
	}
	//for(int i = 1; i <= n; ++i) cout<<height[i]<<" ";cout<<height[n]<<endl;
}

void ST(){
	m = n-1;
	for(int i = 2; i <= n; ++i)
		f[i][0] = height[i];
	for(int j = 1; j <= 20; ++j)
		for(int i = 1; i+(1<<j)-1 <= n; ++i){
			f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
		}
	//for(int i= 0; i <= 3; i++) cout<<f[2][i]<<"----";cout<<endl;
}

void rangemin(int x,int y){
	int k = 0;
	while((1<<(k+1)) <= y-x+1) ++k;
	printf("%d\n",min(f[x][k], f[y-(1<<k)+1][k]));
}

int main(){
	//freopen("a.txt","r",stdin);
	//freopen("b.txt","w",stdout);
	scanf("%d",&n); 
	scanf("%s",s+1);
	doubling();
	//for(int i = 1; i <= m; i++) cout<<height[i]<<endl;
	ST();
	scanf("%d",&m);
	for(int i = 1; i <= m; ++i){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x == y) printf("%d\n",n-x+1);
		else{
			x = rank[x];
			y = rank[y];
			if(x > y) swap(x, y);
			rangemin(x+1, y);
		}
	}
	return 0;
}
