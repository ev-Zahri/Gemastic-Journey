#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int totalDays = 0;

    while (A > 0 || B > 0 || C > 0 || D > 0) {
        totalDays++;
        int consumedToday = 0;

        // Makan lumpia daging
        if (A > 0) {
            int eat = min(A, 3 - consumedToday);
            A -= eat;
            consumedToday += eat;
        }

        // Makan lumpia ayam
        if (B > 0 && consumedToday < 3) {
            int eat = min(B, 3 - consumedToday);
            B -= eat;
            consumedToday += eat;
        }

        // Makan lumpia udang
        if (C > 0 && consumedToday < 3) {
            int eat = min(C, 3 - consumedToday);
            C -= eat;
            consumedToday += eat;
        }

        // Makan lumpia ikan
        if (D > 0 && consumedToday < 3) {
            int eat = min(D, 3 - consumedToday);
            D -= eat;
            consumedToday += eat;
        }

        // Update the totalDays if there are still lumps to eat.
        if (consumedToday == 0) {
            // This case handles if no lumpia was consumed but we still have some leftover
            totalDays++;
        }
    }

    cout << totalDays << endl;
    return 0;
}
