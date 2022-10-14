#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

FILE *fp;
char fileName[100]= "data_tamu.txt";

struct tamu{
    char nama[30], jenis_kelamin;
    int no_identitas, jumlah_orang, no_kamar, tgl_checkin, bln_checkin, thn_checkin, tgl_checkout, bln_checkout, thn_checkout;
    struct tamu *next;
}*head, *tail, *current;

void loading(){
    system("cls");
    char load = 219;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t");
    printf("Loading : ");
    for(int l =0; l<50; l++){
        printf("%c", load);
        Sleep(50);
    }
}

void login(){
    char username[10], pass[10];
    loading();
    do{
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t ");
        printf("LOGIN\n\n");
        printf("\t\t\t\t\t");
        printf("Username\t: ");
        scanf(" %s",&username);
        printf("\n\t\t\t\t\t");
        printf("Password\t: ");
        scanf(" %s",&pass);
        if(strcmp(username,"admin")==0 && strcmp(pass,"admin")==0){
            printf("\n\t\t\t\t\t    ");printf("Selamat Datang");getch();
        }else if(strcmp(username,"admin")!=0){
            printf("\n\t\t\t\t\t");printf("Username salah\n");getch();
        }else if(strcmp(pass,"admin")!=0){
            printf("\n\t\t\t\t\t");printf("Password salah\n");getch();
        }
    }while(strcmp(username,"admin")!=0 || strcmp(pass,"admin")!=0);
}

int hitung(struct tamu *head){
    struct tamu *tmp;
    int jml = 0;
    tmp = head;
    while (tmp != NULL){
        jml++;
        tmp = tmp -> next;
    }
    return jml;
}

void write_file(){
    fp = fopen(fileName, "a");
        fprintf(fp, "%s;", current->nama);
        fprintf(fp, "%d;", current->no_identitas);
        fprintf(fp, "%c;", current->jenis_kelamin);
        fprintf(fp, "%d;", current->jumlah_orang);
        fprintf(fp, "%d;", current->no_kamar);
        fprintf(fp, "%d;", current->tgl_checkin);
        fprintf(fp, "%d;", current->bln_checkin);
        fprintf(fp, "%d;", current->thn_checkin);
        fprintf(fp, "%d;", current->tgl_checkout);
        fprintf(fp, "%d;", current->bln_checkout);
        fprintf(fp, "%d;", current->thn_checkout);
        fprintf(fp, "\n");
    fclose(fp);
}

void edit_file(){
    fp = fopen(fileName, "w");

    struct tamu *temp;
    temp = head;
    while (temp != NULL){
        fprintf(fp, "%s;", temp->nama);
        fprintf(fp, "%d;", temp->no_identitas);
        fprintf(fp, "%c;", temp->jenis_kelamin);
        fprintf(fp, "%d;", temp->jumlah_orang);
        fprintf(fp, "%d;", temp->no_kamar);
        fprintf(fp, "%d;", temp->tgl_checkin);
        fprintf(fp, "%d;", temp->bln_checkin);
        fprintf(fp, "%d;", temp->thn_checkin);
        fprintf(fp, "%d;", temp->tgl_checkout);
        fprintf(fp, "%d;", temp->bln_checkout);
        fprintf(fp, "%d;", temp->thn_checkout);
        fprintf(fp, "\n");
    temp = temp-> next;
    }
     fclose(fp);
}

void tulis_file(){
    current = head;
    while(current != NULL){
        write_file();
        current = current -> next;
    }
}

