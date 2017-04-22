#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

// assert n > 0
char * convert2alpha(int n, char * col) {
    int i = 0;
    while ( n-- > 0 ) {
        col[i++] = n % 26 + 'A';
        n /= 26;
    }
    col[i] = '\0';
    reverse(col, col + i);
    return col;
}

int convert2number(char * s) {
    int n = 0;
    for ( int i = 0; s[i]; ++i ) {
        n = n * 26 + s[i] - 'A' + 1;
    }
    return n;
}

int main() {
    int n;
    char line[100], row[10], col[10];

    scanf("%d\n", &n);
    while ( n-- ) {
        scanf("%s", line);
        if ( sscanf(line, "R%[0-9]C%[0-9]", row, col) == 2 ) {
            printf("%s%s\n", convert2alpha(atoi(col), col), row);
        } else {
            sscanf(line, "%[A-Z]%[0-9]", col, row);
            printf("R%sC%d\n", row, convert2number(col));
        }
    }
    return 0;
}
