// https://tlx.toki.id/problems/troc-19/B

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, M;
    cin >> N >> M;

    // Jika ukuran grid adalah 1x1
    if (N == 1 && M == 1) {
        cout << 1 << endl;
        return 0;
    }

    // Jika ukuran grid adalah Nx1 atau 1xM
    if (N == 1 || M == 1) {
        long long result = 1;
        for (int i = 0; i < max(N, M); i++) {
            result = (result * 2) % MOD;
        }
        cout << result << endl;
        return 0;
    }

    // Jika ukuran grid lebih besar dari 1x1
    long long result = 1;
    for (int i = 0; i < N + M - 1; i++) {
        result = (result * 2) % MOD;
    }
    cout << result << endl;
    return 0;
}
