#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float t;//waktu second
    float s;//jarak km
    float v;//kecepatan km/jam

    cout<<"Masukkan kecepatan (detik)  : ";
    cin >>t;
    cout<<"Masukkan kecepatan (km/jam) : ";
    cin >>v;

    s = v * t /3600;
    cout <<"Jarak yang ditempuh : "<<fixed <<setprecision(2)<<s<<" km";


return 0;
}
