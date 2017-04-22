#include <iostream>
#include <string>

using namespace std;

int main() {
    string x, y, z;
    cin >> x >> y;
    for ( int i = 0; i < x.size(); ++i ) {
        if ( x[i] < y[i] ) {
            cout << -1 << endl;
            return 0;
        }
        z.push_back(y[i]);
    }
    cout << z << endl;
    return 0;
}
