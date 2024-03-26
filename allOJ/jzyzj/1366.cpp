#include<bits/stdc++.h>
using namespace std;
struct qaq{
	int end;
	int lin[26];
	int fail;
}trie[501000];
int trielen = 0;
int n;
char s[1001000];
int len = 0;
int ans = 0;
int q[501000];
int head, tail;

void add_node(int k, int node){
	int ch = s[k] - 'a';
	if(!trie[node].lin[ch]){
		trie[node].lin[ch] = ++trielen;
		trie[trielen].end = 0;
		trie[trielen].fail = 0;
	}
	int nt = trie[node].lin[ch];
	if(k == len){
		++trie[nt].end;
		return;
	}
	add_node(k+1, nt);
}

void build_fail(){
	head = 0;
	tail = 0;
	q[tail] = 0;
	while(head <= tail){
		int node = q[head++];
		int temp;
		for(int i = 0; i < 26; ++i){
			if(trie[node].lin[i]){
				int nt = trie[node].lin[i];
				if(node){
					temp = trie[node].fail;
					while(temp && !trie[temp].lin[i])
						temp = trie[temp].fail;
					trie[nt].fail = trie[temp].lin[i];
				}
				q[++tail] = nt;
			}
		}
	}
}

void find(){
	ans = 0;
	int node = 0;
	for(int i = 1; i <= len; ++i){
		int ch = s[i] - 'a';
		while(!trie[node].lin[ch] && node)
			node = trie[node].fail;
		node = trie[node].lin[ch];
		int temp = node;
		while(temp && trie[temp].end > -1){
			ans += trie[temp].end;
			trie[temp].end = -1;
			temp = trie[temp].fail;
		}
	}
	printf("%d\n",ans);
}

int main(){
	//freopen("a.txt","r",stdin);
	memset(trie,0,sizeof(trie));
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		scanf("%s",s+1);
		len = strlen(s+1);
		//for(int j=1;j<=len;++j)cout<<s[j];cout<<endl;
		//cout<<i<<' '<<len<<endl;
		add_node(1,0);
	}
	build_fail();
	scanf("%s",s+1);
	len = strlen(s+1);
	find();
	return 0;
}
