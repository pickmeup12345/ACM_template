int count_radius(const vector<int> e[]) {
    static int dep[N];
    int mx = -1, pos = -1;
    static function<void(int, int)> dfs = [&](int u, int fa) {
        if(dep[u] > mx)
            mx = dep[pos = u];
        for(int v: e[u]) {
            if (v != fa) {
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
        }
    };
    memset(dep, 0, sizeof(dep));
    dfs(1, -1);
    memset(dep, 0, sizeof(dep));
    dfs(pos, -1);
    return mx;
}
