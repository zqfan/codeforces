#include <bits/stdc++.h>
using namespace std;

unsigned gcd(unsigned a, unsigned b) {
    unsigned r;
    while ( b ) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n + 1);
    int g = 0;
    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &nums[i]);
        g = gcd(nums[i], g);
    }
    if ( g > 1 ) {
        printf("YES\n0");
        return 0;
    }
    int moves = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( nums[i] & 1 ) {
            ++moves;
            if ( (nums[i + 1] & 1) == 0 ) {
                ++moves;
            }
            ++i;
        }
    }
    printf("YES\n%d", moves);
    return 0;
}