void read_file(){
    fp = fopen(fileName, "r");
    char ch, line[100], *ptr = NULL, *p;
    int i = 0;
    while (EOF != fscanf(fp, "%s", line))
    {
        current = (struct tamu*)malloc(sizeof(struct tamu));

        ptr = strtok(line, ";");
        strcpy(current->nama, ptr);

    while (NULL != (ptr = strtok(NULL, ";")))
    {
        i++;
        /* 5. Store the tokens as per structure members , where (i==0) is first member and so on.. */
        if(i == 1){
            current->no_identitas = strtol(ptr, &p, 10);
        }
        else if(i == 2){
            current->jenis_kelamin = *ptr;
        }
        else if (i == 3){
            current->jumlah_orang = strtol(ptr, &p, 10);
        }else if (i == 4){
            current->no_kamar = strtol(ptr, &p, 10);
        }
        else if (i == 5){
            current->tgl_checkin = strtol(ptr, &p, 10);
        }else if (i == 6){
            current->bln_checkin = strtol(ptr, &p, 10);
        }else if (i == 7){
             current->thn_checkin = strtol(ptr, &p, 10);
        }else if (i == 8){
             current->tgl_checkout = strtol(ptr, &p, 10);
        }else if (i == 9){
            current->bln_checkout = strtol(ptr, &p, 10);
        }else if (i == 10){
            current->thn_checkout = strtol(ptr, &ptr, 10);
        }
    }
        if(head == NULL){
                head = tail = current;
        }
        else{
            tail->next = current;
            tail = current;
        }
        tail->next = NULL;
    i = 0;        /* Reset value of i */
    }
    fclose(fp);
}

