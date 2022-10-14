#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// variabel
string username, password, nama, pin, pwd, user, pinv;
long saldo, setor, transfer, topup, tarik, pajak;

// console functions
void clear_screen() // clear terminal/cmd
{
    #ifdef _WIN32
    system("cls");
    #elif defined(__linux__)
    system("clear");
    #endif
}

void system_pause() // pause terminal/cmd
{
    cin.ignore();
    cout << "Tekan Enter untuk lanjut . . . ";
    cin.get();
}

// headers
void header_start()
{
    cout << "====================================" << endl;
    cout << "\t\tBANK INI" <<endl;
    cout << "====================================" << endl;
}

void header_menu()
{
    cout << "====================================" << endl;
    cout << "\t\tMENU" << endl;
    cout << "====================================" << endl;
}

void header_login()
{
    cout << "====================================" << endl;
    cout << "\t\tLOGIN" << endl;
    cout << "====================================" << endl;
}

void header_register()
{
    cout << "====================================" << endl;
    cout << "\t\tREGISTER" << endl;
    cout << "====================================" << endl;

}

void header_informasi()
{
    cout << "====================================" << endl;
    cout << "\t\tINFORMASI" << endl;
    cout << "====================================" << endl;
}

void header_setor()
{
    cout << "====================================" << endl;
    cout << "\t\tSETOR UANG" << endl;
    cout << "====================================" << endl;
}

void header_tarik()
{
    cout << "====================================" << endl;
    cout << "\t\tTARIK TUNAI" << endl;
    cout << "====================================" << endl;
}

void header_transfer()
{
    cout << "====================================" << endl;
    cout << "\t\tTRANSFER UANG" << endl;
    cout << "====================================" << endl;
}

void header_topup()
{
    cout << "====================================" << endl;
    cout << "\tTOP UP E-WALLET" << endl;
    cout << "====================================" << endl;
}

void header_pajak()
{
    cout << "====================================" << endl;
    cout << "\t\tPAJAK" << endl;
    cout << "====================================" << endl;
}

void header_riwayat()
{
    cout << "====================================" << endl;
    cout << "\t\t RIWAYAT" << endl;
    cout << "====================================" << endl;
}

void header_logout()
{
    cout << "====================================" << endl;
    cout << "\t\tLOG OUT" << endl;
    cout << "====================================" << endl;
}

// functions declaration
void start_();
void menu_();
void login_();
void register_();
void informasi_();
long setor_();
long tarik_();
long transfer_();
long topup_();
long pajak_();
void riwayat_();
void exit_();

// main program
int main()
{
    start_();

    return 0;
}

// functions
void start_()
{
    char pilihan;
    clear_screen();
    header_start();
    cout << "1. Login\n";
    cout << "2. Register\n";
    cout << "3. Exit\n";
    cout << "Masukkan pilihan anda (1-3) : ";
    cin >> pilihan;
    cin.ignore();
    if (pilihan == '1')
    {
        login_();
    } else if(pilihan == '2')
    {
        register_();
    } else if (pilihan == '3')
    {
        exit_();
    } else
    {
        cout<< "Pillihan anda salah!\nSilahkan pilih 1-3\n";
        system_pause();
        start_();
    }
}

void login_()
{
    clear_screen();
    header_login();
    cout << "Username\t: ";
    cin >> username;
    cout << "Password\t: ";
    cin >> password;

    ifstream cek (username + ".txt");
    getline(cek, nama);
    getline(cek, user);
    getline(cek, pwd);
    cek.close();

    if(username == user && password == pwd)
    {
        menu_();
    } else if (username != user || password != pwd)
    {
        cout << "Username atau password anda salah!\n";
        system_pause();
        start_();
    }
}

