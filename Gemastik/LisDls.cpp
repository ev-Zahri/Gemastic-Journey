#include <bits/stdc++.h>
using namespace std;

int lds(int arr[], int n) {
    int lds[n];
    int i, j, max = 0;
    
    for (i = 0; i < n; i++)
        lds[i] = 1;
    
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
    
    for (i = 0; i < n; i++)
        if (max < lds[i])
            max = lds[i];
    
    return max;
}

int _lis(int arr[], int n, int* max_ref)
{

    // Base case
    if (n == 1)
        return 1;

    // 'max_ending_here' is length of
    // LIS ending with arr[n-1]
    int res, max_ending_here = 1;

    // Recursively get all LIS ending with
    // arr[0], arr[1] ... arr[n-2]. If
    // arr[i-1] is smaller than arr[n-1],
    // and max ending with arr[n-1] needs
    // to be updated, then update it
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1]
            && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }

    // Compare max_ending_here with the
    // overall max. And update the
    // overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;

    // Return length of LIS ending
    // with arr[n-1]
    return max_ending_here;
}

// The wrapper function for _lis()
int lis(int arr[], int n)
{

    // The max variable holds the result
    int max = 1;

    // The function _lis() stores its
    // result in max
    _lis(arr, n, &max);

    // Returns max
    return max;
}

int main() {
    int arr[] = {15, 27, 14, 38, 63, 55, 46, 65, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Panjang LDS adalah " << lds(arr, n);


    int arr2[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    n = sizeof(arr2) / sizeof(arr2[0]);

    // Function call
    cout << "Length of lis is " << lis(arr2, n);
    return 0;
}
