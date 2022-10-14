#include <iostream> // menambahkan iostream
#include <string> // menambahkan string
using namespace std;

void headerutama() // header menu utama
{
    cout << "===============================" << endl;
    cout << "|            TTS A            |" << endl;
    cout << "===============================" << endl;
}
void headerlift() // header program lift
{
    cout << "===============================" << endl;
    cout << "|           Lift FTI          |" << endl;
    cout << "===============================" << endl;
    cout << endl;
}
void headerbank() // header program bank
{
    cout << "===============================" << endl;
    cout << "|           Bank ACB          |" << endl;
    cout << "===============================" << endl;
}
void headerbelahketupat() // header program belah ketupat
{
    cout << "===============================" << endl;
    cout << "|        Belah Ketupat        |" << endl;
    cout << "===============================" << endl;
}
void headerkelompok8() // header author
{
    cout << "===============================" << endl;
    cout << "|          Kelompok 8         |" << endl;
    cout << "===============================" << endl;
}
void clearScreen() // clear terminal/cmd
{
    #ifdef _WIN32
    system("cls");
    #elif defined(__linux__)
    system("clear");
    #endif
}
void systemPause() // pause terminal/cmd
{
    cin.ignore();
    cout << "Tekan Enter untuk lanjut . . . ";
    cin.get();
}

