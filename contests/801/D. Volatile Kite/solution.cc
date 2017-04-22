#include <cstdio>
#include <cmath>
#include <cfloat>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<double> x(n), y(n);
    for ( int i = 0; i < n; ++i ) {
        scanf("%lf %lf", & x[i], & y[i]);
    }
    double d = DBL_MAX;
    double x0, y0, x1, y1, x2, y2;
    double area, width;
    for ( int i = 0; i < n; ++i ) {
        x0 = x[i];
        y0 = y[i];
        x1 = x[(i + 1) % n];
        y1 = y[(i + 1) % n];
        x2 = x[(i + 2) % n];
        y2 = y[(i + 2) % n];
        area = (x2 - x0) * ( y1 - y0) - (y2 - y0) * (x1 - x0);
        width = sqrt((x2 - x0) * (x2 - x0) + (y2 - y0) * (y2 - y0));
        d = min(d, area / width / 2);
    }
    printf("%.10lf\n", d);
    return 0;
}
