/*
 * Mint (Modular Integer)
 * Time: O(1) for arithmetic, O(log mod) for inv/pow
 * Use: Automatic modular arithmetic to avoid overflow/missing modulo errors
 */
struct Mint {
    int v;
    explicit operator int() const { return v; }
    Mint() { v = 0; }
    Mint(int _v) : v(_v % mod) { v += (v < 0) * mod; }
};

Mint &operator+=(Mint &a, Mint b) {
    if ((a.v += b.v) >= mod) a.v -= mod;
    return a;
}

Mint &operator-=(Mint &a, Mint b) {
    if ((a.v -= b.v) < 0) a.v += mod;
    return a;
}

Mint operator+(Mint a, Mint b) { return a += b; }
Mint operator-(Mint a, Mint b) { return a -= b; }
Mint operator*(Mint a, Mint b) { return Mint(a.v * b.v); }
Mint &operator*=(Mint &a, Mint b) { return a = a * b; }

Mint pow(Mint a, int p) {
    assert(p >= 0);
    Mint res = 1;
    while (p > 0) {
        if (p & 1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

Mint inv(Mint a) {
    assert(a.v != 0);
    return pow(a, mod - 2);
}

Mint operator/(Mint a, Mint b) { return a * inv(b); }
