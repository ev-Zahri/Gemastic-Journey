#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Fungsi untuk menghitung berapa kali Anda harus mencongkel dan menunduk di saat yang sama
int countPokeAndDuck(int N, int D, vector<long long>& A) {
    unordered_set<long long> times; // Set untuk menyimpan waktu mencongkel
    int count = 0;

    // Masukkan semua waktu mencongkel ke dalam set
    for (int i = 0; i < N; i++) {
        times.insert(A[i]);
    }

    // Cek untuk setiap waktu t apakah t + D juga ada dalam set
    for (int i = 0; i < N; i++) {
        if (times.find(A[i] + D) != times.end()) {
            count++;
        }
    }

    return count;
}

int main() {
    int N, D;
    cout << "Masukkan nilai N dan D: ";
    cin >> N >> D;
    vector<long long> A(N);

    cout << "Masukkan nilai-nilai A: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = countPokeAndDuck(N, D, A);
    cout << result << endl;

    return 0;
}
