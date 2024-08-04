#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

int main() {
    // Fast input/output
    ios::sync_with_stdio(false);
    cin.tie(0);

    string N;
    cin >> N;

    string original = N;
    sort(N.begin(), N.end());

    long long originalNum = stoll(original);
    long long minDifference = LLONG_MAX;
    bool found = false;
    set<string> unique_permutations;

    do {
        if (N[0] != '-' && N != original) {
            unique_permutations.insert(N);
        }
    } while (next_permutation(N.begin(), N.end()));

    for (const string &perm : unique_permutations) {
        long long anagramNum = stoll(perm);
        long long difference = abs(anagramNum - originalNum);
        if (difference < minDifference) {
            minDifference = difference;
            found = true;
        }
    }

    if (!found) {
        int num = stoi(N);
        cout << (num-1) << endl;
    } else {
        cout << minDifference << endl;
    }

    return 0;
}
