#include <iostream>
#define MOD 1000000007

using namespace std;

// Fungsi untuk menghitung pangkat dengan modulus
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

int main() {
    long long a, k;
    cin >> a >> k;
    
    long long T = 0;
    for (long long i = 1; i <= k; ++i) {
        T = (T + (i * power(a, i, MOD)) % MOD) % MOD;
    }
    
    cout << T << endl;
    return 0;
}
