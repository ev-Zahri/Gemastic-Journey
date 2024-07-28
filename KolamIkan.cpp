#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> kolam(n), saluran1(k), saluran2(k);

    // Input bobot masing-masing kolam
    for (int i = 0; i < n; ++i) {
        cin >> kolam[i];
    }

    // Input saluran yang menghubungkan kolam
    for (int i = 0; i < k; ++i) {
        cin >> saluran1[i] >> saluran2[i];
    }

    // Adjust the weights based on the connections
    for (int i = 0; i < k; ++i) {
        int kolam1 = saluran1[i] - 1; // Convert to zero-based index
        int kolam2 = saluran2[i] - 1; // Convert to zero-based index
        int minWeight = min(kolam[kolam1], kolam[kolam2]);
        kolam[kolam1] = kolam[kolam2] = minWeight;
    }

    // Handle the case for the remaining kolam
    for (int i = 0; i < b; ++i) {
        if (n - b + i < n) {
            kolam[n - b + i] = kolam[n - b - 1];
        }
    }

    // Calculate the total weight
    int totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        totalWeight += kolam[i];
    }

    cout << totalWeight << endl;

    return 0;
}
