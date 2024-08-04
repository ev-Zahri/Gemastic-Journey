#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, sum = 0; cin >> n;
    int arr[n*2]; 
    for (int i = 0; i < n*2; i++){
        cin >> arr[i];
    }
    sort(arr, arr + 2 * n);
    for (int i = n * 2 - 1; i >= n; --i){
        sum += arr[i];
    }
    cout << sum;
    return 0;
}