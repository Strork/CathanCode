#include<cctype>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<ctime>
#define ll long long
#define sid 257777
#define reg register int
#define step 7

//using namespace std;

struct treap_node{
	int fix, val, tim, size, weight, id;
	int l, r;
}treap[sid + 100];

inline int left_size(int p) {
	return treap[p].l ? treap[treap[p].l].size : 0;
}
inline int right_size(int p) {
	return treap[p].r ? treap[treap[p].r].size : 0;
}

struct hash_string{
	char ch[15];
	int len;
}hash[sid + 100];

char str[15];
int n;
int tot = 0;
int root = 0;
int mark[sid + 100];
int taim[sid + 100];
int gamer = 0;

inline int read() {
	int k = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		k = k * 10 + ch - '0';
		ch = getchar();
	}
	return k * f;
}

int bkdr_hash() {
	int temp = 0;
	int seed = 131;
	int i = 1;
	int k = strlen(str + 1);
	while (i <= k) {
		temp = temp * seed + str[i];
		++i;
		temp %= sid;
	}
	return temp % sid;
}

int find() {
	int temp = bkdr_hash();
	while (strlen(hash[temp].ch + 1) && strcmp(hash[temp].ch + 1, str + 1)) {
		temp += step;
		if (temp > sid) temp -= sid;
	}
	return temp;
}

void treap_left_rotate(int &a) {
	int b = treap[a].r;
	treap[a].r = treap[b].l;
	treap[b].l = a;
	a = b;
	b = treap[a].l;
	treap[b].size = left_size(b) + right_size(b) + treap[b].weight;
	treap[a].size = left_size(a) + right_size(a) + treap[a].weight;
}

void treap_right_rotate(int &a) {
	int b = treap[a].l;
	treap[a].l = treap[b].r;
	treap[b].r = a;
	a = b;
	b = treap[a].r;
	treap[b].size = left_size(b) + right_size(b) + treap[b].weight;
	treap[a].size = left_size(a) + right_size(a) + treap[a].weight;
}

void treap_insert(int &p, int val, int tim, int id) {
	//if (id == 255039) printf("---------%d--------\n", p);
	if (!p) {
		p = ++tot;
		treap[p].val = val;
		treap[p].fix = rand() * rand() % 19260817;
		treap[p].tim = tim;
		treap[p].id = id;
		treap[p].weight = 1;
		treap[p].size = 1;
		mark[id] = val;
		taim[id] = tim;
		return;
	}
	else if (val > treap[p].val) {
		treap_insert(treap[p].l, val, tim, id);
		++treap[p].size;
		if (treap[treap[p].l].fix < treap[p].fix) 
			treap_right_rotate(p);
	}
	else if (val < treap[p].val) {
		treap_insert(treap[p].r, val, tim, id);
		++treap[p].size;
		if (treap[treap[p].r].fix < treap[p].fix) 
			treap_left_rotate(p);
	}
	else {
		if (tim < treap[p].tim) {
			treap_insert(treap[p].l, val, tim, id);
			++treap[p].size;
			if (treap[treap[p].l].fix < treap[p].fix)
				treap_right_rotate(p);
		}
		else {
			treap_insert(treap[p].r, val, tim, id);
			++treap[p].size;
			if (treap[treap[p].r].fix < treap[p].fix)
				treap_left_rotate(p);
		}
	}
}

void treap_delete(int &p, int id) {
	if (!p) return;
	if (treap[p].id == id) {
		if ((!treap[p].r) || (!treap[p].l)) {
			if (treap[p].l) p = treap[p].l;
			else if (treap[p].r) p = treap[p].r;
			else p = 0;
			return;
		}
		else {
			if (treap[treap[p].l].fix < treap[treap[p].r].fix) {
				treap_right_rotate(p);
				treap_delete(treap[p].r, id);
				--treap[p].size;
			}
			else {
				treap_left_rotate(p);
				treap_delete(treap[p].l, id);
				--treap[p].size;
			}
		}
	}
	else if (mark[id] > treap[p].val) {
		treap_delete(treap[p].l, id);
		--treap[p].size;
	}
	else if (mark[id] < treap[p].val){
		treap_delete(treap[p].r, id);
		--treap[p].size;
	}
	else {
		if (taim[id] < treap[p].tim) {
			treap_delete(treap[p].l, id);
			--treap[p].size;
		}
		else {
			treap_delete(treap[p].r, id);
			--treap[p].size;
		}
	}
}

int treap_rank(int p, int id, int cur) {
	if (!p) return 0;
	if (treap[p].id == id) 
		return left_size(p) + 1 + cur;
	else if (mark[id] > treap[p].val) 
		return treap_rank(treap[p].l, id, cur);
	else if (mark[id] < treap[p].val)
		return treap_rank(treap[p].r, id, cur + left_size(p) + treap[p].weight);
	else {
		if (taim[id] < treap[p].tim) 
			return treap_rank(treap[p].l, id, cur);
		else 
			return treap_rank(treap[p].r, id, cur + left_size(p) + treap[p].weight);
	}
}

int treap_kth(int p, int k) {
	if (k < left_size(p) + 1) return treap_kth(treap[p].l, k);
	else if (k > left_size(p) + treap[p].weight) 
		return treap_kth(treap[p].r, k - (left_size(p) + treap[p].weight));
	else return treap[p].id;
}

void init() {
	srand((unsigned)time(NULL));
	n = read();
	for (reg i = 1; i <= n; ++i) {	
		scanf("%s", str);
		int id;
		if (str[0] == '+') {
			id = find();
			int temp = read();
			if (mark[id]) {
				treap_delete(root, id);
				--treap[root].size;
			}
			else strcpy(hash[id].ch + 1, str + 1), ++gamer;
			treap_insert(root, temp, i, id);
		}
		else {
			if (!isdigit(str[1])) {
				id = find();
				int rank = treap_rank(root, id, 0);
				printf("%d\n", rank);
			}
			else {
				int k = 0;
				int cc = strlen(str + 1);
				for (int i = 1; i <= cc; ++i) k = k * 10 + str[i] - '0';
				int aa = k;
				int bb = k + 9;
				if (bb > gamer) bb = gamer;
				for (int i = aa; i <= bb; ++i) {
					id = treap_kth(root, i);
					printf("%s ", hash[id].ch + 1);
				}
				printf("\n");
			}
		}
		
	}
}

int main() {
	//freopen("a.txt", "r", stdin);
	//freopen("b.txt", "w", stdout);
	init();
	return 0;
}
