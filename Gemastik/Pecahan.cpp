#include <iostream>
using namespace std;
int main(){
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a * d > c * b){
        cout << "lebih besar";
    }else if (a * d < c * b){
        cout << "lebih kecil";
    }else {
        cout << "sama";
    }
}