#include <iostream>
#include <vector>

using namespace std;

int hitungMinimalTekanSaklar(const vector<int>& lampu) {
    int n = lampu.size();
    int tekan = 0;
    int flipCount = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        // Jika lampu[i] setelah flipCount flips masih menyala, kita perlu flip lagi
        if ((lampu[i] + flipCount) % 2 == 1) {
            tekan++;
            flipCount++;
        }
    }
    
    return tekan;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> lampu(n);
    for (int i = 0; i < n; ++i) {
        cin >> lampu[i];
    }
    
    int hasil = hitungMinimalTekanSaklar(lampu);
    cout << hasil << endl;
    
    return 0;
}