int main () // program utama
{
    // deklarasi variabel
    int lantai1,lantai2,pindah,saldo,transfer,masuk;
    char pilihanuser,pilihanbank;
    string x,jawaban;

    // inisisalisasi variabel
    pilihanuser = '0';

    // MENU UTAMA

    while(pilihanuser!='5') // loop program selama user tidak memilih 5
    {
        clearScreen(); // memanggil fungsi clearScreen
        headerutama(); // memanggil fungsi headerutama

        // output & user input
        cout << "1. Lift FTI" <<endl;
        cout << "2. Bank ACB" <<endl;
        cout << "3. Belah Ketupat" <<endl;
        cout << "4. Author" <<endl;
        cout << "5. Exit" <<endl;
        cout << "Masukkan Pilihan Anda: ";
        cin >> pilihanuser;

        switch(pilihanuser) // switch dari pilihanuser
        {
            case '1' : // program Lift FTI
            {
                clearScreen();
                headerlift(); // memanggil fungsi headerlift
                    cout << "Sekarang anda berada di lantai berapa: ";
                    cin >> lantai1;
                do  // do-while loop
                {
                    // output & user input
                    cout <<"Ingin pindah ke lantai berapa? ";
                    cin >> lantai2;
                    cout << "Anda sekarang berada di lantai: " << lantai2 << endl;
                    cout << "Ingin pindah lagi?(y/n) ";
                    cin >> jawaban;
                    cout << endl;

                    if (jawaban.compare("n") && jawaban.compare("y") != 0) // jika input user salah
                    {
                        cout << "Maaf input anda tidak sesuai\nProgram Lift FTI akan berhenti . . .\n\n";

                        break;
                        systemPause();
                    }

                } while (jawaban.compare("n") !=0 ); // loop program Lift FTI selama user tidak input "n"
                cout <<"Anda sekarang berada di lantai: " << lantai2 << endl;

                // inisisalisasi variabel
                pindah = lantai2 - lantai1;

                // perpindahan lantai/tingkat dari lift
                if (lantai2 > lantai1)
                {
                    cout << "Anda bergerak " << pindah << " lantai ke atas\n\n";
                } else if (lantai1 > lantai2)
                {
                    cout<<"Anda bergerak " << abs(pindah) << " lantai ke bawah\n\n";
                } else if (lantai2 == lantai1)
                {
                    cout << "Anda tidak berpindah lantai\n\n";
                }
                systemPause();
                break;
            }

            case '2' : // program Bank ACB
            {
                // inisialisasi variabel
                saldo = 0;
                pilihanbank = '0';

                do
                {
                    clearScreen();
                    headerbank(); // memanggil fungsi headerbank

                    // output & user input
                    cout << "1. Cek Saldo" << endl;
                    cout << "2. Setor Uang" << endl;
                    cout << "3. Transfer" << endl;
                    cout << "4. Kembali" << endl;
                    cout << "Masukkan Pilihan Anda: ";
                    cin >> pilihanbank;

                    switch (pilihanbank) // switch dari pilihanbank
                    {
                        case '1' : // program Cek Saldo
                            clearScreen();
                            headerbank();

                            // output
                            cout << "Saldo rekening anda sekarang: Rp. " << saldo << endl;
                            systemPause();
                        break;

                        case '2' : // program Setor Uang
                            clearScreen();
                            headerbank();

                            //output & user input
                            cout << "Masukkan jumlah uang: Rp. ";
                            cin >> masuk;

                            if (masuk <= 0)
                            {
                                cout << "\nSetor Uang Gagal!\nMaaf jumlah saldo yang anda masukkan kurang dari 1\n\n";
                                masuk = 0;
                            }


                            // inisialisasi variabel
                            saldo += masuk;

                            // output
                            cout << "Saldo rekening anda sekarang: Rp. " << saldo << endl;
                            systemPause();
                        break;

                        case '3' : // program Transfer
                            clearScreen();
                            headerbank();

                            // output & user input
                            cout << "Masukkan jumlah uang yang ingin ditransfer: Rp. ";
                            cin >> transfer;

                            if (transfer <= 0)
                            {
                                cout << "\nTransaksi Gagal!\nMaaf jumlah uang yang anda ingin transfer kurang dari 1\n\n";
                                transfer = 0;
                            } else
                            {
                                // cek jumlah saldo dengan uang yang di transfer
                                if (saldo >= transfer) // jika jumlah transfer tidak melebihi jumlah saldo
                                {
                                    // inisialisasi
                                    saldo -= transfer ;

                                    // output
                                    cout << "\nTransaksi Berhasil!\n\n";
                                    cout << "Saldo rekening anda sekarang : Rp. " << saldo << endl;
                                } else // jika jumlah transfer melebihi jumlah saldo
                                {
                                    // output
                                    cout << "\nTransaksi Gagal!\n";
                                    cout << "Maaf jumlah saldo anda kurang!\n\n";
                                }
                            }
                            systemPause();
                        break;

                        case '4' : // kembali atau tutup program Bank ACB
                            cout << "\n\tProgram Bank ACB Selesai!\n";
                            cout << "\t   <-- TERIMAKASIH -->\n\n";
                            systemPause();
                        break;

                        default : // input user tidak sesuai
                            cout << "\nMaaf input anda tidak sesuai" << endl;
                            cout << "Silahkan pilih angka (1-4)" << endl;
                            systemPause();
                        break;
                    }
                }
                while (pilihanbank !='4'); // loop program Bank ACB selama user tidak memilih '4'
                break;
            }

            case '3' : // program Belah Ketupat
            {
                do
                {
                    clearScreen();
                    headerbelahketupat(); // memanggil fungsi header

                    // deklarasi variabel
                    int i, j, n, rb;

                    // output & user input
                    cout << "Masukkan setengah diagonal: ";
                    cin >> n;
                    cout << "\n";
                    if (n <= 1)
                            {
                                cout << "\nInput Salah!\nSilahkan input angka lebih dari 1\n\n";
                            }
                    else{
                    // inisialisasi variabel
                    rb= n*3+3;

                    for (i = 1; i <= n*2+1; i++) // loop untuk mencetak baris
                    {
                        for (j = 1; j <= n*2+1; j++) // loop untuk mencetak karakter di tiap baris
                        { // diagonal ke bawah, diagonal ke samping, miring atas kanan, miring bawah kanan
                            if (i == n+1  || j == n+1  || i + j == n+1  || i - j == n+1  || j - i == n+1 || i + j == rb) // mencetak berdasarkan posisinya di tiap baris yang ditentukan
                            { // miring atas kiri, miring bawah kiri
                                // output
                                cout << "*";
                            } else // mencetak di posisi yang tidak ditentukan
                            {
                                // output
                                cout << " ";
                            }
                        }
                        // output
                        cout << endl;
                    }
                    }
                    // output & user input
                    cout << "\nApakah anda ingin mencoba lagi?(y/n)";
                    cin >> jawaban;

                    if(jawaban.compare("n") && jawaban.compare("y") != 0) // jika input user tidak sesuai
                    {
                        cout << "\nMaaf input anda tidak sesuai\nProgram Belah Ketupat telah berhenti . . .\n\n";
                        systemPause();
                        break;
                    }
                } while (jawaban.compare("n") != 0);
                break;
            }

            case '4' : // author
            {
                clearScreen();
                headerkelompok8();

                // output
                cout << "ANGGOTA : \n";
                cout << "Anthony Febrian Aria Sena\t(672021037)" << endl;
                cout << "Nicholas Tegar Mukti\t\t(672021053)"  << endl;
                cout << "Yosua Dhanny Adibudi Pratama\t(672021188)" << endl;
                cout << endl;

                systemPause();
                break;
            }

            case '5' : // exit
            {
                // output
                cout << endl;
                cout <<"\t  Program Selesai\n";
                cout <<"\t<-- TERIMAKASIH -->\n\n";

                break;
            }

            default : // jika user input salah
            {
                // output
                cout << "Maaf input anda tidak sesuai" << endl;
                cout << "Silahkan pilih angka (1-5)" << endl;

                systemPause();
                break;
            }
        }
    }
    return 0;
}
