#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x1, y1, x2, y2, x, y, vx, vy, ok = 1;
    scanf("%d %d %d %d %d", &n, &x1, &y1, &x2, &y2);
    double st = 0, et = 1e6, t1, t2;
    for ( int i = 0; i < n; ++i ) {
        scanf("%d %d %d %d", &x, &y, &vx, &vy);
        if ( vx != 0 ) {
            t1 = (x1 - x) / double(vx);
            t2 = (x2 - x) / double(vx);
            st = max(st, min(t1, t2));
            et = min(et, max(t1, t2));
        } else if ( x <= x1 || x >= x2 ) ok = 0;
        if ( vy != 0 ) {
            t1 = (y1 - y) / double(vy);
            t2 = (y2 - y) / double(vy);
            st = max(st, min(t1, t2));
            et = min(et, max(t1, t2));
        } else if ( y <= y1 || y >= y2 ) ok = 0;
    }
    if ( ok == 1 && st < et ) printf("%.20lf\n", st);
    else printf("-1\n");
    return 0;
}
