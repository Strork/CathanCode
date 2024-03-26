void add_node(int k, int node) {
    int ch = s[k] - 'a';
    if (!trie[node].lin[ch]) {
        trie[node].lin[ch] = ++len;
        trie[len].end = 0;
        trie[len].fail = 0;
    }
    if (k == slen) {
        trie[node].end = 1;//++trie[node].end;
        return;
    }
    add_node(k+1, trie[node].lin[ch]);
}

void build_fail() {
    head = tail = 0;
    q[tail] = 0;
    while (head <= tail) {
        int node = q[head++];
        int temp;
        for (int i = 0; i < 26; ++i) {
            if (trie[node].lin[i]) {
                int nt = trie[node].lin[i];
                if (node) {
                    temp = trie[node].fail;
                    while (!trie[temp].lin[i] && temp)
                        temp = trie[temp].fail;
                    trie[nt].fail = trie[temp].lin[i];
                }
                q[++tail] = nt;
            }
        }
    }
}

void find() {
    ans = 0;
    int node = 0;
    for (int i = 1; i <= len; ++i) {
        int ch = s[i] - 'a';
        while (!trie[node].lin[ch] && node)
            node = trie[node].fail;
        node = tire[node].lin[ch];
        int temp = node;
        while (temp) {
            if (trie[temp].end >= -1) {
                ans += trie[temp].end;
                trie[temp].end = -1;
            }
            temp = trie[temp].fail;
        }
    }
    printf("%d\n",ans);
}
