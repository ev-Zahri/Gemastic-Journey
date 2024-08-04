#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

long countTileWays(int N) {
    // Array untuk menyimpan jumlah susunan kemungkinan pemasangan ubin
    vector<long long> dp(N + 1, 0);

    // Base cases
    dp[1] = 1; // Untuk N = 1, hanya ada satu kemungkinan (dua ubin 1x1)
    dp[2] = 4; // Untuk N = 2, ada empat kemungkinan seperti contoh di soal

    // Menghitung nilai dp[i] untuk i dari 3 hingga N
    for (long i = 3; i <= N; ++i) {
        dp[i] = (dp[i-1] * 2 + dp[i-2] * 1) % MOD;
    }

    return dp[N];
}

int main() {
    int N;
    cin >> N;
    cout << countTileWays(N) << endl;
    return 0;
}
