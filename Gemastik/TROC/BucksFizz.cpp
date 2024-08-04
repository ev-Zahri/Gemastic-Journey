#include <iostream>
using namespace std;

int main() {
    long long A, B, C;
    cin >> A >> B >> C;
    long long count = 0;
    for (long long x = 1; x <= A; ++x) {
        for (long long y = 1; y <= B; ++y) {
            for (long long z = 1; z <= C; ++z) {
                if (x % y == y % z && y % z == z % x) {
                    ++count;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}
