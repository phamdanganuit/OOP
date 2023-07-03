#include <iostream>
#include <string>

using namespace std;

const int M = 1000;

class sinhviencaodang
{
private:
    string msv;
    string hoten;
    string diachi;
    int sotinchi;
    float diemtrungbinh;
    float diemthitotnghiep;
public:
    sinhviencaodang() {
        this-> msv = '\0'; 
        this-> hoten = '\0'; 
        this-> diachi = '\0';
        this->sotinchi = 0;
        this->diemtrungbinh = 0;
        this->diemthitotnghiep = 0;
    }

    sinhviencaodang(string msv, string hoten, string diachi, int sotinchi, float diemtrungbinh, float diemthitotnghiep)
    {
        this->msv = msv;
        this->hoten = hoten;
        this->diachi = diachi;
        this->sotinchi = sotinchi;
        this->diemtrungbinh = diemtrungbinh;
        this->diemthitotnghiep = diemthitotnghiep;
    }


    void nhap() {
        cout << "\nMa sinh vien: ";
        fflush(stdin);
        getline(cin, msv);
        cout << "\nHo ten: ";
        fflush(stdin);
        getline(cin, hoten);
        fflush(stdin);
        cout <<"\nDia chi: ";
        getline(cin, diachi);
        cout << "\nSo tin chi: ";
        cin >> sotinchi;
        cout << "\nDiem trung binh: ";
        cin >> diemtrungbinh;
        cout << "\nDiem thi tot nghiep: ";
        cin >> diemthitotnghiep;
    }

    void xuat() {
        cout << "\nMa sinh vien: " << msv;
        cout << "\nHo ten: " << hoten;
        cout << "\nDia chi: " << diachi;
        cout << "\nSo tin chi: " << sotinchi;
        cout << "\nDiem trung binh: " << diemtrungbinh;
        cout << "\nDiem thi tot nghiep: " << diemthitotnghiep;
    }

    bool totnghiep() {
        if (sotinchi >= 120 && diemtrungbinh >= 5 && diemthitotnghiep >= 5)
            return 1;
        else
            return 0;
    }
};

class sinhviendaihoc
{
private:
    string msv;
    string hoten;
    string diachi;
    int sotinchi;
    float diemtrungbinh;
    string tenluanvan;
    float diemluanvan;
public:
    friend void dtbmax(sinhviendaihoc a[], int n);
    sinhviendaihoc() {
        this-> msv = '\0'; 
        this-> hoten = '\0'; 
        this-> diachi = '\0';
        this->sotinchi = 0;
        this->diemtrungbinh = 0;
        this->tenluanvan = '\0';
        this->diemluanvan = 0;
    }

    sinhviendaihoc(string msv, string hoten, string diachi, int sotinchi, string tenluanvan, float diemluanvan)
    {
        this->msv = msv;
        this->hoten = hoten;
        this->diachi = diachi;
        this->sotinchi = sotinchi;
        this->diemtrungbinh = diemtrungbinh;
        this->tenluanvan = tenluanvan;
        this->diemluanvan = diemluanvan;
    }
    

    void nhap() {
        cout << "\nMa sinh vien: ";
        fflush(stdin);
        getline(cin, msv);
        cout << "\nHo ten: ";
        fflush(stdin);
        getline(cin, hoten);
        cout <<"\nDia chi: ";
        fflush(stdin);
        getline(cin, diachi);
        cout << "\nSo tin chi: ";
        cin >> sotinchi;
        cout << "\nDiem trung binh: ";
        cin >> diemtrungbinh;
        cout << "Ten luan van: ";
        fflush(stdin);
        getline(cin, tenluanvan);
        cout << "\nDiem luan van: ";
        cin >> diemluanvan;
    }

    void xuat() {
        cout << "\nMa sinh vien: " << msv;
        cout << "\nHo ten: " << hoten;
        cout << "\nDia chi: " << diachi;
        cout << "\nSo tin chi: " << sotinchi;
        cout << "\nDiem trung binh: " << diemtrungbinh;
        cout << "\nTen luan van: " << tenluanvan;
        cout << "\nDiem luan van: " << diemluanvan;
    }

    bool totnghiep() {
        if (sotinchi >= 150 && diemtrungbinh >= 5 && diemluanvan >= 5)
            return 1;
        else
            return 0;
    }
};

void nhapsvcd(sinhviencaodang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n\t Thong tin sinh vien thu " << i + 1 << " la: ";
        a[i].nhap();
    }
}

void nhapsvdh(sinhviendaihoc a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n\t Thong tin sinh vien thu " << i + 1 << " la: ";
        a[i].nhap();
    }
}

void xuatsvcd(sinhviencaodang a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].xuat();
        cout << "------------------------";
    }
}

void xuatsvdh(sinhviendaihoc a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i].xuat();
        cout << "------------------------";
    }
}

void dtbmax(sinhviendaihoc a[], int n) {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (a[i].diemtrungbinh > max)
            max = i;
    }
    cout << "Sinh vien dai hoc co diem trung binh cao nhat la: ";
    a[max].xuat();
}

void demsvtotnghiep(sinhviencaodang a[], sinhviendaihoc b[], int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].totnghiep())
            count++;
    }
    for (int i = 0; i < m; i++) {
        if (b[i].totnghiep())
            count++;
    }
    cout << "\nSo sinh vien tot nghiep la: " << count;
}

int main() {
    sinhviencaodang svcd[M];
    sinhviendaihoc svdh[M];
    int n, m;

    cout << "Nhap so sinh vien cao dang: ";
    cin >> n;
    nhapsvcd(svcd, n);

    cout << "Nhap so sinh vien dai hoc: ";
    cin >> m;
    nhapsvdh(svdh, m);

    cout << "\n\t DANH SACH SINH VIEN CAO DANG ";
    xuatsvcd(svcd, n);

    cout << "\n\t DANH SACH SINH VIEN DAI HOC ";
    xuatsvdh(svdh, m);

    demsvtotnghiep(svcd, svdh, n, m);

    dtbmax(svdh, m);
}