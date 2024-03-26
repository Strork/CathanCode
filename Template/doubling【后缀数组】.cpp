bool rua(int x, int y, int l) {
    return rank[x] == rank[y] && rank[x + l] == rank[y + l]; 
}

void doubling() {
    m = 260;
    for (int i = 1; i <= n; ++i) ++cnt[rank[i] = s[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i; --i) sa[cnt[rank[i]]--] = i;
    for (int i, l = 1, k = 0; k < n; m = k) {
        for (k = 0,i = n - l + 1; i <= n; ++i) p[++k] = i;
        for (i = 1; i <= n; ++i) if(sa[i] > l) p[++k] = sa[i] - l;
        for (i = 1; i <= m; ++i) cnt[i] = 0;
        for (i = 1; i <= n; ++i) ++cnt[rank[i]];
        for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i; --i) sa[cnt[rank[p[i]]]--] = p[i];
        for (k = 0, i = 1; i <= n; ++i) 
            temp[sa[i]] = rua(sa[i], sa[i-1], l) ? k : ++k;
        for (i = 1; i <= n; ++i) rank[i] = temp[i];
        l <<= 1;
    }
    for (int i = 1; i <= n; ++i) rank[sa[i]] = i;

    for (int i = 1, j = 0, k; i <= n; ++i) {
        if (!(k = sa[rank[i] - 1])) {
            j = 0;
            continue;
        }
        if (j) --j;
        while (s[k + j] == s[i + j]) ++j;
        height[rank[i]] = j;
    }
}
