// https://www.codewars.com/kata/5ca24526b534ce0018a137b5/train/cpp
#include <iostream>
#include <string>
using namespace std;

string oldPhone(const string& pesan) {
    string tombol = "";
    for (size_t i = 0; i < pesan.size(); ++i) {
        char c = pesan[i];
        if (c == ' ') tombol += ' ';
        else if (c >= 'a' && c <= 'c') tombol += string(1, '2' + (c - 'a') / 3);
        else if (c >= 'd' && c <= 'f') tombol += string(1, '3' + (c - 'd') / 3);
        else if (c >= 'g' && c <= 'i') tombol += string(1, '4' + (c - 'g') / 3);
        else if (c >= 'j' && c <= 'l') tombol += string(1, '5' + (c - 'j') / 3);
        else if (c >= 'm' && c <= 'o') tombol += string(1, '6' + (c - 'm') / 3);
        else if (c >= 'p' && c <= 's') tombol += string(1, '7' + (c - 'p') / 4);
        else if (c >= 't' && c <= 'v') tombol += string(1, '8' + (c - 't') / 3);
        else if (c >= 'w' && c <= 'z') tombol += string(1, '9' + (c - 'w') / 4);
    }
    return tombol;
}

int main() {
    string pesan;
    cout << "Masukkan pesan: ";

    // Menggunakan ignore untuk membersihkan buffer sebelum getline
    cin.ignore(10000, '\n');
    getline(cin, pesan);

    cout << "==============================\n";
    cout << "Pesan yang ingin dikirim: " << pesan << endl;
    cout << "Tombol yang ditekan: " << oldPhone(pesan) << endl;

    return 0;
}
