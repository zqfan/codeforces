#include <iostream>
#include <string>
using namespace std;

int count(string s) {
    int count = 0;
    for ( int i = 0; i < s.size() - 1; ++i ) {
        if ( s[i] == 'V' && s[i + 1] == 'K' ) {
            ++count;
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    int maxCount = count(s);
    for ( int i = 0; i < s.size(); ++i ) {
        if ( s[i] == 'V' ) {
            s[i] = 'K';
            maxCount = max(maxCount, count(s));
            s[i] = 'V';
        } else {
            s[i] = 'V';
            maxCount = max(maxCount, count(s));
            s[i] = 'K';
        }
    }
    cout << maxCount << endl;
    return 0;
}
