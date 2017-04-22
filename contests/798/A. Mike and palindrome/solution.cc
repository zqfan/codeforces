#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1, diff = 0;
    while ( i < j ) {
        if ( s[i] != s[j] ) {
            ++diff;
        }
        ++i;
        --j;
    }
    if ( diff > 1 || ( diff == 0 && i != j ) ) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
