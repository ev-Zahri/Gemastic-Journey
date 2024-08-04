#include <iostream>
#include <algorithm>
using namespace std;

int highV(int *volume, int n){
    int max = volume[0], index;
    for (int i = 0; i < n; i++){
        if (volume[i] > max) index = i;
    }
    return index;
}

int lowv(int *volume, int n){
    int min = volume[0], index;
    for (int i = 0; i < n; i++){
        if (volume[i] < min) index = i;
    }
    return min;
}

bool sameV(int *volume, int n){
    for (int i = 0; i < n - 1; i++){
        if (volume[i] != volume[i+1]){
            return false;
        }
    }
    return true;
}

int main(){

    int n, total = 0;
    cin >> n;
    int *arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int max = highV(arr, n);
    int min = lowV(arr, n);
    
    return 0;
}