#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;// jumlah suhu
    int range1 = -273, range2 = 5526; // range
    int hasil=5526; //5526 adalah nilai maksimal dari suhu
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // suhu
        cin >> t; cin.ignore();
        if(t >= range1 && abs(t) <= range2 ){
            if (abs(t) < abs(hasil) || abs(t) == abs(hasil) && t > hasil){
                hasil = t;
            }
        }
    }
    if (n <= 0){
        cout << endl << "0" << endl;
    }else {
        cout <<endl <<hasil << endl;
    }

    return 0;
}
