#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string reverseLookup(const unordered_map<string, string>& table, const string& value) {
    for (const auto& pair : table) {
        if (pair.second == value) {
            return pair.first;
        }
    }
    return "";
}

string minEs(string pesan, int panjang) {
    unordered_map<string, string> tabel1 = {
        {"AA", "AB"}, {"AB", "DC"}, {"AC", "CC"}, {"AD", "CB"},
        {"BA", "CA"}, {"BB", "DA"}, {"BC", "CD"}, {"BD", "DD"},
        {"CA", "BC"}, {"CB", "AA"}, {"CC", "BA"}, {"CD", "DB"},
        {"DA", "BD"}, {"DB", "AD"}, {"DC", "BB"}, {"DD", "AC"},
    };
    unordered_map<string, string> tabel2 = {
        {"AA", "CD"}, {"AB", "BB"}, {"AC", "AC"}, {"AD", "CC"},
        {"BA", "CB"}, {"BB", "DB"}, {"BC", "AD"}, {"BD", "DD"},
        {"CA", "DA"}, {"CB", "DC"}, {"CC", "BC"}, {"CD", "BD"},
        {"DA", "AA"}, {"DB", "BA"}, {"DC", "CA"}, {"DD", "AB"},
    };

    string decGema = "";
    string decToTable1 = "";
    string potongan = "";
    string pesanAsli = "";

    // pesan gema ke astik using tabel2 (reverse lookup)
    for (int i = 0; i < panjang; i += 2) {
        potongan = pesan.substr(i, 2);
        string temp = reverseLookup(tabel2, potongan);
        decGema.append(temp);
    }

    // decGema ke pesanAsli using tabel1 (reverse lookup)
    for (int i = 0; i < panjang; i += 2) {
        potongan = decGema.substr(i, 2);
        string temp = reverseLookup(tabel1, potongan);
        pesanAsli.append(temp);
    }

    return pesanAsli;
}

int main() {
    string karakter = "";
    cout << "Masukan karakter: ";
    cin >> karakter;
    int panjangKarakter = karakter.length();
    if (panjangKarakter % 2 != 0) {
        cout << "Panjang karakter harus kelipatan 2" << endl;
        return 1;
    }

    cout << minEs(karakter, panjangKarakter) << endl;

    return 0;
}
