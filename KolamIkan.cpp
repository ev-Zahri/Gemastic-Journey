#include <iostream>
using namespace std;

int main(){
    int index = 0;
    int n, k, b;
    cin >> n >> k >> b;
    int h[k][n], kolam1[k], kolam2[k];
    // input baris ke 2
    for(int i = 0; i < n; i++){
        cin >> h[0][i];
    }
    // pengisian baris ke 3 dan 4
    for (int i = 0; i < k; i++){
        cin >> kolam1[i];
        h[1][index] = kolam1[i];
        index++;
    }
    for (int i = 0; i < k; i++){
        cin >> kolam2[i];
        h[1][index] = kolam2[i];
        index++;
        if (i == k - 1){
            h[1][index] = index + 1;
        }
    }
    // harga saluran air diberi index
    int result = 0;
    int bKolam1 = h[0][0];
    int bKolam2 = h[0][k];
    index = 0;
    for(int i = 0; i < k; i++){
        index++;
        if (bKolam1 > h[0][i]){
            bKolam1 = h[0][i];
            break;
        }
    }
    for (int i = k; i < n; i++){
        if (bKolam2 > h[0][i]){
            bKolam2 = h[0][i];
            break;
        }
    }
    result = bKolam1 * k + bKolam2 * (n - index);
    cout << result;
    return 0;
}