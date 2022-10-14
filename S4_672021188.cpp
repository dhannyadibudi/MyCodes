#include <iostream>
#include <string>
using namespace std;

    string satuan[10] = {"nol","satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

string konversi (int angka) {
       if (angka < 10) {
            return satuan[angka];
        } else if (angka == 10){
            return "sepuluh";
        } else if (angka == 11){
            return "sebelas";
        } else if (angka < 20) {
            return konversi(angka - 10) + " belas";
        } else if (angka < 100) {
            return konversi(angka / 10) + " puluh" + ((angka % 10 != 0) ? " " + konversi(angka % 10) : "");
        } else if (angka == 100){
            return "seratus";
        } else if (angka < 1000) {
            return konversi(angka / 100) + " ratus" + ((angka % 100 != 0) ? " " + konversi(angka % 100) : "");
        } else if (angka == 1000){
            return "seribu";
        } else if (angka < 1000000) {
            return konversi(angka / 1000) + " ribu" + ((angka % 1000 != 0) ? " " + konversi(angka % 1000) : "");
        }
        return "error";
    }

int main(){
    int angka;
    cin >> angka;
    cout << "\n" << konversi(angka) << endl;
    return 0;
}
