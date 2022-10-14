#include <iostream>
using namespace std;

int main() {
  int a,b,c,ganjil,genap;
  for (a = 6; a >= 1; a--){

    for (b = 6; b > a; b--){ //Spasi berbentuk segitiga siku terbalik agar tidak rata ke kanan
      cout << "\t";
    }
    for (c = 1; c <= (2*a-1); c++ ){//Pola segitiga sama sisi
        ganjil = c*2-1;
        genap = c*2;
      if (a%2 == 0){ //menentukan baris ganjil
        cout << genap << "\t";
      }else if (a%2 == 1){//menentukan baris genap
        cout << ganjil << "\t";
      }
    }
    cout << endl;
  }
  return 0;
}
