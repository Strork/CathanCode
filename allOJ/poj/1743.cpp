#include<iostream>
#include<cctype>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;
int ch[20100];
int sa[20100];
int cnt[20100];
int height[20100];
int p[20100];
int temp[20100];
int rank[20100];
int q[20100];
int head,tail;
int n,m;

int read(){
	int k = 0;
	int f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		k = k*10 + ch-'0';
		ch = getchar();
	}
	return k*f;
}

inline bool rua(int x, int y, int l){
	return rank[x] == rank[y] && rank[x+l] == rank[y+l];
}
void doubling(){
	m = 100;
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

void solution(){
	int l = 1, r = n;
	int mid = (l+r) >> 1;
	while(l+1 < r){
		cout<<l<<"   "<<r<<endl;
		mid = (l+r) >> 1;
		head = 1, tail = 0;
		for(int i = 1; i <= n; ++i){
			if(height[i] >= mid){
				q[++tail] = i;
			}
			else{
				int minn = 123456789, maxx = -123456789;
				for(int i = head; i <= tail; ++i){
					if(sa[q[i]] < minn) minn = sa[q[i]];
					if(sa[q[i]] > maxx) maxx = sa[q[i]];
				}
				if(sa[q[1] - 1] < minn) minn = sa[q[1] - 1];
				if(sa[q[1] - 1] > maxx) maxx = sa[q[1] - 1];
				if(maxx - minn >= mid){
					l = mid;
					break;
				}
			}
		}
		if(l != mid) r = mid;
	}
	//cout<<l<<" "<<r<<endl;
	for(int i = 1; i <= n; ++i){
		if(height[i] >= r){
			q[++tail] = i;
		}
		else{
			int minn = 123456789, maxx = -123456789;
			for(int i = head; i <= tail; ++i){
				if(sa[q[i]] < minn) minn = sa[q[i]];
				if(sa[q[i]] > maxx) maxx = sa[q[i]];
			}
			if(sa[q[1] - 1] < minn) minn = sa[q[1] - 1];
			if(sa[q[1] - 1] > maxx) maxx = sa[q[1] - 1];
			if(maxx - minn >= r){
				printf("%d\n",r);
				return;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		if(height[i] >= l){
			q[++tail] = i;
		}
		else{
			int minn = 123456789, maxx = -123456789;
			for(int i = head; i <= tail; ++i){
				if(sa[q[i]] < minn) minn = sa[q[i]];
				if(sa[q[i]] > maxx) maxx = sa[q[i]];
			}
			if(sa[q[1] - 1] < minn) minn = sa[q[1] - 1];
			if(sa[q[1] - 1] > maxx) maxx = sa[q[1] - 1];
			if(maxx - minn >= l){
				printf("%d\n",l);
				return;
			}
		}
	}
	cout<<0<<endl;
}

int main(){
	freopen("a.txt","r",stdin);
	while(n = read()){
		for(int i = 1; i <= n; ++i) ch[i] = read();
		doubling();
		solution();
	}
	return 0;
}
