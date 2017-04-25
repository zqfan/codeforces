#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    int minVal = INT_MAX;
    for ( int i = 0; i < n; ++i ) {
        cin >> A[i];
        minVal = min(minVal, A[i]);
    }
    long long time = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( (A[i] - minVal) % k != 0 ) {
            cout << -1 << endl;
            return 0;
        }
        time += (A[i] - minVal) / k;
    }
    cout << time << endl;
    return 0;
}
