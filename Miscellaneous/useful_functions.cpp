/*
 * Collection of CP Utilities
 * Includes: Custom Hash for maps, Modular Inverse, Combinations, and Sieve
 */

// Random Number Generation & Custom Hash for unordered_map
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Modular Arithmetic
int power(int a, int b, int m = mod) {
    int res = 1; a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    }
    return res;
}

int mminvprime(int a, int b = mod) { return power(a, b - 2, b); }

int mod_add(int a, int b, int m = mod) { return (a % m + b % m + m) % m; }
int mod_mul(int a, int b, int m = mod) { return ((a % m) * (b % m)) % m; }
int mod_sub(int a, int b, int m = mod) { return (a % m - b % m + m) % m; }
int mod_div(int a, int b, int m = mod) { return mod_mul(a, mminvprime(b, m), m); }

// Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<int> is_prime(n + 1, 1), primes;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = 0;
        }
    }
    return primes;
}

int getRandomNumber(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }
