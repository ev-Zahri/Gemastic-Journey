
// Url = https://tlx.toki.id/problems/toki-open-2024/1A

#include <iostream>
#include <vector>

using namespace std;

long long min_leftover(int N, std::vector<int> A) {
    vector<int> duplicate = A;
    bool leftToRight = N % 2 != 0;

    while (N > 3) {
        if (leftToRight) {
            for (int j = 0; j < duplicate.size(); ++j) {
                if (duplicate[j] > 0) {
                    duplicate[j]--;
                }
            }
        } else {
            for (int j = duplicate.size() - 1; j >= 0; --j) {
                if (duplicate[j] > 0) {
                    duplicate[j]--;
                }
            }
        }
        leftToRight = !leftToRight;
        N--;
    }

    long long result = 0;
    for (int remaining : duplicate) {
        result += remaining;
    }

    return result;
}

int main() {
    vector<int> A1 = {2, 1, 3, 4, 1};
    vector<int> A2 = {1, 1, 2, 2, 1, 1};

    long long result1 = min_leftover(5, A1);
    cout << "Hasilnya adalah = " << result1 << endl;

    long long result2 = min_leftover(6, A2);
    cout << "Hasilnya adalah = " << result2 << endl;

    return 0;
}
