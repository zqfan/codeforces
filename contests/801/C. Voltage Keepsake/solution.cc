#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    vector<int> A(n);
    vector<int> B(n);
    vector< pair<double, int> > T(n);
    for ( int i = 0; i < n; ++i ) {
        scanf("%d %d", &A[i], &B[i]);
        T[i] = make_pair(-double(B[i]) / A[i], A[i]);
    }
    make_heap(T.begin(), T.end());
    double burden = -p, time = 0.0, remain = 0.0, cost = 0.0;
    while ( T.size() > 0 ) {
        pair<double, int> & t = T.front();
        cost = (-t.first - time) * burden;
        if ( remain - cost < 0 ) {
            printf("%lf\n", time + remain / burden);
            return 0;
        }
        remain -= cost;
        burden += t.second;
        time = -t.first;
        pop_heap(T.begin(), T.end());
        T.pop_back();
    }
    if ( burden <= 0 ) {
        printf("-1\n");
    } else {
        printf("%lf\n", time + remain / burden);
    }
    return 0;
}
