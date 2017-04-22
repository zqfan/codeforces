#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> factors;
    for ( int i = 2; i <= n && k > 0; ++i ) {
        while ( n % i == 0 && k > 0) {
            factors.push_back(i);
            --k;
            n /= i;
        }
    }
    if ( k > 0 ) {
        printf("-1\n");
    } else {
        factors.back() *= n;
        for ( int i = 0; i < factors.size(); ++i ) {
            printf("%d ", factors[i]);
        }
    }
    return 0;
}
