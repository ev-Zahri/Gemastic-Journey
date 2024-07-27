#include <iostream>
#include <algorithm>
using namespace std;
int main(){

    int n, average = 0, high = 0, sisa = 0, low = 0, sum = 0;
    int indexHigh = 1, indexLow = 1;
    cin >> n;
    int array[n];

    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    high = array[0];
    low = array[0];
    for (int i = 0; i < n; i++){
        if (high < array[i]){
            high = array[i];
            indexHigh = i + 1;
        }
        if (low > array[i]){
            low = array[i];
            indexLow = i + 1;
        }
        sum = sum + array[i]; 
    }
    average = sum / n;
    for (int i = 0; i < n; i++){
        int temp = 0;
        temp = array[i] - average;
        if (temp > 0){
            sisa += temp;
        }
    }
    if (sisa > 0){
        int temp = low + sisa;
        int arr2[n];
        copy(array, array+n, arr2);
        if (temp <= average){
            // menambah nilai terendah dan mengurangi nilai tertinggi
            for (int i = 0; i < n; i++){
                if (arr2[i] == low){
                    arr2[i] += sisa;
                }
                if (arr2[i] == high){
                    arr2[i] -= sisa;
                }
            }
            for (int i = 0; i < n; i++){
                int check = 0;
                for (int j = 0; j < n; j++){
                    if (arr2[j] == average){
                        check++;
                    }
                }
                if (check == n){
                    cout << sisa << " " << indexHigh << " " << indexLow;
                    break;
                }
                check = 0;
                for (int j = 0; j < n; j++){
                    if (arr2[j] > average || arr2[j] < average){
                        check++;
                    }
                }
                if (check != 0){
                    cout << "TIDAK SESUAI"; 
                    break;
                }
            }
            return 0;
        }
    }
    if (sisa == 0){
        cout << "SESUAI" << endl;
    }
    return 0;
}