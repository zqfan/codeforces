#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &arr[i]);
    }
    vector<int> even(n + 1, INT_MIN + 10000);
    vector<int> odd(n + 1, INT_MIN + 10000);
    for ( int i = 0; i < n; ++i ) {
        if ( arr[i] & 1 ) {
            odd[i + 1] = max(arr[i] + even[i], odd[i]);
            odd[i + 1] = max(arr[i], odd[i + 1]);
            even[i + 1] = max(arr[i] + odd[i], even[i]);
        } else {
            odd[i + 1] = max(arr[i] + odd[i], odd[i]);
            even[i + 1] = max(arr[i] + even[i], even[i]);
            even[i + 1] = max(arr[i], even[i + 1]);
        }
    }
    printf("%d", odd[n]);
    return 0;
}
