#include <iostream>
#include <vector>

// Fungsi untuk mencetak elemen-elemen dalam vektor 2 dimensi
void printVector(const std::vector<std::vector<int> >& vec) {
    for (std::vector<int> row : vec) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

// Fungsi untuk menambah elemen ke baris tertentu
void addElement(std::vector<std::vector<int> >& vec, int row, int element) {
    if (row >= vec.size()) {
        std::cerr << "Baris tidak ada" << std::endl;
        return;
    }
    vec[row].push_back(element);
}

// Fungsi untuk mengosongkan salah satu baris
void clearRow(std::vector<std::vector<int> >& vec, int row) {
    if (row >= vec.size()) {
        std::cerr << "Baris tidak ada" << std::endl;
        return;
    }
    vec[row].clear();
}

// Fungsi untuk menghapus elemen pada indeks tertentu di baris tertentu
void removeElement(std::vector<std::vector<int> >& vec, int row, int col) {
    if (row >= vec.size() || col >= vec[row].size()) {
        std::cerr << "Indeks tidak valid" << std::endl;
        return;
    }
    vec[row].erase(vec[row].begin() + col);
}

// Fungsi untuk mengosongkan seluruh vektor
void clearVector(std::vector<std::vector<int> >& vec) {
    vec.clear();
}

int main() {
    // Membuat vektor 2 dimensi
    std::vector<std::vector<int> > vec(3); // 3 baris kosong

    // Menambah elemen ke dalam vektor
    addElement(vec, 0, 1);
    addElement(vec, 0, 2);
    addElement(vec, 1, 3);
    addElement(vec, 2, 4);
    addElement(vec, 2, 5);

    std::cout << "Isi vektor awal:" << std::endl;
    printVector(vec);

    // Mengosongkan baris kedua
    clearRow(vec, 1);
    std::cout << "Setelah mengosongkan baris kedua:" << std::endl;
    printVector(vec);

    // Menghapus elemen pertama dari baris ketiga
    removeElement(vec, 2, 0);
    std::cout << "Setelah menghapus elemen pertama dari baris ketiga:" << std::endl;
    printVector(vec);

    // Mengosongkan seluruh vektor
    clearVector(vec);
    std::cout << "Setelah mengosongkan seluruh vektor:" << std::endl;
    printVector(vec);

    return 0;
}

