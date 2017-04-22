#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<char> minChar(n, s[n-1]);
    for ( int i = n - 2; i >= 0; --i ) {
        minChar[i] = min(minChar[i + 1], s[i]);
    }
    stack<char> t;
    string u;
    for ( int i = 0; i < n; ++i ) {
        while ( t.size() > 0 && t.top() <= minChar[i] ) {
            u.push_back(t.top());
            t.pop();
        }
        t.push(s[i]);
    }
    while ( t.size() > 0 ) {
        u.push_back(t.top());
        t.pop();
    }
    cout << u << endl;
    return 0;
}
