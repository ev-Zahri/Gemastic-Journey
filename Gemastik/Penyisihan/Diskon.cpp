#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    for (int i = 0; i < Q; ++i) {
        int Xi;
        cin >> Xi;
        
        long long totalCost = 0;
        int j = 0;
        
        while (j < N) {
            // Check if the group is full
            if (j + Xi <= N) {
                // Group is full, apply discount
                for (int k = 0; k < Xi; ++k) {
                    totalCost += A[j + k];
                }
                totalCost -= A[j] / 2;  // Apply discount to the cheapest book in the group
                j += Xi;
            } else {
                // Group is not full, no discount
                for (int k = j; k < N; ++k) {
                    totalCost += A[k];
                }
                break;
            }
        }
        
        cout << totalCost << endl;
    }
    
    return 0;
}
