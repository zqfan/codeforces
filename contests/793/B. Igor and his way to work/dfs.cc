#include <bits/stdc++.h>
using namespace std;

int n, m, si, sj;
char g[1001][1001];
bool v[1000][1000][5][3];
int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
bool ok = false;

void dfs(int i, int j, int d, int t) {
    if ( t > 2 ) return;
    if ( i < 0 || i >= n || j < 0 || j >= m ) return;
    if ( '*' == g[i][j] ) return;
    if ( 'T' == g[i][j] ) ok = true;
    if ( v[i][j][d][t] ) return;
    v[i][j][d][t] = true;
    for ( int k = 0; k < 4; ++k )
        dfs(i + dx[k], j + dy[k], k, t + (d != 4 && d != k));
}

int main() {
    scanf("%d %d", &n, &m);
    for ( int i = 0; i < n; ++i ) {
        scanf("%s", g[i]);
        for ( int j = 0; j < m; ++j )
            if ( g[i][j] == 'S' ) si = i, sj = j;
    }
    dfs(si, sj, 4, 0);
    printf(ok ? "YES\n" : "NO\n");
}
