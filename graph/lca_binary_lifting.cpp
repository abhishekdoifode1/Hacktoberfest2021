vector<vector<int>> g;
vector<vector<int>> up;
vector<int> tin, tout;
int MAXLOG = 20;
int tim = 0;

void dfs(int i, int par) {
    up[i][0] = par;
    tin[i] = tim++;
    for (int j = 1; j <= MAXLOG; ++j) {
        up[i][j] = up[up[i][j - 1]][j - 1];
    }
    for (int j: g[i]) {
        if (j == par) continue;
        dfs(j, i);
    }
    tout[i] = tim++;
}

bool isAncestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;
    for (int i = MAXLOG; i >= 0; --i) {
        if (!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}
