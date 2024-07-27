// https://tlx.toki.id/problems/troc-19/A

#include <iostream>
using namespace std;

int main(){

    int P, Q;
    bool loop = true;

    // while (loop){
        cout << "Masukan P Q: ";
        cin >> P >> Q;

        if (P < 0){
            cout << "Nilai P tidak boleh kurang dari 1";
        }

        if (Q > 101){
            cout << "Nilai Q tidak boleh lebih dari 100";
        }

        if (P >= 1 || Q <= 100){
            loop = false;
        }
    // }
    
    int dayOne = P * P;
    int dayTwo = Q * Q;
    int result = dayOne + dayTwo + 1;

    if (result % 4 != 0){
        cout << "-1";
    }else{
        cout << "1";
    }

    return 0;
}