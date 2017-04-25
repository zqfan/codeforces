#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, si, sj, ti, tj;
    char g[1000][1001] = {0};
    int v[1000][1000] = {0};
    scanf("%d %d", &n, &m);
    for ( int i = 0; i < n; ++i ) {
        scanf("%s", g[i]);
        for ( int j = 0; j < m; ++j ) {
            if ( 'S' == g[i][j] ) si = i, sj = j;
            if ( 'T' == g[i][j] ) ti = i, tj = j;
        }
    }
    v[si][sj] = 1;
    for ( int t = 1; t <= 4; ++t ) {
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( v[i][j] != t ) continue;
                for ( int k = j - 1; k >= 0; --k ) {
                    if ( '*' == g[i][k] || 0 != v[i][k] ) break;
                    v[i][k] = t + 1;
                }
                for ( int k = j + 1; k < m; ++k ) {
                    if ( '*' == g[i][k] || 0 != v[i][k] ) break;
                    v[i][k] = t + 1;
                }
                for ( int k = i - 1; k >= 0; --k ) {
                    if ( '*' == g[k][j] || 0 != v[k][j] ) break;
                    v[k][j] = t + 1;
                }
                for ( int k = i + 1; k < n; ++k ) {
                    if ( '*' == g[k][j] || 0 != v[k][j] ) break;
                    v[k][j] = t + 1;
                }
            }
        }
    }
    printf(v[ti][tj] > 0 && v[ti][tj] <= 4 ? "YES\n" : "NO\n");
    return 0;
}
