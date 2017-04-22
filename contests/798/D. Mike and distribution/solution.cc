#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findUnfair(vector<int> & A, vector<int> & B) {
        int n = A.size();
        vector<pair<int, int>> indices(n);
        for ( int i = 0; i < n; ++i ) {
            indices[i] = make_pair(i, A[i]);
        }
        auto cmp = [] (const pair<int, int> & a, const pair<int, int> & b) {
            return a.second > b.second;
        };
        sort(indices.begin(), indices.end(), cmp);
        vector<int> unfair;
        unfair.push_back(indices[0].first + 1);
        for ( int i = 1; i < n; i += 2 ) {
            if ( i + 1 < n && B[indices[i + 1].first] > B[indices[i].first] ) {
                unfair.push_back(indices[i + 1].first + 1);
            } else {
                unfair.push_back(indices[i].first + 1);
            }
        }
        return unfair;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    vector<int> A(n), B(n);
    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &A[i]);
    }
    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &B[i]);
    }
    Solution s;
    vector<int> unfair = s.findUnfair(A, B);
    printf("%d\n", n / 2 + 1);
    for ( int n : unfair ) {
        printf("%d ", n);
    }
    return 0;
}
