#include <iostream>
#include <string>
using namespace std;

int main(){
    int f=0,b=0, Fizz, Buzz;
    int N,F[N],B[N];
    string input;
    cin >> N;
    F[0]=0;
    B[0]=0;
    for (int i= 0; i<N; i++){
        cin >> input; cin.ignore();
        if (input == "Fizz"){
            F[f] = i + 1;
            f++;
        }
        if (input == "Buzz"){
            B[b] =  i + 1;
            b++;
        }
        if (input == "FizzBuzz"){
            F[f] = i + 1;
            B[b] = i + 1;
            f++; b++;
        }
    }
    if (b !=0 && f !=0){
    Fizz = F[f-1] - F[f-2];
    Buzz = B[b-1] - B[b-2];
    cout << Fizz << " " << Buzz;
    }else if(b == 0){
        Fizz = F[f-1] - F[f-2];
        cout << Fizz << " 0";
    }else if(f == 0){
        Buzz = B[b-1] - B[b-2];
        cout << "0 "<< Buzz;
    }
    return 0;
}

