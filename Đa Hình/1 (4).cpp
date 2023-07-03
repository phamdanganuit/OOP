#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SV {
protected:
    string Ten, MSSV, DiaChi;
    float DiemTb;
    int SoTC;

public:
    SV() {
        // Khởi tạo các thuộc tính mặc định của SV
        Ten = "";
        MSSV = "";
        DiaChi = "";
        DiemTb = 0.0f;
        SoTC = 0;
    }
    SV(string Ten, string MSSV, string DiaChi, float DiemTb, int SoTC) {
        // Khởi tạo các thuộc tính với giá trị truyền vào
        this->Ten = Ten;
        this->MSSV = MSSV;
        this->DiaChi = DiaChi;
        this->DiemTb = DiemTb;
        this->SoTC = SoTC;
    }
    virtual void Nhap() {
        cout << "\nNhap Ten: ";
        getline(cin, Ten);
        cout << "Nhap MSSV: ";
        getline(cin, MSSV);
        cout << "Nhap Dia Chi: ";
        getline(cin, DiaChi);
        cout << "Nhap Diem TB: ";
        cin >> DiemTb;
        cout << "Nhap So TC: ";
        cin >> SoTC;
    }
    virtual void Xuat() {
        cout << "\n Ten: " << Ten;
        cout << "\n MSSV: " << MSSV;
        cout << "\n Dia Chi: " << DiaChi;
        cout << "\n Diem TB: " << DiemTb;
        cout << "\n So TC: " << SoTC;
    }
    virtual bool XetTN() {
        return false; // Default implementation, override in derived classes
    }
    virtual float GetDiem() {
        return DiemTb;
    }
};

class SVDH : public SV {
private:
    string LV;
    float DLV;

public:
    SVDH() : SV() {
        // Khởi tạo các thuộc tính mặc định của SVDH
        LV = "";
        DLV = 0.0f;
    }
    SVDH(string Ten, string MSSV, string DiaChi, float DiemTb, int SoTC, string LV, float DLV)
        : SV(Ten, MSSV, DiaChi, DiemTb, SoTC) {
        // Khởi tạo các thuộc tính với giá trị truyền vào
        this->LV = LV;
        this->DLV = DLV;
    }
    void Nhap() {
        SV::Nhap();
        cout << "Nhap Ten Luan Van: ";
        getline(cin, LV);
        cout << "Nhap Diem Luan Van: ";
        cin >> DLV;
    }
    void Xuat() {
        SV::Xuat();
        cout << "\nTen Luan Van: " << LV;
        cout << "\nDiem Luan Van: " << DLV;
    }
    bool XetTN() {
        if (SoTC >= 150 && DiemTb >= 5 && DLV >= 5)
            return true;
        return false;
    }
};

class SVCD : public SV {
private:
    float TN;

public:
    SVCD() : SV() {
        TN = 0;
    }
    SVCD(string Ten, string MSSV, string DiaChi, float DiemTb, int SoTC, float TN)
        : SV(Ten, MSSV, DiaChi, DiemTb, SoTC) {
        this->TN = TN;
    }
    void Nhap() {
        SV::Nhap();
        cout << "\nNhap diem TN: ";
        cin >> TN;
    }
    void Xuat() {
        SV::Xuat();
        cout << "\nDiem TN: " << TN;
    }
    bool XetTN() {
        if (SoTC >= 120 && DiemTb >= 5 && TN >= 5)
            return true;
        return false;
    }
    float GetDiem() {
        return 0;
    }
};

class ListSV {
private:
    int n;
    vector<SV*> s;

public:
    void Nhap() {
        cout << "\nNhap So Luong SV: ";
        cin >> n;
        s.resize(n); // Resize the vector to accommodate 'n' student objects

        for (int i = 0; i < n; i++) {
            int loai;
            cout << "\nSinh Vien CD(1) or DH(2): ";
            cin >> loai;
            cin.ignore(); // Ignore the remaining newline character from previous input

            if (loai == 1) {
                s[i] = new SVCD;
                s[i]->Nhap();
            }
            else if (loai == 2) {
                s[i] = new SVDH;
                s[i]->Nhap();
            }
        }
    }

    void Xuat() {
        for (int i = 0; i < n; i++) {
            s[i]->Xuat();
        }
    }

    void XetTN() {
        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (s[i]->XetTN())
                dem++;
        }
        cout << "\nSo Luong SV duoc TN la " << dem;
    }

    SV* TimMax();
};

int main() {
    ListSV s;
    s.Nhap();
    s.Xuat();
    s.XetTN();
    s.Max();
    return 0;
}
