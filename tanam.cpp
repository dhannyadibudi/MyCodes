#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void tanam();
void tebang();
void lihat();
void pilihtanam();
void pilihtebang();
void nyebar(int i, int j);
int acak();
void benih(int i, int j);
int main();
void header(){
    HANDLE  g;
    g = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(g, 15);
    cout << "===============================\n";
    cout << "\tSIMULATOR KEBUN \n";
    cout << "===============================\n";

}


int kebun[5][4]; // deklarasi array kebun baris x kolom

int main(){
    HANDLE  g;
    g = GetStdHandle(STD_OUTPUT_HANDLE); // untuk mengubah tampilan dari output
    SetConsoleTextAttribute(g, 15); // mengubah warna menjadi putih
    char x; // deklarasi variabel pilihan
    system ("cls");
    header();
    cout << "LIST MENU\n";
    cout << "1. Tanam\n";
    cout << "2. Tebang\n";
    cout << "3. Lihat\n";
    cout << "4. Exit\n";
    cout << "Masukkan pilihan anda : "; cin >> x;
    if (x == '1'){
        tanam();// menuju prosedur tanam
    }else if (x == '2'){
        tebang();// menuju prosedur tebang
    }else if (x == '3'){
        lihat();// menuju prosedur lihat untuk menampilkan kebun
    }else if (x == '4'){
        cout << "\n\nTerimaksih telah menggunakan\n\n";exit(0);
    }else {
    cout << "\nPilihan Anda salah!!!\nSilakan pilih 1-4 \n";
    system("pause");
    main();// kembali ke main atau list menu
    }

    return 0;
}

void pilihtanam(){
    char jawab;
    cout << "\nLanjut tanam? (y/n)";
    cin >> jawab;
    if (jawab == 'y'){
        tanam();// menuju prosedur tanam
    } else {
        main();// kembali ke main atau list menu
    }
}

void tanam(){
    HANDLE  g;
    g = GetStdHandle(STD_OUTPUT_HANDLE);
    system ("cls");
    header();
    int x,y; // x baris, y kolom
    char jawab;
    cout << "Kebun berukuran 5 x 4\n";
    cout << "Petak kebun yang ditanami \n";
    cout << "Baris: "; cin >> x;
    cout << "Kolom : ";cin >> y;
    if( x <=0 || x >5 || y <=0 || y > 4){// pencegahan bila petak diluar lingkup kebun
        cout << "Petak tidak ada\n";
        pilihtanam();
    }else {
    x--; y--;// mengurangi inputan supaya pas dengan array
    if(kebun[x][y] == 0){
    kebun[x][y] = 1;// menanam benih
    }else { // pecegahan bila user menginput petak yang sudah ditanami
    cout << "Petak sudah ditanami!!";
    }
    cout <<"\nLihat kebun? (y/n)";
    cin >> jawab;
    if (jawab == 'y'){

        for (int i=0; i<5; i++){
            cout << "|";
            for(int j=0; j<4; j++){
                if (kebun[i][j] == 0){
                    cout << " \t";
                }else if (kebun[i][j] == 1){
                    cout << ".\t";
                }else if (kebun[i][j] == 2){
                    SetConsoleTextAttribute(g, 10); // mengubah warna tampilan ke hijau
                    cout << "v\t";
                    SetConsoleTextAttribute(g, 15); // mengubah warna tampilan ke putih
                }else if (kebun[i][j] == 3){
                    SetConsoleTextAttribute(g, 14); // mengubah warna tampilan ke kuning
                    cout << "0\t";
                    SetConsoleTextAttribute(g, 15);// mengubah warna tampilan ke putih
                }else if (kebun[i][j] >= 4){
                    SetConsoleTextAttribute(g, 12); // mengubah warna tampilan ke merah
                    cout << "x\t";
                    SetConsoleTextAttribute(g, 15); // mengubah warna tampilan ke putih
                }

            }
            cout << "|";
            cout << endl;
        }
        pilihtanam(); // ke proseudr lanjut tanam atau tidak?
        }else if (jawab == 'n'){
           pilihtanam(); // ke proseudr lanjut tanam atau tidak?
        }
    }
}

void pilihtebang(){
    char jawab;
        cout << "\nLanjut tebang? (y/n)";
        cin >> jawab;
        if (jawab == 'y'){
            tebang(); // menuju prosedur tebang
        } else{
            main();// kembali ke main atau list menu
        }
    }


