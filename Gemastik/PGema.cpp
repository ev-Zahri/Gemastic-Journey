#include <iostream>
#define MOD 1000000007

using namespace std;

long power(long base, long exp, long mod) {
    long result = 1;
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
    long a, k;
    cin >> a >> k;
    long T = 0;
    if (a >= 1){
        for (long i = 1; i <= k; ++i) {
            T = (T + (i * power(a, i,MOD)) % MOD);
        }
    }
    cout << T << endl;
    return 0;
}
