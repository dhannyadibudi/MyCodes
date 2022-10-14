#include <iostream>
#include <string>

using namespace std;
//Urutan kombinasi 5 3 2
int main(){
    int input;
    string lima, tiga, dua;
    string satu, kedua, output;
    cout << "Program ini akan mengeluarkan kombinasi \n5 3 2\n";
    cout <<"Masukkan Angka : ";cin >> input;
    cout << endl;
    if (input == 0 || input == 1){
        cout << "0 0 0\n";
    }
        for (int j = 0; j <= input / 2; j++) {
            for (int i = 0; j >= i; i++) {
                for (int k = 0; k <= input / 3; ++k) {
                    if (i * 5 + k * 3 + j * 2 == input) {
                       lima = to_string(i); tiga = to_string(k); dua = to_string(j);
                       if (lima + " " + tiga + " " + dua + "\n" != satu){
                       kedua += lima + " " + tiga + " " + dua + "\n";
                       }
                    }
                }
            }
        }
        if (input == 7 || input == 8 )
        for (int i = 0; i <= input / 5; ++i) {
            for (int j = 0; i >= j; ++j) {
                for (int k = 0; k <= input / 3; ++k) {
                    if (i * 5 + k * 3 + j * 2 == input) {
                       lima = to_string(i); tiga = to_string(k); dua = to_string(j);
                       satu += lima + " " + tiga + " " + dua + "\n";
                    }
                }
            }
        }
        output = satu + kedua;
        cout << output;
    return 0;
}
