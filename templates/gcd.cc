unsigned gcd(unsigned a, unsigned b) {
    unsigned r;
    while ( b ) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
