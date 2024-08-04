#include <iostream>
#include <vector>
using namespace std;

int maxXORValue(vector<int>& arr) {
    int n = arr.size();
    int maxXor = 0;
    for (int num : arr) {
        maxXor ^= num;
    }
    int maxResult = maxXor;
    for (int num : arr) {
        for (int i = 0; i <= num; ++i) {
            int currentXor = maxXor ^ num ^ i;
            maxResult = max(maxResult, currentXor);
        }
    }
    return maxResult;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << maxXORValue(arr) << endl;
    return 0;
}
