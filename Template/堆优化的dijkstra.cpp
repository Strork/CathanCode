typedef pair<int, int> pii;
void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii> > Q;
    memset(dis, 10, sizeof(dis));
    dis[s] = 0;
    memset(vis, 0, sizeof(vis));
    Q.push(make_pair(dis[s], s));
    while (!Q.empty()) {
        pii temp = Q.top();
        Q.pop();
        int x = temp.second;
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = lin[x]; i; i = e[i].nt) {
            if (dis[e[i].y] > dis[x] + e[i].v) {
                dis[e[i].y] = dis[x] + e[i].v;
                Q.push(make_pair(dis[e[i].y], e[i].y));
            }
        }
    }
}

