#include <iostream>
#include <iomanip>
using namespace std;

int main (){
    int matkul,i;
    string aksara;
    double SKS,totalSKS,nilai,angka,totalnilai,IPS;
    cout << "Masukkan jumlah Mata Kuliah : ";
    cin >> matkul;
    for (i=1;i<=matkul;i++){
        cout << "Aksara SKS\n";
        cin >> aksara>> SKS;
        if (aksara == "A"){
                angka =4.00;
        }if (aksara == "AB"){
                angka =3.50;
        }if (aksara == "B"){
                angka =3.00;
        }if (aksara == "BC"){
                angka =2.50;
        }if (aksara == "C"){
                angka =2.00;
        }if (aksara == "CD"){
                angka =1.50;
        }if (aksara == "D"){
                angka =1.00;
        }if (aksara == "E"){
                angka =0.00;
        }
        nilai = angka *SKS;
        totalSKS += SKS;
        totalnilai += nilai;
    }
      IPS = totalnilai/totalSKS;
      cout<<"IPS : "<<fixed<< setprecision(2)<<IPS;


return 0;
}
