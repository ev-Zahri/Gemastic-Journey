#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    long long L;
    cin >> N >> L;
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    vector<long long> lengths = {L}; 

    for (int i = 0; i < N; i++) {
        int index = B[i] - 1; 
        long long current_length = lengths[index];
        long long new_length = current_length / 2;
        lengths[index] = new_length;
        lengths.insert(lengths.begin() + index + 1, new_length);
    }
    for (long long length : lengths) {
        cout << length << " ";
    }

    return 0;
}
