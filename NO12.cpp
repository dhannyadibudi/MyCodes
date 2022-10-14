#include <iostream>
using namespace std;

int main (){
    int  nialimedal, tingkatan1,tingkatan2,i,ii;
    char tim1,tim2;
    string medal1,medal2;
    float rumus,kekuatan1, kekuatan2;

    cin>>tim1>>tim2;
    for (i=1;i<=5;i++){
        cin>>medal1>>tingkatan1;
        if(medal1=="H"){
            nialimedal=1;
        }if(medal1=="G"){
            nialimedal=2;
        }if(medal1=="C"){
            nialimedal=3;
        }if(medal1=="Ar"){
            nialimedal=4;
        }if(medal1=="L"){
            nialimedal=5;
        }if(medal1=="An"){
            nialimedal=6;
        }if(medal1=="D"){
            nialimedal=7;
        }
        rumus = nialimedal + (tingkatan1/5)-0,1;
        kekuatan1 += rumus;
    }
    for (ii=1;ii<=5;ii++){
        cin>>medal2>>tingkatan2;
        if(medal2=="H"){
            nialimedal=1;
        }if(medal2=="G"){
            nialimedal=2;
        }if(medal2=="C"){
            nialimedal=3;
        }if(medal2=="Ar"){
            nialimedal=4;
        }if(medal2=="L"){
            nialimedal=5;
        }if(medal2=="An"){
            nialimedal=6;
        }if(medal2=="D"){
            nialimedal=7;
        }
        rumus = nialimedal + (tingkatan2/5)-0,1;
        kekuatan2 += rumus;
    }
 if (kekuatan1>kekuatan2){
    cout<<tim1;
 }else if (kekuatan2>kekuatan1){
    cout<<tim2;
 }else if (kekuatan1==kekuatan2){
    cout<<"Sama Kuat";
 }


return 0;
}
