/*
 * Euler's Totient Function (Phi)
 * Use: Counting integers up to n that are relatively prime to n
 */
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

void phi_1_to_n(int n, vector<int>& p) {
    p.resize(n + 1);
    for (int i = 0; i <= n; i++) p[i] = i;
    for (int i = 2; i <= n; i++) {
        if (p[i] == i) {
            for (int j = i; j <= n; j += i)
                p[j] -= p[j] / i;
        }
    }
}
