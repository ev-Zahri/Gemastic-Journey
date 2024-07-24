// https://tlx.toki.id/problems/troc-21/A

#include <iostream>
#include <cmath>

using namespace std;

bool canBurnHair(int N, int D) {
    int k = 1;  // Mulai dari 1 karena pangkat 0 tidak berguna dalam kasus ini
    while (true) {
        long long power = pow(k, D);  // Gunakan long long untuk menangani nilai besar
        if (power == N) {
            break;  // Jika hasil pangkat sama dengan N, berhenti
        }
        if (power > N) {
            return true;  // Jika hasil pangkat lebih besar dari N, kembalikan true
        }
        k++;
    }
    return false;  // Jika tidak ada k yang memenuhi, kembalikan false
}

int main() {
    int N, D;
    cout << "Masukkan nilai N dan D: ";
    cin >> N >> D;

    if (canBurnHair(N, D)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
