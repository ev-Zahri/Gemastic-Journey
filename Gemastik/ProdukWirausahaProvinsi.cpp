#include <iostream>
using namespace std;

struct ProdukWirausahaProvinsi{
    string namaProvinsi;
    int produk;
};


int main(){
    long p, n, i = 0;
    long k;
    string namaProv = "";
    cin >> p >> n >> k;
    long jmlProdukPerProvinsi[p];
    ProdukWirausahaProvinsi Provinsi[p];

    while (i < p){
        cin >> namaProv;
        Provinsi[i].namaProvinsi = namaProv;
        cin.ignore(); 
        namaProv = "";
        int hargaProduk[n];
        int temp = 0;
        // input harga
        for (int j = 0; j < n; j++){
            cin >> hargaProduk[j];
        }
        // penjumlahan harga
        for (int j = 0; j < n; j++){
            temp += hargaProduk[j];
        }
        Provinsi[i].produk = temp;
        temp = 0;
        i++;
        cout << endl;
    }
    
    int hargaMendekati = Provinsi[0].produk;
    int index = 0;
    for(int j = 0; j < p; j++){
        if (Provinsi[0].produk > hargaMendekati && Provinsi[0].produk < k){
            cout << Provinsi[index].namaProvinsi;
            break;
        }
        index++;
    }

}