void tebang(){
    HANDLE  g;
    g = GetStdHandle(STD_OUTPUT_HANDLE);
    system ("cls");
    header();
    int x,y;// x baris, y kolom
    char jawab;
    cout << "Kebun berukuran 5 x 4\n";
    cout << "Petak kebun yang ditebang \n";
    cout << "Baris: "; cin >> x;
    cout << "Kolom : ";cin >> y;
    if(x <=0 || x >5 || y <=0 || y > 4){// pencegahan jika input diluar lingkup kebun
        cout << "Petak tidak ada\n";
        pilihtebang();
    }else {
    x--; y--;// mengurangi inputan supaya pas dengan array
    if(kebun[x][y] == 0){ // mencegah untuk petak yang belum ditanam tidak bisa ditebang
       cout << "Petak belum ditanami!!";
    }else {
        kebun[x][y]= 0; // memangkas tanaman
    }
    cout <<"\nLihat kebun? (y/n)";
    cin >> jawab;
    if (jawab == 'y'){

        for (int i=0; i<5; i++){
            cout << "|";
            for(int j=0; j<4; j++){
                if (kebun[i][j] == 0){
                    cout << " \t";
                }else if (kebun[i][j] == 1){
                    cout << ".\t";
                }else if (kebun[i][j] == 2){
                    SetConsoleTextAttribute(g, 10);
                    cout << "v\t";
                    SetConsoleTextAttribute(g, 15);
                }else if (kebun[i][j] == 3){
                    SetConsoleTextAttribute(g, 14);
                    cout << "0\t";
                    SetConsoleTextAttribute(g, 15);
                }else if (kebun[i][j] >= 4){
                    SetConsoleTextAttribute(g, 12);
                    cout << "x\t";
                    SetConsoleTextAttribute(g, 15);
                }

            }
            cout << "|";
            cout << endl;
        }
        pilihtebang();// menuju prosedur memilih lanjut tebang atau tidak

        }else if (jawab == 'n'){
           pilihtebang();// menuju prosedur memilih lanjut tebang atau tidak
        }
    }
}

void benih(int i, int j){
    if(i >=0 && i <5 && j >=0 && j < 4){
        if (kebun [i][j] == 0){
            kebun[i][j] = 1;
            }
        }
}

void nyebar (int i,int j){
    int a=acak();// memanggil fungsi acak
    // penerjemah hasil acak ke area muncul benih
    cout << a;
    if (a == 0){
        i--; j--;
        benih(i,j);
    }else if (a == 1){
        i--;
        benih(i,j);
    }else if (a == 2){
        i--; j++;
         benih(i,j);
    }else if (a == 3){
        j--;
        benih(i,j);;
    }else if (a == 4){
        benih(i,j);
    }else if (a == 5){
        j++;
        benih(i,j);
    }else if (a == 6){
        i++;j--;
        benih(i,j);
    }else if (a == 7){
        i++;
        benih(i,j);
    }else if (a == 8){
        i++; j++;
        benih(i,j);
    }
}

void lihat(){
    HANDLE  g;
    g = GetStdHandle(STD_OUTPUT_HANDLE);
    char jawab;
    system ("cls");
    header();
    cout << "Kebun berukuran 5 x 4\n";
    for (int i=0; i<5; i++){
        cout << "|";
        for(int j=0; j<4; j++){

            if (kebun[i][j] == 0){
                cout << " \t";
            }else if (kebun[i][j] == 1){
                cout << ".\t";
                kebun [i][j] ++; // membuat tanaman tumbuh
            }else if (kebun[i][j] == 2){
                SetConsoleTextAttribute(g, 10);
                cout << "v\t";
                SetConsoleTextAttribute(g, 15);
                kebun [i][j] ++; // membuat tanaman tumbuh
            }else if (kebun[i][j] == 3){
                SetConsoleTextAttribute(g, 14);
                cout << "0\t";
                SetConsoleTextAttribute(g, 15);
                kebun [i][j] ++; // membuat tanaman tumbuh
            }else if (kebun[i][j] == 4){
                SetConsoleTextAttribute(g, 12);
                cout << "x\t";
                SetConsoleTextAttribute(g, 15);
                kebun [i][j] = 0; // membuat tanaman dipangkas
            }
        }
        cout << "|\n";
     }
     for (int i = 0; i < 5; i++){
        for (int j = 0; j < 4; j++){
            if (kebun[i][j] == 4){
                nyebar(i,j);// memanggil prosedur penyebaran benih
            }
        }
    }
    cout << "\nLihat kebun lagi? (y/n)"; cin >> jawab;
    if (jawab == 'y'){
        lihat();// kembali ke lihat
    }else{
        main(); // kembali ke main atau list menu
    }

    system("pause");
    main();// kembali ke main atau list menu
}

int acak(){ // fungsi untuk mencari angka acak 0-8
    int a = rand()%(8-0+1)+0;
    return a;
}
