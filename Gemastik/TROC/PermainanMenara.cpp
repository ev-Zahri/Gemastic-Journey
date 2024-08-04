#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        string kata = "";
        for (int j = 0; j < m; j++){
            kata = (j % 2 == 0) ? "W" : "B";
            cout << kata;
        }
        cout << endl;
    }

    return 0;
}