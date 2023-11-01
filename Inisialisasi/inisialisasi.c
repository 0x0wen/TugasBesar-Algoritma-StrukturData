#include <stdio.h>
#include "wordmachine.c"

void inisialisasi(){
    printf(".______    __    __  .______      .______    __  .______\n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n");
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /\n");
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    printf("\n");
    printf("Selamat datang di BurBir.\n");
    printf("\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode\n");
    printf("(pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    printf("\n");
    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");

    STARTWORD();

    printf("\n");
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");

    FILE* fptr;
    fptr = fopen("config-1/pengguna.config","r");
    char content[10];
    char content2[100];
    fgets(content,10,fptr);
    int i;
    for(i = 0; i < 33; i++){
        fgets(content2,100,fptr);
        printf("%s",content2);
    }
}