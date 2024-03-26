long long fastpower(int x, int y) {
    long long t = 1;
    while (y) {
        if (y & 1) t = t * x % mod;
        x = x * x % mod;
        y = y >> 1;
    }
    return t;
}
