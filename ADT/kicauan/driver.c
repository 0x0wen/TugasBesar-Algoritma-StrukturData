#include <stdio.h>
#include "kicauan.c"
#include "listdin_kicauan.c"

int main(){

    TabKicauan TK;

    /*
    Alur program:

    ** KICAUAN **

    Terdapat variabel global "TK" bertipe data TabKicau yang merupakan list dinamis yang menampung semua kicauan,
    saat pertama kali program di-load, semua kicauan dari .config dimasukan ke variabel tsb

    Kenapa perlu tipe data TabKicau agar InfoType nya bertipe data Kicau

    Fungsi yang perlu di-implementasikan:

    1. KICAU : membuat kicauan baru,
    setiap membuat kicauan baru, akan append ke variabel global TK

    2. KICAUAN : menampilkan semua kicauan milik id-user X,
    fungsi akan ngebaca semua kicauan pada TK dan melakukan print(Kicau) untuk kicauan yang merupakan
    kicauan milik user X

    3. SUKA_KICAUAN : untuk like kicauan dengan idKicau X,
    fungsi akan brute force search kicauan dengan idKicau X pada TabKicau dan melakukan penambahan like
    pada kicauan tsb

    4. UBAH_KICAUAN : edit kicauan yang udah ada,
    fungsi bakal ngecek apakah ada id kicauan yang dicari di dalam TK, kalo ada baru jalanin prosedur ubah

    ** DRAF KICAUAN **

    Terdapat atribut ".TDK" dari ADT user bertipe data TabDrafKicauan yang merupakan stack yang menampung semua
    draf kicau user X

    Fungsi yang perlu di-implementasikan:

    1. BUAT_DRAF  : input text draf kicauan
    2. LIHAT_DRAF : akses top of stack .TDK

    Dipanggil setelah setiap fungsi 1/2 dipanggil

    3. SIMPAN : ngepush kicauan tsb ke .TDK sebagai top of stack (khusus BUAT_DRAF)
    4. UBAH   : edit draf pada top of stack (khusus LIHAT_DRAF)
    5. HAPUS  : ngepop draf kicauan dari stack
    6. TERBIT : ngepop kicauan dari stack dan dimasukkan ke TK
    */


    return 0;
}