#include <stdio.h>
#include <stdint.h>

uint64_t combination(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k; 
    uint64_t c = 1;
    for (int i = 0; i < k; i++) {
        c = c * (n - i) / (i + 1);
    }
    return c;
}

uint64_t findNthNumberWithKBits(uint64_t N, int K) {
    uint64_t result = 0;
    int bits = 64; 

    for (int i = bits - 1; i >= 0; i--) {
        if (K == 0) break;
        uint64_t c = combination(i, K);
        if (N > c) {
            N -= c;
            result |= (1ULL << i);
            K--;
        }
    }

    return result;
}

int main() {
    uint64_t N;
    scanf("%llu", &N);

    const int K = 30;
    uint64_t number = findNthNumberWithKBits(N, K);

    printf("%llu\n", number);

    return 0;
}
