#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> kolam(n), saluran1(k), saluran2(k);

    for (int i = 0; i < n; ++i) {
        cin >> kolam[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> saluran1[i] >> saluran2[i];
    }

    for (int i = 0; i < k; ++i) {
        int kolam1 = saluran1[i] - 1; 
        int kolam2 = saluran2[i] - 1; 
        int minWeight = min(kolam[kolam1], kolam[kolam2]);
        kolam[kolam1] = kolam[kolam2] = minWeight;
    }

    for (int i = 0; i < b; ++i) {
        if (n - b + i < n) {
            kolam[n - b + i] = kolam[n - b - 1];
        }
    }

    int totalWeight = 0;
    for (int i = 0; i < n; ++i) {
        totalWeight += kolam[i];
    }

    cout << totalWeight << endl;

    return 0;
}