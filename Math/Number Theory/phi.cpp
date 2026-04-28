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

const int N = 1e7 + 1;
vector<int> primes;
int phi[N];

void phi_1_to_n(){
    phi[1] = 1;
    for(int i = 2; i < N; i++) {
        if(phi[i] == 0){ 
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for(int p : primes){
            if(i * p >= N) break;
            if(i % p == 0){
                phi[i * p] = phi[i] * p;
                break;
            }else {
                phi[i * p] = phi[i] * (p - 1);
            }
        }
    }
}