void register_()
{
    clear_screen();
    header_register();

    cout << "Silahkan daftar\n";

    cout << "Nama Lengkap\t: ";
    getline(cin, nama);

    int cek;
    int a = nama.length();
    for(int i = 0;i < a; i++)
    {
        char x = nama.at(i);
        if(x != '0' && x != '1' && x != '2' && x != '3' && x != '4' && x != '5' && x != '6' && x != '7' && x != '8' && x != '9')
        {
           cek = 1;
        }
    }
    if(cek == 0)
    {
        cout <<"Nama harus berupa huruf!\n";
        system_pause();
        register_();
    }

    ofstream user;
    user.open("datauser.txt", ios::out | ios::app);
    user.close();

    cout << "Username\t: ";
    getline(cin, username);
    int j=username.size();
    for(int i = 0; i < j; i++)
        {
            char x = username.at(i);
            if(x ==' '){
              cout<< "Username tidak boleh menggunakan spasi\n";
              system_pause();
              register_();
            }
        }
    ifstream readuser;
    string output, buffer;
    readuser.open("datauser.txt");
    do
    {
        getline(readuser, buffer);
        if(buffer == username)
        {
            cout<<"Username sudah dipakai!";
            system_pause();
            register_();
        }
    } while(!readuser.eof());
    readuser.close();

    cout << "Password\t: ";
    getline(cin, password);

    cout << "PIN\t\t: ";
    cin >> pin;

    int b = pin.length();
    if(b != 6)
    {
        cout << "PIN harus berjumlah 6 digit!" << endl;
        system_pause();
        register_();
    } else if (b == 6)
    {
        for(int i = 0; i < b; i++)
        {
            char x = pin.at(i);

            if(x != '0' && x != '1' && x != '2' && x != '3' && x != '4' && x != '5' && x != '6' && x != '7' && x != '8' && x != '9')
            {
                cout<<"PIN harus berupa angka!" << endl;
                system_pause();
                register_();
            }
        }
    }

    cout << "Setoran Awal (min. Rp 50rb)\t: ";
    cin >> saldo;

    if(saldo < 50000)
    {
        cout << "Silakan isi lebih dari RP 50.000";
        cin.ignore();

        system_pause();
        register_();
    } else if (saldo >= 50000)
    {
        cout << "Selamat Akun anda berhasil dibuat!" << endl;

        ofstream user;
        user.open("datauser.txt",ios_base::app);
        user << username << endl;
        user.close();

        ofstream akun;
        akun.open(username + ".txt");
        akun << nama << endl << username << endl << password << endl << pin;
        akun.close();

        ofstream riwayat;
        riwayat.open(nama + "-riwayat.txt");
        riwayat << "[IN]    Setoran pertama Rp" << saldo << endl;
        riwayat.close();

        ofstream saldo_akun;
        saldo_akun.open(nama + "-saldo.bin", ios::out | ios::binary);
        saldo_akun.write(reinterpret_cast<char*>(&saldo),sizeof(saldo));
        saldo_akun.close();

        system_pause();
        start_();
    }
}

void menu_()
{
    char pilihan;
    clear_screen();
    header_menu();
    cout << "1. Informasi akun\n";
    cout << "2. Setor uang\n";
    cout << "3. Tarik tunai\n";
    cout << "4. Transfer uang\n";
    cout << "5. Top up e-wallet\n";
    cout << "6. Bayar pajak\n";
    cout << "7. Riwayat\n";
    cout << "8. Log out\n";
    cout << "Masukkan pilihan anda (1-8): ";
    cin >> pilihan;
    if (pilihan == '1')
    {
        informasi_();
    } else if (pilihan == '2')
    {
        setor_();
    } else if (pilihan == '3')
    {
        tarik_();
    } else if (pilihan == '4')
    {
        transfer_();
    } else if (pilihan == '5')
    {
        topup_();
    } else if (pilihan == '6')
    {
        pajak_();
    } else if (pilihan == '7')
    {
        riwayat_();
    } else if (pilihan == '8')
    {
        start_();
    } else
    {
        cout << endl << "Pilihan anda salah! Pilih satu angka antara 1-7!" << endl;
        system_pause();
        menu_();
    }

}

void informasi_()
{
    clear_screen();
    header_informasi();

    ifstream cek (username + ".txt");
    getline(cek, nama);
    cek.close();

    cout << "Nama Lengkap\t: " << nama << endl;

    fstream saldo_akun;
    saldo_akun.open(nama + "-saldo.bin", ios::in | ios::binary);
    saldo_akun.read(reinterpret_cast<char*>(&saldo), sizeof(saldo));
    saldo_akun.close();

    cout << "Saldo anda\t: Rp" << saldo << endl << endl;
    system_pause();
    menu_();
}

