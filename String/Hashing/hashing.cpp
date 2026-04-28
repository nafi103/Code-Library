/*
 * Double String Hashing
 * Time: O(N) precompute, O(1) substring hash
 * Note: Requires mminvprime from useful_functions.cpp
 */
vector<int> hashPrimes = {1000000009, 1000000007};
static constexpr int base = 31, maxLen = 100010;
vector<vector<int>> powersOfBase, inversePowersOfBase;

void precomputePowers() {
    int primes = sz(hashPrimes);
    powersOfBase.assign(primes, vector<int>(maxLen + 1));
    inversePowersOfBase.assign(primes, vector<int>(maxLen + 1));
    for (int i = 0; i < primes; i++) {
        powersOfBase[i][0] = 1;
        for (int j = 1; j <= maxLen; j++) {
            powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
        }
        inversePowersOfBase[i][maxLen] = mminvprime(powersOfBase[i][maxLen], hashPrimes[i]);
        for (int j = maxLen - 1; j >= 0; j--) {
            inversePowersOfBase[i][j] = (inversePowersOfBase[i][j + 1] * base) % hashPrimes[i];
        }
    }
}

struct Hashing {
    string s;
    int n, primes;
    vector<vector<int>> hashValues;
    Hashing(string a) {
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        if (powersOfBase.empty()) precomputePowers();
        s = a; n = s.length();
        for (int i = 0; i < primes; i++) {
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++) {
                hashValues[i][j] = ((s[j] - 'a' + 1ll) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0ll)) % hashPrimes[i];
            }
        }
    }
    vector<int> substringHash(int l, int r) {
        vector<int> hash(primes);
        for (int i = 0; i < primes; i++) {
            int val1 = hashValues[i][r];
            int val2 = l > 0 ? hashValues[i][l - 1] : 0ll;
            hash[i] = ((((val1 - val2) % hashPrimes[i] + hashPrimes[i]) % hashPrimes[i]) * inversePowersOfBase[i][l]) % hashPrimes[i];
        }
        return hash;
    }
};
