#include <iostream>
#include <string>
#include <array>
#include <algorithm>
using namespace std;

int main(){
    int n; // jumlah kuda
    int hasil=100;

    cin >> n;
    int power[n]; //kekuatan kuda
    for (int i=0; i<n; i++){
        cin >> power[i]; cin.ignore();
    }
    sort(power,power+n);
    for (int i = 0; i < n-1; i++) {
       int selisih = power[i+1]-power[i];
        if (selisih < hasil)
                hasil = selisih;
    }

    cout << hasil;
   return 0;
}
