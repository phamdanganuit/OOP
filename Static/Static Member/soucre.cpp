#include<iostream>

using namespace std;
class cPhanso
{
private:
    int tu, mau;
    static int dem;

public:
    cPhanso(int tu = 0, int mau = 0)
    {
        this->tu = tu;
        this->mau = mau;
        dem++;
    }
    void Xuat()
    {
        cout << dem;
    }
    ~cPhanso(){

    }
};
int cPhanso::dem=10
;
int main()
{
    cPhanso p(1,2),p2(1,4);
    p.Xuat();
}