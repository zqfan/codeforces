#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9, MAX = 82;
int dp[MAX][MAX][MAX];
vector<int> edges[MAX], diffs[MAX];

int dfs(int start, int end, int k) {
    if ( k <= 0 ) return 0;
    if ( abs(start - end) <= 1 ) return INF;
    int & t = dp[start][end][k];
    if ( t != 0 ) return t;
    t = INF;
    for ( int i = 0, v, c; i < edges[start].size(); ++i ) {
        v = edges[start][i], c = diffs[start][i];
        if ( (end - v) * (v - start) <= 0 ) continue;
        t = min(t, dfs(v, start, k - 1) + c);
        t = min(t, dfs(v, end, k - 1) + c);
    }
    return t;
}

int main() {
    int n, k, m, r = INF;
    scanf("%d %d %d", &n, &k, &m);
    for ( int i = 0, u, v, c; i < m; ++i ) {
        scanf("%d %d %d", &u, &v, &c);
        edges[u].push_back(v);
        diffs[u].push_back(c);
    }
    for ( int i = 1; i <= n; ++i ) {
        r = min(r, dfs(i, 0, k - 1));
        r = min(r, dfs(i, n + 1, k - 1));
    }
    printf("%d\n", r == INF ? -1 : r);
    return 0;
}
