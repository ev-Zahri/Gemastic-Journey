#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int sides[3] = {A, B, C};
    sort(sides, sides + 3);
    A = sides[0]; B = sides[1]; C = sides[2];

    int operations = 0;
    while (A + B <= C) {
        if (A <= B) {
            A++;
        } else {
            B++;
        }
        operations++;
        int new_sides[3] = {A, B, C};
        sort(new_sides, new_sides + 3);
        A = new_sides[0]; B = new_sides[1]; C = new_sides[2];
    }

    cout << operations << endl;

    return 0;
}
