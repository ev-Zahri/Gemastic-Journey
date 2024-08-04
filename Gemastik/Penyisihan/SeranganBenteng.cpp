#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // Menambahkan header untuk std::numeric_limits

using namespace std;

long long minCoins(long long soldiers, long long P, long long Q) {
    vector<long long> dp(soldiers + 1, numeric_limits<long long>::max());
    dp[0] = 0;
    
    for (long long i = 1; i <= soldiers; ++i) {
        // Gun
        dp[i] = min(dp[i], dp[i - 1] + 1);
        
        // Small bomb
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + P);
        }
        
        // Big bomb
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + Q);
        }
    }
    return dp[soldiers];
}

int main() {
    int N;
    long long P, Q;
    cin >> N >> P >> Q;
    vector<long long> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        cout << minCoins(A[i], P, Q) << endl;
    }
    
    return 0;
}
