#include <iostream>
using namespace std;
class PhanSo
{
private:
    int tu, mau;

public:
    PhanSo(){

    }
    ~PhanSo(){

    }
    PhanSo(int tu,int mau){
        this->tu=tu;
        this->mau=mau;
    }
    PhanSo(const PhanSo &n){
        tu=n.tu;
        mau=n.mau;
    }
    void Xuat(){
        cout << tu<<" "<<mau;
    }
};
int main(){
    PhanSo ps1(1,0);
    PhanSo ps2(ps1);
    ps2.Xuat();
}