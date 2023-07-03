#include<iostream>

using namespace std;

class DongVat
{
    protected:
        int tuoi,cannang,chieucao;
    public:
        void An()
        {
            cout<<"Dang An";
        }
        void Uong()
        {
            cout<<"Dang Uong";
        }

};

class ConBao:public DongVat
{
    public:
        void DiSan()
        {
            cout<<"Di San";
        }
    void Nhap();

};
void ConBao::Nhap()
{
    cin>>tuoi;
    cin>>chieucao;
    cin>>cannang;
}
int main()
{
    DongVat A;
    ConBao B;
    
    B.An();
}