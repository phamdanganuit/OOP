#include <iostream>
#include <string>
#include <vector>
#define M 100
#define N 100
using namespace std;

class SVList;
class SinhVienCaoDang
{
    friend class SVList;

private:
    string MSSV;
    string Name;
    string DiaChi;
    int TongSoTC;
    float DiemTb;
    float DiemTn;

public:
    static int Dem;
    SinhVienCaoDang(string MSSV, string Name, string DiaChi, int TongSoTC, float DiemTb, float DiemTn);

    SinhVienCaoDang(); // constructor mac dinh

    void Nhap();

    void Xuat();

    bool KiemTraTn();
};
class SinhVienDaiHoc
{

private:
    friend void checkMax(SinhVienDaiHoc a[], int n);
    string MSSV;
    string Name;
    string DiaChi;
    int TongTC;
    float DiemTb;
    string TenLuanVan;
    float DiemLuanVan;

public:
    SinhVienDaiHoc();
    SinhVienDaiHoc(string MSSV, string Name, string DiaChi, int TongTC, float DiemTb, string TenLuanVan, float DiemLuanVan);
    void Nhap();
    void Xuat();
    bool CheckTn();
};
void SinhVienDaiHoc::Nhap()
{   
    cout << "\nMa sinh vien: ";
    fflush(stdin);
    getline(cin, MSSV);
    cout << "\nHo ten: ";
    fflush(stdin);
    getline(cin, Name);
    cout << "\nDia chi: ";
    fflush(stdin);
    getline(cin, DiaChi);
    cout << "\nSo tin chi: ";
    cin >> TongTC;
    cout << "\nDiem trung binh: ";
    cin >> DiemTb;
    cout << "Ten luan van: ";
    fflush(stdin);
    getline(cin, TenLuanVan);
    cout << "\nDiem luan van: ";
    cin >> DiemLuanVan;
}
void SinhVienDaiHoc::Xuat()
{
    cout << "\nMa sinh vien: " << MSSV;
    cout << "\nHo ten: " << Name;
    cout << "\nDia chi: " << DiaChi;
    cout << "\nSo tin chi: " << TongTC;
    cout << "\nDiem trung binh: " << DiemTb;
    cout << "\nTen luan van: " << TenLuanVan;
    cout << "\nDiem luan van: " << DiemLuanVan;
}
bool SinhVienDaiHoc::CheckTn()
{
    if (TongTC >= 150 && DiemTb >= 5 && DiemLuanVan >= 5)
        return 1;
    else
        return 0;
}
SinhVienDaiHoc::SinhVienDaiHoc()
{
    MSSV = "0";
    Name = "0";
    DiaChi = "0";
    TongTC = 0;
    DiemLuanVan = 0;
    DiemTb = 0;
    TenLuanVan = "0";
}
SinhVienDaiHoc::SinhVienDaiHoc(string MSSV, string Name, string DiaChi, int TongTC, float DiemTb, string TenLuanVan, float DiemLuanVan)
{
    this->MSSV = MSSV;
    this->Name = Name;
    this->DiaChi = DiaChi;
    this->TongTC = TongTC;
    this->DiemLuanVan = DiemLuanVan;
    this->DiemTb = DiemTb;
    this->TenLuanVan = TenLuanVan;
}
void checkMax(SinhVienDaiHoc s[], int n)

{
    float max = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].DiemTb > max)
        {
            count++;
            max = s[i].DiemTb;
        }
    }
    cout << "\n Sinh Vien Dai Hoc Co Diem TB Cao Nhat La \n";
    s[count].Xuat();
}
void SinhVienCaoDang::Nhap()
{
    cout << "\nMa sinh vien: ";
    fflush(stdin);
    getline(cin, MSSV);
    cout << "\nHo ten: ";
    fflush(stdin);
    getline(cin, Name);
    cout << "\nDia chi: ";
    fflush(stdin);
    getline(cin, DiaChi);
    cout << "\nSo tin chi: ";
    cin >> TongSoTC;
    cout << "\nDiem trung binh: ";
    cin >> DiemTb;
    cout << "\nDiem tot nghiep: ";
    cin >> DiemTn;
}
void SinhVienCaoDang::Xuat()
{
    cout << "\nMa sinh vien: " << MSSV;
    cout << "\nHo ten: " << Name;
    cout << "\nDia chi: " << DiaChi;
    cout << "\nSo tin chi: " << TongSoTC;
    cout << "\nDiem trung binh: " << DiemTb;
    cout << "\n Diem Tot Nghiep: " << DiemTn;
}
bool SinhVienCaoDang::KiemTraTn()
{
    if (TongSoTC >= 120 && DiemTb >= 5 && DiemTn >= 5)
        return 1;
    else
        return 0;
}
SinhVienCaoDang::SinhVienCaoDang(string MSSV, string Name, string DiaChi, int TongSoTC, float DiemTb, float DiemTn)

{
    this->MSSV = MSSV;
    this->Name = Name;
    this->DiaChi = DiaChi;
    this->TongSoTC = TongSoTC;
    this->DiemTb = DiemTb;
    this->DiemTn = DiemTn;
}
SinhVienCaoDang::SinhVienCaoDang()
{
    MSSV = "/0";
    Name = "/0";
    DiaChi = "/0";
    TongSoTC = 0;
    DiemTb = 0;
    DiemTn = 0;
}
int main()
{

    int t = 0, m = 0, n = 0;
    SinhVienCaoDang svcd[M];
    SinhVienDaiHoc svdh[N];
    cout << "\nNhap so luong sinh vien: ";
    cin >> t;
    do
    {
        cout << "\n Nhap so luong sinh vien dai hoc: ";
        cin >> m;
    } while (m > t);
    n = t - m;
    if (m > 0 && n > 0)
    {
        cout << "\nNhap Thong Tin Sinh Vien Dai Hoc\n";
        for (int i = 0; i < m; i++)
        {
            cout << "\nSinh Vien Dai hoc Thu " << i << endl;
            svdh[i].Nhap();
            cout << "\n--------------------------------------";
        }
        for (int i = 0; i < n; i++)
        {
            cout << "\nSV Cao Dang thu " << i << endl;
            svcd[i].Nhap();
            cout << "\n---------------------------------------";
        }
    }
    if (m > 0 && n == 0)
    {

        cout << "\nNhap Thong Tin Sinh Vien Dai Hoc\n";
        for (int i = 0; i < m; i++)
        {
            cout << "\nSinh Vien Dai hoc Thu " << i << endl;
            svdh[i].Nhap();
            cout << "\n--------------------------------------";
        }
    }
    if (m == 0 && n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\nSV Cao Dang thu " << i << endl;
            svcd[i].Nhap();
            cout << "\n---------------------------------------";
        }
    }
    int dem=0;
    for (int i=0;i<m;i++)
    {
        if (svdh[i].CheckTn()==1)
            dem++;
    }
    for (int i=0;i<n;i++)
    {
        if (svcd[i].KiemTraTn()==1)
            dem++;
    }
    cout <<" \nSo Sinh Vien Tot Nghiep La: "<< dem;
}
