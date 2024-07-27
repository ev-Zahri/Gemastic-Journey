#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, k, sum;
    cout << "a: "; 
    cin >> a;
    cout << "k: ";
    cin >> k;

    sum = 0;

    for(int i = k; i > 0; i--){
        sum = sum + (k * pow(k, a));
    }
    cout << sum;
}