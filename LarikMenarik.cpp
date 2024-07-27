// https://tlx.toki.id/problems/troc-19/C

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool has_and_zero(int a, int b) {
    return (a & b) == 0;
}

int main() {
    int N;
    cout << "Masukan N: ";
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int max_size = 0;
    vector<int> result;

    for (int mask = 1; mask < (1 << N); mask++) {
        vector<int> subset;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                subset.push_back(A[i]);
            }
        }

        bool valid = true;
        int xor_sum = 0;

        for (size_t i = 0; i < subset.size() && valid; i++) {
            for (size_t j = i + 1; j < subset.size() && valid; j++) {
                if (!has_and_zero(subset[i], subset[j])) {
                    valid = false;
                }
            }
            xor_sum ^= subset[i];
        }

        if (valid && xor_sum != 0) {
            if (subset.size() > max_size) {
                max_size = subset.size();
                result = subset;
            }
        }
    }

    cout << max_size << endl;
    for (int i = 0; i < max_size; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
