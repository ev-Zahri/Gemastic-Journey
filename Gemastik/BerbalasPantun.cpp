#include <iostream>
using namespace std;

int summarize(int kelasA[], int kelasB[], int n){
    long result = 0;
    // sejajar
    for (int i = 0; i < n; i++){
        result = result + kelasA[i] + kelasB[i];
    }
    // menderet ke kanan
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            result = result + kelasA[i] + kelasB[j];
            break;
        }
    }
    // menderet ke kiri
    for (int i = n - 1; i >= 0; i--){
        for (int j = i - 1; j >= 0; j--){
            result = result + kelasA[i] + kelasB[j];
            break;
        }
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    int kelasA[n], kelasB[n];
    for (int i = 0; i < n; i++){
        cin >> kelasA[i];
    } 
    for (int i = 0; i < n; i++){
        cin >> kelasB[i];
    } 
    cout << summarize(kelasA, kelasB, n);
    return 0;
}