long setor_()
{
    clear_screen();
    header_setor();
    cout << "Jumlah yang ingin anda setor: ";
    cin >> setor;
    cout << "Masukkan PIN anda: ";
    cin >> pinv;

    ifstream cek (username + ".txt");
    getline(cek, nama);
    getline(cek, user);
    getline(cek, pwd);
    getline(cek, pin);
    cek.close();

    if(pin == pinv)
    {
        if (setor <= 0)
        {
            cout << endl << "Setor Gagal!" << endl;
            cout << "Jumlah setoran harus lebih dari Rp0" << endl << endl;
        } else
        {
            ofstream riwayat;
            riwayat.open(nama + "-riwayat.txt",ios_base::app);
            riwayat << "[IN]    Setor uang sebesar Rp" << setor << endl;
            riwayat.close();

            saldo += setor;
            cout << endl << "Setor Berhasil!" << endl << endl;
            cout << "Saldo rekening anda sekarang Rp" << saldo << endl << endl;

            ofstream saldo_akun;
            saldo_akun.open(nama + "-saldo.bin", ios::out | ios::binary);
            saldo_akun.write(reinterpret_cast<char*>(&saldo), sizeof(saldo));
            saldo_akun.close();
        }
    } else
    {
        cout << "PIN yang anda masukkan salah!\n";
        system_pause();
        menu_();
    }

    system_pause();
    menu_();
    return saldo;
}

long tarik_()
{
    clear_screen();
    header_tarik();
    cout << "Masukkan jumlah uang yang ingin ditarik: Rp. ";
    cin >> tarik;
    cout << "Masukkan PIN anda: ";
    cin >> pinv;

    ifstream cek (username + ".txt");
    getline(cek, nama);
    getline(cek, user);
    getline(cek, pwd);
    getline(cek, pin);
    cek.close();

    if (pin == pinv)
    {
        if (tarik <= 0)
        {
            cout << "\nTarik Uang Gagal!\nTarik uang harus lebih dari Rp0\n\n";
                tarik = 0;
        } else
        {
            if (saldo >= tarik)
            {
                ofstream riwayat;
                riwayat.open(nama + "-riwayat.txt",ios_base::app);
                riwayat << "[OUT]   Tarik uang sebesar Rp" << tarik << endl;
                riwayat.close();

                saldo -= tarik ;

                ofstream saldo_akun;
                saldo_akun.open(nama + "-saldo.bin", ios::out | ios::binary);
                saldo_akun.write(reinterpret_cast<char*>(&saldo), sizeof(saldo));
                saldo_akun.close();

                cout << "\nTarik Uang Berhasil!\n\n";
                cout << "Saldo rekening anda tersisa Rp. " << saldo << endl;
            } else
            {
            cout << "\nTarik Uang Gagal!\n";
            cout << "Saldo anda tidak mencukupi!\n\n";
            }
        }
    } else
    {
        cout << "PIN yang anda masukkan salah!\n";
        system_pause();
        menu_();
    }

    system_pause();
    menu_();
    return saldo;
}

long transfer_()
{
    clear_screen();
    header_transfer();
    cout << "Masukkan jumlah uang yang ingin ditransfer: Rp. ";
    cin >> transfer;
    cout << "Masukkan PIN anda: ";
    cin >> pinv;

    ifstream cek (username + ".txt");
    getline(cek, nama);
    getline(cek, user);
    getline(cek, pwd);
    getline(cek, pin);
    cek.close();

    if (pin == pinv)
    {
        if (transfer <= 0)
        {
            cout << "\nTransaksi Gagal!\nTransfer uang harus lebih dari Rp0\n\n";
            transfer = 0;
        } else
        {
            if (saldo >= transfer)
            {
                ofstream riwayat;
                riwayat.open(nama + "-riwayat.txt",ios_base::app);
                riwayat << "[OUT]   Transfer sebesar Rp" << transfer << endl;
                riwayat.close();

                saldo -= transfer ;

                ofstream saldo_akun;
                saldo_akun.open(nama + "-saldo.bin", ios::out | ios::binary);
                saldo_akun.write(reinterpret_cast<char*>(&saldo), sizeof(saldo));
                saldo_akun.close();

                cout << "\nTransfer Berhasil!\n\n";
                cout << "Saldo rekening anda tersisa Rp" << saldo << endl;
            } else
            {
                cout << "\nTransfer Gagal!\n";
                cout << "Saldo anda tidak mencukupi!\n\n";
            }
        }
    } else
    {
        cout << "PIN yang anda masukkan salah!\n";
        system_pause();
        menu_();
    }

    system_pause();
    menu_();
    return saldo;
}

