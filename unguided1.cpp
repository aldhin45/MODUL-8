#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Fungsi binary search untuk mencari huruf dalam string
int binarySearch(const string &str, char target) {
  int left = 0; // Diubah dari 1 menjadi 0
  int right = str.length() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (str[mid] == target) {
      // Menemukan huruf, kembalikan index yang tepat
      return mid;
    } else if (str[mid] < target) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  // Huruf tidak ditemukan
  return -1;
}

int main() {
  string kalimat;
  char huruf;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Mengurutkan kalimat terlebih dahulu
  sort(kalimat.begin(), kalimat.end());

  // Input huruf yang dicari
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> huruf;

  // Melakukan binary search
  int posisi = binarySearch(kalimat, huruf);

  // Mengecek hasil pencarian
  if (posisi != -1) {
    cout << "Huruf \"" << huruf << "\" ditemukan pada posisi " << posisi + 1 << " dari kalimat." << endl;
  } else {
    cout << "Huruf \"" << huruf << "\" tidak ditemukan dalam kalimat." << endl;
  }

  return 0;
}
