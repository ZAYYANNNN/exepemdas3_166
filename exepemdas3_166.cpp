#include <iostream>



using namespace std;

class bidangDatar {
private:
    int x;                                               // variable untuk menyimpan input dari lingkaran maupun bujursangkar
public:
    bidangDatar() {                                     // constructor
        x = 0; 
    }

    virtual void input() {}                             // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x

    virtual float Luas(int a) { return 0; }             // fungsi untuk menghitung luas

    virtual float Keliling(int a) { return 0; }         // fungsi untuk menghitung keliling

    void setX(int a) {                                  // fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }

    int getX() {                                        // fungsi untuk membaca atau mengambil nilai dalam x
        return x;
    }
};

class Bujursangkar : public bidangDatar {   /*membuat class bujur sangkar dengan polymorphi*/
public:
    void input() {
        int sisi;
        cout << "\nMasukkan Panjang Sisi Bujur Sangkar :";
        cin >> sisi;
        setX(sisi);
    }

    float Luas(int sisi) {
        return sisi * sisi;
    }

    float Keliling(int sisi) {
        return 4 * sisi;
    }
};

class Lingkaran : public bidangDatar {  /*membuat class lingkaran dengan polymorphi*/
public:
    void input() {
        int jejari;
        cout << "\nMasukkan jari-jari lingkaran: ";
        cin >> jejari;
        setX(jejari);
    }

    float Luas(int jejari) {
        return 3.14 * jejari * jejari;
    }

    float Keliling(int jejari) {
        return 2 * 3.14 * jejari;
    }
};

int main() {
    bidangDatar* bitar;
    Lingkaran lingkaran;
    Bujursangkar bujur;

    int outin;
    cout << "Pilih Jenis Bangun Datar : " << endl;
    cout << "1. Bujur Sangkar " << endl;
    cout << "2. Lingkaran " << endl;
    cout << "\nMasukkan pilihan ( 1/2 ) : ";
    cin >> outin;

    switch (outin)
    {
    case 1:
        bitar = &bujur;
        bitar->input();

        cout << "\n====================================================\n";
        cout << "Luas Dari Bujur Sangkar Adalah : " << bitar->Luas(bitar->getX()) << endl;
        cout << "Keliling Dari Bujur Sangkar Adalah : " << bitar->Keliling(bitar->getX()) << endl;
        cout << "========================================================";


        break;

    case 2:
        bitar = &lingkaran;
        bitar->input();

        cout << "\n====================================================\n";
        cout << "Luas Dari lingkaran Adalah : " << bitar->Luas(bitar->getX()) << endl;
        cout << "Keliling Dari lingkaran Adalah: " << bitar->Keliling(bitar->getX()) << endl;
        cout << "========================================================";

        break;

    default:
        cout << "Pilihan Salah !!";
        break;
    }

    return 0;
};