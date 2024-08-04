#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int minOperations(string A, string B) {
    int N = A.length();
    int operations = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) {
            int j = i + 1;
            while (j < N && A[j] > B[j]) {
                ++j;
            }
            reverse(A.begin() + i, A.begin() + j);
            ++operations;
        }
    }

    return operations;
}

int main() {
    int N;
    string A, B;

    cin >> N;
    cin >> A;
    cin >> B;

    int result = minOperations(A, B);
    cout << result << endl;

    return 0;
}
