#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

void countFimoracciSubsequences(vector<int>& A, int K, int index, vector<int>& current, int& count) {
    if (current.size() >= K) {
        bool isFimoracci = true;
        for (int i = 2; i < current.size(); ++i) {
            if (current[i] < current[i - 1] + current[i - 2]) {
                isFimoracci = false;
                break;
            }
        }
        if (isFimoracci) {
            count = (count + 1) % MOD;
        }
    }
    for (int i = index; i < A.size(); ++i) {
        current.push_back(A[i]);
        countFimoracciSubsequences(A, K, i + 1, current, count);
        current.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int count = 0;
    vector<int> current;
    countFimoracciSubsequences(A, K, 0, current, count);

    cout << count << endl;

    return 0;
}