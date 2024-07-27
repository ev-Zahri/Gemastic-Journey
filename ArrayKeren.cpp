#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

// Fungsi untuk mengecek apakah suatu bilangan adalah bilangan kuadrat
bool isSquare(int num) {
    int root = (int)sqrt(num);
    return root * root == num;
}

// Fungsi utama untuk menentukan nilai K terkecil
int smallestK(int n, vector<int>& A) {
    for (int K = 2; K <= n; K++) {
        bool allKeren = true;
        
        // Cek semua kombinasi subarray ukuran K
        for (int i = 0; i <= n - K; i++) {
            unordered_set<int> seen;
            bool found = false;
            
            for (int j = i; j < i + K; j++) {
                for (int x : seen) {
                    if (isSquare(A[j] * x)) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
                seen.insert(A[j]);
            }
            
            if (!found) {
                allKeren = false;
                break;
            }
        }
        
        if (allKeren) return K;
    }
    
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int result = smallestK(n, A);
    cout << result << endl;
    
    return 0;
}