long topup_()
{
    clear_screen();
    header_topup();
    cout << "Masukkan jumlah nominal: Rp. ";
    cin >> topup;
    cout << "Masukkan PIN anda: ";
    cin >> pinv;

    ifstream cek (username + ".txt");
    getline(cek, nama);
    getline(cek, user);
    getline(cek, pwd);
    getline(cek, pin);
    cek.close();

    if (pin == pinv)
    {
        if (topup <= 0)
        {
            cout << "\nTop Up Gagal!\nTop up e-wallet harus lebih dari Rp0\n\n";
            topup = 0;
        } else
        {
            if (saldo >= topup)
            {
                ofstream riwayat;
                riwayat.open(nama + "-riwayat.txt",ios_base::app);
                riwayat << "[OUT]   Top up e-wallet sebesar Rp" << topup << endl;
                riwayat.close();

                saldo -= topup;

                ofstream saldo_akun;
                saldo_akun.open(nama + "-saldo.bin", ios::out | ios::binary);
                saldo_akun.write(reinterpret_cast<char*>(&saldo), sizeof(saldo));
                saldo_akun.close();

                cout << "\nTop Up Berhasil!\n\n";
                cout << "Saldo rekening anda tersisa Rp" << saldo << endl << endl;
            } else
            {
                cout << "\nTop Up Gagal!\n";
                cout << "Saldo anda tidak mencukupi!\n\n";
            }
        }
    } else
    {
        cout << "PIN yang anda masukkan salah!\n";
        system_pause();
        menu_();
    }

    system_pause();
    menu_();
    return saldo;
}

long pajak_()
{
    clear_screen();
    header_pajak();
    cout << "Masukkan jumlah pajak yang ingin anda bayar: ";
    cin >> pajak;
    cout << "Masukkan PIN anda: ";
    cin >> pinv;

    ifstream cek (username + ".txt");
    getline(cek, nama);
    getline(cek, user);
    getline(cek, pwd);
    getline(cek, pin);
    cek.close();

    if (pin == pinv)
    {
        if (pajak > saldo)
        {
            cout << endl << "Pembayaran Pajak Gagal!" << endl;
            cout << "Saldo anda tidak mencukupi." << endl << endl;
        } else if (pajak <= 0)
        {
            cout << endl << "Pembayaran Pajak Gagal!" << endl;
            cout << "Pembayaran pajak harus lebih dari Rp0" << endl << endl;
        } else
        {
            ofstream riwayat;
            riwayat.open(nama + "-riwayat.txt",ios_base::app);
            riwayat << "[OUT]   Bayar pajak sebesar Rp" << pajak << endl;
            riwayat.close();

            saldo -= pajak;

            ofstream saldo_akun;
            saldo_akun.open(nama + "-saldo.bin", ios::out | ios::binary);
            saldo_akun.write(reinterpret_cast<char*>(&saldo), sizeof(saldo));
            saldo_akun.close();

            cout << endl << "Pajak Berhasil Dibayar!" << endl << endl;
            cout << "Saldo rekening anda tersisa Rp" << saldo << endl << endl;
        }
    } else
    {
        cout << "PIN yang anda masukkan salah!\n";
        system_pause();
        menu_();
    }

    system_pause();
    menu_();
    return saldo;
}

void riwayat_()
{
    clear_screen();
    header_riwayat();

    string data, output, buffer;
    ifstream riwayat;
    riwayat.open(nama + "-riwayat.txt");

    while (!riwayat.eof())
    {
        getline(riwayat, data);
        output.append(buffer);
        cout << output << data << endl;
    }

    riwayat.close();

    fstream saldo_akun;
    saldo_akun.open(nama + "-saldo.bin", ios::in | ios::binary);
    saldo_akun.read(reinterpret_cast<char*>(&saldo), sizeof(saldo));
    saldo_akun.close();

    cout << "[INFO]  Saldo di rekening anda saat ini Rp" << saldo << endl << endl;
    system_pause();
    menu_();
}

void exit_()
{
    clear_screen();
    header_logout();
    cout << "\t\tTERIMA KASIH" << endl;
    cout << "\t TELAH MENGGUNAKAN BANK INI" << endl << endl << "Tekan Enter untuk melanjutkan . . .";
    cin.get();
    exit(0);
}
