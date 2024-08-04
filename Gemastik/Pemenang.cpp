#include <iostream>
#include <cstring>
// #include <string.h>
using namespace std;

int main(){
    int n, a, b;
    cin >> n;
    int jumlahPertandingan = n * (n - 1) / 2;
    char tim[n+1][jumlahPertandingan];
    int skor[n+1];

    for(int i = 1; i <= n; i++){
        cin >> tim[i];
        skor[i] = 0;
    }

    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            cin >> a >> b;
            if(a > b){
                skor[i] += 3;
                skor[j]--;
            }
            if(a < b){
                skor[i]--;
                skor[j]+=3;
            }
            else{
                skor[i]++;
                skor[j]++;
            }
        }
    }

    char pemenang[jumlahPertandingan];
    strcpy(pemenang, tim[1]);
    a = -10000;
    for (int i = 1; i <= n; i++){
        if ( a < skor[i]){
            a = skor[i];
            strcpy(pemenang, tim[i]);
        }
        if (a == skor[i] && strcmp(pemenang, tim[i]) > 0){
            strcpy(pemenang, tim[i]);
        }
    }
    cout << pemenang;
    return 0;
}