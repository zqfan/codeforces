#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strs(n);
    for ( int i = 0; i < n; ++i ) {
        cin >> strs[i];
    }
    int minMoves = INT_MAX, curMoves;
    for ( int i = 0; i < strs[0].size(); ++i ) {
        curMoves = i;
        string s = strs[0].substr(i) + strs[0].substr(0, i);
        for ( int j = 1, k; j < n; ++j ) {
            for ( k = 0; k < strs[0].size(); ++k ) {
                string t = strs[j].substr(k) + strs[j].substr(0, k);
                if ( s == t ) {
                    curMoves += k;
                    break;
                }
            }
            if ( k == strs[0].size() ) {
                cout << -1 << endl;
                return 0;
            }
        }
        minMoves = min(minMoves, curMoves);
    }
    cout << minMoves << endl;
    return 0;
}