void buat_data(){
    fp = fopen(fileName, "w");
    fclose(fp);
    head = NULL;
    system("cls");
    printf("  ====================================================================================================================");
    printf("\n  ||\t\t\t\t\t\t     BUAT DATA\t\t\t\t\t\t\t    ||\n");
    printf("  ====================================================================================================================");
    printf("\n0.Kembali");
    int jumlah_input;
    char nama[30], jenis_kelamin;
    int no_identitas, jumlah_orang, no_kamar, tgl_checkin, bln_checkin, thn_checkin, tgl_checkout, bln_checkout, thn_checkout;
    printf("\n\n\t\t\t\t\t      ");
    printf("Masukkan Jumlah Data : ");
    scanf("%d",&jumlah_input);
    if(jumlah_input <= 0){
        main_menu();
    }else{
        for(int j = 0; j < jumlah_input; j++){
            int cek = 0;
            current = (struct tamu*)malloc(sizeof(struct tamu));
            printf("\n\n\t\t\t\t\t      ");
            printf("Data Tamu Hotel ke-%d\n",j+1);
            do{
                printf("\n\t\t\t\t\t");
                printf("Nama\t\t\t: ");fflush(stdin);gets(nama);
            } while (cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("No.Identitas\t\t: ");scanf("%d", &no_identitas);
                if(no_identitas <= 0 ){
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                }
            }while(no_identitas <= 0);
            do{
                printf("\t\t\t\t\t");
                printf("Jenis Kelamin(L/P)\t: ");scanf(" %c", &jenis_kelamin);
                if ( jenis_kelamin == 'L' || jenis_kelamin == 'P' || jenis_kelamin == 'l' || jenis_kelamin == 'p'){
                    if (jenis_kelamin == 'l' || jenis_kelamin == 'p'){
                        jenis_kelamin -= 32;
                    }
                    cek = 0;
                } else{
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Jumlah Orang(1-4)\t: ");scanf("%d", &jumlah_orang);
                if (jumlah_orang <= 4 && jumlah_orang > 0){
                    cek = 0;
                }else{
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while (cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("No.Kamar(1-30)\t\t: ");scanf("%d", &no_kamar);
                if (no_kamar <= 30 && no_kamar > 0){
                    cek = 0;
                }else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Tanggal Check-In(1-31)\t: ");scanf("%d", &tgl_checkin);
                if(tgl_checkin <= 31 && tgl_checkin > 0 ){
                    cek = 0;
                } else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Bulan Check-In(1-12)\t: ");scanf("%d", &bln_checkin);
                if(bln_checkin <= 12 && bln_checkin > 0){
                    cek = 0;
                }else{
                     printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                     cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Tahun Check-In\t\t: ");scanf("%d", &thn_checkin);
                 if (thn_checkin <= 0){
                   printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                }
            } while (thn_checkin <= 0);
            do{
                printf("\t\t\t\t\t");
                printf("Tanggal Check-Out(1-31)\t: ");scanf("%d", &tgl_checkout);
                if(tgl_checkout <= 31 && tgl_checkout > 0){
                    cek = 0;
                } else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Bulan Check-Out(1-12)\t: ");scanf("%d", &bln_checkout);
                if(bln_checkout <= 12 && bln_checkout >0){
                    cek = 0;
                } else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Tahun Check-Out\t\t: ");scanf("%d", &thn_checkout);
                if (thn_checkout <=0){
                   printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                }
            }while (thn_checkout <= 0);

            strcpy(current->nama, nama);
            current->no_identitas = no_identitas;
            current->jenis_kelamin = jenis_kelamin;
            current->jumlah_orang = jumlah_orang;
            current->no_kamar = no_kamar;
            current->tgl_checkin = tgl_checkin;
            current->bln_checkin = bln_checkin;
            current->thn_checkin = thn_checkin;
            current->tgl_checkout = tgl_checkout;
            current->bln_checkout = bln_checkout;
            current->thn_checkout = thn_checkout;

            write_file();

            if(head == NULL){
                head = tail = current;
            }
            else{
                tail->next = current;
                tail = current;
            }
            tail->next = NULL;
        }
        printf("\n  ====================================================================================================================");
        printf("\n\t\t\t\t\t      ");
        printf("Data berhasil diinput");
    }
	getch();
}

void lihat_data(){
    loading();
    system("cls");
    printf("  ====================================================================================================================");
    printf("\n  ||\t\t\t\t\t\t     LIHAT DATA\t\t\t\t\t\t\t    ||\n");
    printf("  ====================================================================================================================");
    printf("\n\n  ====================================================================================================================");
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
    if(head == NULL){
        printf("\n\t\t\t\t\t ");printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        current = head;
        while(current != NULL){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
            current = current->next;
            printf("\n");
        }
    }
    printf("\n");
    getch();
}

void tambah_data(){
    system("cls");
    printf("  ====================================================================================================================");
    printf("\n  ||\t\t\t\t\t\t    TAMBAH DATA\t\t\t\t\t\t\t    ||\n");
    printf("  ====================================================================================================================");
    printf("\n0.Kembali");
    int jumlah_tambah;
    char nama[30], jenis_kelamin;
    int no_identitas, jumlah_orang, no_kamar, tgl_checkin, bln_checkin, thn_checkin, tgl_checkout, bln_checkout, thn_checkout;
    if(head == NULL){
        printf("\n\n\t\t\t\t\t   ");printf("Belum ada Data, silahkan input dulu!\n");getch();
    }else{printf("\n\n\t\t\t\t\t      ");
        printf("\n\n\t\t\t\t\t      ");printf("Masukkan Jumlah Data : ");
        scanf("%d",&jumlah_tambah);
    if(jumlah_tambah <= 0){
        main_menu();
    }else{
         for(int j = 0; j < jumlah_tambah; j++){
            int cek = 0;
            current = (struct tamu*)malloc(sizeof(struct tamu));
            printf("Data Tamu Hotel ke-%d\n",j+1);
            do{
                printf("\n\t\t\t\t\t");
                printf("Nama\t\t\t: ");fflush(stdin);gets(nama);
            } while (cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("No.Identitas\t\t: ");scanf("%d", &no_identitas);
                if(no_identitas <= 0){
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                }
            }while(no_identitas <= 0);
            do{
                printf("\t\t\t\t\t");
                printf("Jenis Kelamin(L/P)\t: ");scanf(" %c", &jenis_kelamin);
                if ( jenis_kelamin == 'L' || jenis_kelamin == 'P' || jenis_kelamin == 'l' || jenis_kelamin == 'p'){
                    if (jenis_kelamin == 'l' || jenis_kelamin == 'p'){
                        jenis_kelamin -= 32;
                    }
                    cek = 0;
                } else{
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Jumlah Orang(1-4)\t: ");scanf("%d", &jumlah_orang);
                if (jumlah_orang <= 4 && jumlah_orang > 0){
                    cek = 0;
                }else{
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while (cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("No.Kamar(1-30)\t\t: ");scanf("%d", &no_kamar);
                if (no_kamar <= 30 && no_kamar > 0){
                    cek = 0;
                }else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Tanggal Check-In(1-31)\t: ");scanf("%d", &tgl_checkin);
                if(tgl_checkin <= 31 && tgl_checkin > 0 ){
                    cek = 0;
                } else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Bulan Check-In(1-12)\t: ");scanf("%d", &bln_checkin);
                if(bln_checkin <= 12 && bln_checkin > 0){
                    cek = 0;
                }else{
                     printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                     cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Tahun Check-In\t\t: ");scanf("%d", &thn_checkin);
                 if (thn_checkin <= 0){
                   printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                }
            } while (thn_checkin <= 0);
            do{
                printf("\t\t\t\t\t");
                printf("Tanggal Check-Out(1-31)\t: ");scanf("%d", &tgl_checkout);
                if(tgl_checkout <= 31 && tgl_checkout > 0){
                    cek = 0;
                } else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Bulan Check-Out(1-12)\t: ");scanf("%d", &bln_checkout);
                if(bln_checkout <= 12 && bln_checkout >0){
                    cek = 0;
                } else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
            }while(cek != 0);
            do{
                printf("\t\t\t\t\t");
                printf("Tahun Check-Out\t\t: ");scanf("%d", &thn_checkout);
                if (thn_checkout <=0){
                   printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                }
            }while (thn_checkout <= 0);

            strcpy(current->nama, nama);
            current->no_identitas = no_identitas;
            current->jenis_kelamin = jenis_kelamin;
            current->jumlah_orang = jumlah_orang;
            current->no_kamar = no_kamar;
            current->tgl_checkin = tgl_checkin;
            current->bln_checkin = bln_checkin;
            current->thn_checkin = thn_checkin;
            current->tgl_checkout = tgl_checkout;
            current->bln_checkout = bln_checkout;
            current->thn_checkout = thn_checkout;

            write_file();

            if(head == NULL){
                head = tail = current;
            }
            else{
                tail->next = current;
                tail = current;
            }
            tail->next = NULL;
         }
    }
	printf("\n  ====================================================================================================================");
	printf("\n\t\t\t\t\t      ");
	printf("Data berhasil diinput");
	getch();
}
}

void hapus_data(){
    system("cls");
    printf("  ====================================================================================================================");
    printf("\n  ||\t\t\t\t\t\t     HAPUS DATA\t\t\t\t\t\t\t    ||\n");
    printf("  ====================================================================================================================");
    printf("\n0.Kembali");
    printf("\n\n  ====================================================================================================================");
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
      if(head == NULL){
        printf("\n\t\t\t\t\t ");printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        current = head;
        int i = 1;
        while(current != NULL){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
            current = current->next;
            printf("\n");
            i++;
        }
        i = 1;
        printf("\n");
        struct tamu *temp = head;
        current = head;

        int no_identitas;
        printf("\n\t\t\t\t\t ");printf("Cari No.Identitas yang mau dihapus : ");scanf("%d", &no_identitas);
        if(no_identitas <= 0){
            main_menu();
        }else{
            int index = 0;
            while (current != NULL) {
                if (current->no_identitas == no_identitas){
                    break;
                }
                index++;
                current = current->next;
            }

            if (index == 0){
                head = temp->next;
                free(temp);

                remove(fileName);
                tulis_file();
                printf("\n\t\t\t\t\t ");printf("Data berhasil dihapus");
            }else{
                for (int i=0; temp!=NULL && i<index-1; i++){
                    temp = temp->next;
                }
                if (temp == NULL || temp->next == NULL){
                    printf("\n\t\t\t\t\t ");printf("Data tidak ada");
                }else{
                    if(temp->next->next == NULL){
                        free(temp->next);
                        temp->next = NULL;
                        tail = temp;
                    } else {
                    struct tamu *next = temp->next->next;
                    free(temp->next);
                    temp->next = next;
                    }
                    remove(fileName);
                    tulis_file();

                    printf("\n\t\t\t\t\t ");printf("Data berhasil dihapus");
                }
            }
        }
    }
    getch();
}

void edit_nama(){
    char namaBaru[30];
    printf("\n\t\t\t\t\t");printf("Nama baru : ");fflush(stdin);gets(namaBaru);
    strcpy(current->nama, namaBaru);
    remove(fileName);
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_no_identitas(){
    int noIdentitasBaru;
    do{
        printf("\n\t\t\t\t\t");printf("No.Identitas baru : ");scanf("%d", &noIdentitasBaru);
        if (noIdentitasBaru <= 0){
             printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
        }
    }while (noIdentitasBaru <= 0);
    current->no_identitas = noIdentitasBaru;
    printf("\n\t\t\t\t\tData berhasil diedit");
    edit_file();
}

void edit_jk(){
    char jkBaru;
    int cek = 0;
    do{
        printf("\n\t\t\t\t\t");printf("Jenis Kelamin baru(L/P) : ");scanf(" %c", &jkBaru);
            if ( jkBaru == 'L' || jkBaru == 'P' || jkBaru == 'l' || jkBaru == 'p'){
                    if (jkBaru == 'l' || jkBaru == 'p'){
                        jkBaru-= 32;
                    }
                    cek = 0;
            } else{
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
                }
    }while(cek != 0);
    current->jenis_kelamin = jkBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_jml_org(){
    int jmlOrgBaru;
    int cek = 0;
    do{
        printf("\n\t\t\t\t\t");printf("Jumlah Orang baru(1-4) : ");scanf("%d", &jmlOrgBaru);
            if (jmlOrgBaru <= 4 && jmlOrgBaru > 0){
                    cek = 0;
            }else{
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
            }
    }while (cek != 0);
    current->jumlah_orang = jmlOrgBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_no_kmr(){
    int noKmrBaru;
    int cek = 0;
    do{
        printf("\n\t\t\t\t\t");printf("No.Kamar baru(1-30) : ");scanf("%d", &noKmrBaru);
            if (noKmrBaru <= 30 && noKmrBaru > 0){
                    cek = 0;
            }else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
            }
    }while(cek != 0);
    current->no_kamar = noKmrBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_tgl_ci(){
    int tglCiBaru;
    int cek = 0;
    do{
        printf("\n\t\t\t\t\t");printf("Tanggal Check-In baru(1-31) : ");scanf("%d", &tglCiBaru);
            if(tglCiBaru <= 31 && tglCiBaru > 0 ){
                    cek = 0;
            } else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
            }
    }while(cek != 0);
    current->tgl_checkin = tglCiBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_bln_ci(){
    int blnCiBaru;
    int cek = 0;
    do{
        printf("\n\t\t\t\t\t");printf("Bulan Check-In baru(1-12) : ");scanf("%d", &blnCiBaru);
            if(blnCiBaru <= 12 && blnCiBaru > 0){
                    cek = 0;
            }else{
                     printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                     cek = 1;
            }
    }while(cek != 0);
    current->bln_checkin = blnCiBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_thn_ci(){
    int thnCiBaru;
    printf("\n\t\t\t\t\t");printf("Tahun Check-In baru : ");scanf("%d", &thnCiBaru);
    current->thn_checkin = thnCiBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_tgl_co(){
    int tglCoBaru;
    int cek = 0;
    do{
        printf("\n\t\t\t\t\t");printf("Tanggal Check-Out baru(1-31) : ");scanf("%d", &tglCoBaru);
            if(tglCoBaru <= 31 && tglCoBaru > 0 ){
                    cek = 0;
            } else {
                    printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                    cek = 1;
            }
    }while(cek != 0);
    current->tgl_checkout = tglCoBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_bln_co(){
    int blnCoBaru;
    int cek = 0;
    do{
        printf("\n\t\t\t\t\t");printf("Bulan Check-Out baru(1-12) : ");scanf("%d", &blnCoBaru);
            if(blnCoBaru <= 12 && blnCoBaru > 0){
                    cek = 0;
            }else{
                     printf("\t\t\t\t\t    ");printf("Maaf Data Yang Anda Inputkan Salah\n");
                     cek = 1;
            }
    }while(cek != 0);
    current->bln_checkout = blnCoBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void edit_thn_co(){
    int thnCoBaru;
    printf("\n\t\t\t\t\t");printf("Tanggal Check-Out baru : ");scanf("%d", &thnCoBaru);
    current->thn_checkout = thnCoBaru;
    edit_file();
    printf("\n\t\t\t\t\tData berhasil diedit");
}

void menu_edit(){
    int pilihan_menu;
    do{
    system("cls");
    printf("  ====================================================================================================================");
    printf("\n  ||\t\t\t\t\t\t    Edit Data Tamu\t\t\t\t\t\t    ||\n");
    printf("  ====================================================================================================================");
    printf("\n\n  ====================================================================================================================");
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
    printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
    printf("\n\n\t\t  1. NAMA\t\t\t4. JUMLAH ORANG\t\t  7. BULAN CHECK-IN\t 10.BULAN CHECK-OUT ");
    printf("\n\t\t  2. NO. IDENTITAS\t\t5. NO.KAMAR\t\t  8. TAHUN CHECK-IN\t 11.TAHUN CHECK-OUT");
    printf("\n\t\t  3. JENIS KELAMIN\t\t6. TANGGAL CHECK-IN\t  9. TANGGAL CHECK-OUT\t 12.KEMBALI");
    printf("\n\n  ====================================================================================================================");
    printf("\n\n\t\t\t\t\t\t   Pilihan : ");
    scanf("%d", &pilihan_menu);
    switch(pilihan_menu){
        case 1 : edit_nama();break;
        case 2 : edit_no_identitas();break;
        case 3 : edit_jk();break;
        case 4 : edit_jml_org();break;
        case 5 : edit_no_kmr();break;
        case 6 : edit_tgl_ci();break;
        case 7 : edit_bln_ci();break;
        case 8 : edit_thn_ci();break;
        case 9 : edit_tgl_co();break;
        case 10 : edit_bln_co();break;
        case 11 : edit_thn_co();break;
        case 12 : main_menu();break;
        default : printf("\n\t\t\t\t\tMaaf pilihan anda tidak tersedia");getch();break;
        }
    }while(pilihan_menu !=12);
    getch();
}

void edit_data(){
    int nemu = 0;
    system("cls");
    printf("  ====================================================================================================================");
    printf("\n  ||\t\t\t\t\t\t     EDIT DATA\t\t\t\t\t\t\t    ||\n");
    printf("  ====================================================================================================================");
    printf("\n 0.Kembali\n");
    if(head==NULL){
        printf("\n\t\t\t\t\t ");printf("Belum ada Data, silahkan input dulu!\n");
    }else{
        current = head;
        int no_kamar;
        printf("\n\t\t\t\t\t ");printf("Cari No.Kamar yang mau diedit : ");scanf("%d", &no_kamar);
        if(no_kamar <= 0){
                main_menu();
        }else{
        while (current != NULL) {
            if (current->no_kamar == no_kamar){
                nemu = 1;
                break;
            }else if(current == NULL || current->next==NULL){
               nemu = 0;
            }
            current = current->next;
        }
        if(nemu == 0){
             printf("\n\t\t\t\t\t");printf("Data tidak ada");
        }else{
            menu_edit();
        }
    }
    }
    getch();
}
void tampil_cari(){
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
    printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
}

void cari_nama(){
    char cari[30];
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Nama yang dicari : "); fflush(stdin);gets(cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (strcmp(current->nama,cari) == 0){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_no_identitas(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan No. Identitas yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->no_identitas == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_jk(){
    char cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Jenis Kelamin yang dicari : "); scanf(" %c", &cari);
    if (cari == 'l' || cari == 'p'){
        cari -=32;
    }
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->jenis_kelamin == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_jml_org(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Jumlah Orang yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->jumlah_orang == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_no_kmr(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan No. Kamar yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->no_kamar == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_tgl_ci(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Tanggal Check-In yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->tgl_checkin == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_bln_ci(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Bulan Check-In yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->bln_checkin == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_thn_ci(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Tahun Check-In yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->thn_checkin == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_tgl_co(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Tanggal Check-Out yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->tgl_checkout == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_bln_co(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Bulan Check-Out yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->bln_checkout == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}
void cari_thn_co(){
    int cari;
    current = head;
    printf("\n\t\t\t\t\t ");printf("Masukkan Tahun Check-Out yang dicari : "); scanf("%d", &cari);
    printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
    printf("  ====================================================================================================================\n");
       while (current != NULL) {
        if (current->thn_checkout == cari){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d\n", current->nama, current->no_identitas, current->jenis_kelamin, current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
        }
        current = current->next;
    }
    getch();
}

void cari_data(){
    if(head==NULL){
        printf("\nBelum ada Data, silahkan input dulu!\n");
    }else{
        int pilihan_menu;
        do{
        system("cls");
        printf("  ====================================================================================================================");
        printf("\n  ||\t\t\t\t\t\t    Cari Data Tamu\t\t\t\t\t\t    ||\n");
        printf("  ====================================================================================================================");
        printf("\n  ====================================================================================================================");
        printf("\n\t\t  1. NAMA\t\t\t4. JUMLAH ORANG\t\t  7. BULAN CHECK-IN\t 10.BULAN CHECK-OUT ");
        printf("\n\t\t  2. NO. IDENTITAS\t\t5. NO.KAMAR\t\t  8. TAHUN CHECK-IN\t 11.TAHUN CHECK-OUT");
        printf("\n\t\t  3. JENIS KELAMIN\t\t6. TANGGAL CHECK-IN\t  9. TANGGAL CHECK-OUT\t 12.KEMBALI");
        printf("\n\n  ====================================================================================================================");
        printf("\n\n\t\t\t\t\t\t   Pilihan : ");
        scanf("%d", &pilihan_menu);
        switch(pilihan_menu){
            case 1 : cari_nama();break;
            case 2 : cari_no_identitas();break;
            case 3 : cari_jk();break;
            case 4 : cari_jml_org();break;
            case 5 : cari_no_kmr();break;
            case 6 : cari_tgl_ci();break;
            case 7 : cari_bln_ci();break;
            case 8 : cari_thn_ci();break;
            case 9 : cari_tgl_co();break;
            case 10 : cari_bln_co();break;
            case 11 : cari_thn_co();break;
            case 12 : main_menu();break;
            default : printf("\n\t\t\t\t\tMaaf pilihan anda tidak tersedia");getch();break;
            }
        }while(pilihan_menu !=12);
    }
    getch();
}

void display(){
    printf("Tabel yang diurutkan :\n");
    current = head;
        int i = 1;
        printf("\n    Nama\t\t  No.Identitas\t  Jenis Kelamin\t Jumlah Orang\tNo.Kamar\tCheck-In\tCheck-Out\n");
        printf("  ====================================================================================================================\n");
        while(current != NULL){
            printf("    %s\t\t  %d\t  %c\t\t   %d\t\t%d\t\t%d-%d-%d\t%d-%d-%d", current->nama, current->no_identitas, current->jenis_kelamin,
                   current->jumlah_orang, current->no_kamar, current->tgl_checkin, current->bln_checkin, current->thn_checkin, current->tgl_checkout, current->bln_checkout, current->thn_checkout);
            current = current->next;
            printf("\n");
            i++;
        }
        i = 1;
}

void urut_nama(struct tamu** head)
{
    int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (strcmp(p1->nama, p2->nama) > 0)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_no_identitas(struct tamu** head){
    int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->no_identitas > p2->no_identitas)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_jk(struct tamu** head){
    int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->jenis_kelamin > p2->jenis_kelamin)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_jml_org(struct tamu** head){
 int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->jumlah_orang > p2->jumlah_orang)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_no_kmr(struct tamu** head){
    int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->no_kamar > p2->no_kamar)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_tgl_ci(struct tamu** head){
    int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->tgl_checkin > p2->tgl_checkin)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_bln_ci(struct tamu** head){
    int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->bln_checkin > p2->bln_checkin)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_thn_ci(struct tamu** head){
int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->thn_checkin > p2->thn_checkin)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_tgl_co(struct tamu** head){
int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->tgl_checkout > p2->tgl_checkout)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_bln_co(struct tamu** head){
int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->bln_checkout > p2->bln_checkout)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}
void urut_thn_co(struct tamu** head){
int jml = hitung(*head);
    struct tamu** temp;
    int i, j, swapped;
    struct tamu *p1,*p2;
    for (i = 0; i <= jml; i++)
    {
        temp = head;
        swapped = 0;
        for (j = 0; j < jml - i - 1; j++)
        {
            p1 = *temp;
            p2 = p1->next;
            if (p1->thn_checkout > p2->thn_checkout)
            {
                //update the link after swapping
                struct tamu* tmp;
                tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                *temp = p2;
                swapped = 1;
            }
            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    display();
    getch();
    return;
}

void urut_data(){
        system("cls");
        printf("  ====================================================================================================================");
        printf("\n  ||\t\t\t\t\t\tUrutkan Data Tamu\t\t\t\t\t\t    ||\n");
        printf("  ====================================================================================================================");
     if(head==NULL){
        printf("\nBelum ada Data, silahkan input dulu!\n");
    }else{
        int pilihan_menu;
        do{
        system("cls");
        printf("  ====================================================================================================================");
        printf("\n  ||\t\t\t\t\t\tUrutkan Data Tamu\t\t\t\t\t\t    ||\n");
        printf("  ====================================================================================================================");
        printf("\n  ====================================================================================================================");
        printf("\n\t\t  1. NAMA\t\t\t4. JUMLAH ORANG\t\t  7. BULAN CHECK-IN\t 10.BULAN CHECK-OUT ");
        printf("\n\t\t  2. NO. IDENTITAS\t\t5. NO.KAMAR\t\t  8. TAHUN CHECK-IN\t 11.TAHUN CHECK-OUT");
        printf("\n\t\t  3. JENIS KELAMIN\t\t6. TANGGAL CHECK-IN\t  9. TANGGAL CHECK-OUT\t 12.KEMBALI");
        printf("\n\n  ====================================================================================================================");
        printf("\n\n\t\t\t\t\t\t   Pilihan : ");
        scanf("%d", &pilihan_menu);
        switch(pilihan_menu){
            case 1 : urut_nama(&head);break;
            case 2 : urut_no_identitas(&head);break;
            case 3 : urut_jk(&head);break;
            case 4 : urut_jml_org(&head);break;
            case 5 : urut_no_kmr(&head);break;
            case 6 : urut_tgl_ci(&head);break;
            case 7 : urut_bln_ci(&head);break;
            case 8 : urut_thn_ci(&head);break;
            case 9 : urut_tgl_co(&head);break;
            case 10 : urut_bln_co(&head);break;
            case 11 : urut_thn_co(&head);break;
            case 12 : main_menu();break;
            default : printf("\n\t\t\t\t\tMaaf pilihan anda tidak tersedia");getch();break;
            }
        }while(pilihan_menu !=12);
    }
    getch();
}


void author(){
system("cls");
printf("\n\n\n\n\n\n\n\n");
printf("\t\t\t\t\t ");
printf("==================================");
printf("\n\t\t\t\t\t ");
printf("||\t KELOMPOK WIBU YA?\t ||");
printf("\n\t\t\t\t\t ");
printf("||\t\t\t\t ||");
printf("\n\t\t\t\t\t ");
printf("||\tNICHOLAS TEGAR MUKTI     ||");
printf("\n\t\t\t\t\t ");
printf("||\t     672021053\t\t ||");
printf("\n\t\t\t\t\t ");
printf("||\t\t\t\t ||");
printf("\n\t\t\t\t\t ");
printf("|| YOSUA DHANNY ADIBUDI PRATAMA ||");
printf("\n\t\t\t\t\t ");
printf("||\t     672021188\t\t ||");
printf("\n\t\t\t\t\t ");
printf("==================================\n");
exit(0);
}

void main_menu(){
int pilihan_menu;
    do{
        system("cls");
        printf("  ====================================================================================================================");
        printf("\n  ||\t\t\t\t\t\t     HOTEL\t\t\t\t\t\t\t    ||\n");
        printf("  ====================================================================================================================");
        printf("\n\n\t\t  1. Buat Data\t\t\t\t4. Hapus Data\t\t\t  7. Urutkan Data");
        printf("\n\t\t  2. Lihat Data\t\t\t\t5. Edit Data\t\t\t  8. Exit");
        printf("\n\t\t  3. Tambah Data\t\t\t6. Cari Data");
        printf("\n\n  ====================================================================================================================");
        printf("\n\n\t\t\t\t\t\t   Pilihan : ");
        scanf("%d", &pilihan_menu);
        switch(pilihan_menu){
            case 1 :buat_data();break;
            case 2 :lihat_data();break;
            case 3 :tambah_data();break;
            case 4 :hapus_data();break;
            case 5 :edit_data();break;
            case 6 :cari_data();break;
            case 7 :urut_data();break;
            case 8 :author();break;
            default :printf("\n\t\t\t\t\tMaaf pilihan anda tidak tersedia");getch();break;
        }
    }while(pilihan_menu !=8);
}

int main(){
    read_file();
    system("color 4f");
    login();
    main_menu();
    return 0;
}
