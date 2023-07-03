#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;
class cProduct
{
protected:
    string ID;
    string Title;
    float Price;
    string AuthorName;

public:
    cProduct()
    {
        ID = " ";
        Title = " ";
        Price = 0;
        AuthorName = " ";
    }
    cProduct(string ID, string Title, float Price, string AuthorName)
    {
        this->ID = ID;
        this->Title = Title;
        this->Price = Price;
        this->AuthorName = AuthorName;
    }
    virtual void Nhap()
    {
        cout << "\n Nhap Ma San Pham: ";
        cin >> ID;
        cout << "\n Nhap Tieu De ";
        cin >> Title;
        cout << "\n Nhap Gia ";
        cin >> Price;
        cout << "\n Nhap ten tac gia ";
        cin >> AuthorName;
    }
    virtual void Xuat()
    {
        cout << "\n Ma San Pham " << ID;
        cout << "\n Tieu De " << Title;
        cout << "\n Gia " << Price;
        cout << "\n Ten Tac Gia " << AuthorName;
    }
    virtual float GetPrice()
    {
        return Price;
    }
};
class cCD : public cProduct
{
private:
    string Unit;

public:
    cCD() : cProduct()
    {
        Unit = " ";
    }
    cCD(string ID, string Title, float Price, string AuthorName, string Unit) : cProduct(ID, Title, Price, AuthorName)
    {
        this->Unit = Unit;
    }
    void Nhap()
    {
        cProduct::Nhap();
        cout << "\n Nhap ten don vi san xuat: ";
        cin >> Unit;
    }
    void Xuat()
    {
        cProduct::Xuat();
        cout << "\n Ten don vi san xuat: " << Unit;
    }
};
class cPicture : public cProduct
{
private:
    float width;
    float hight;

public:
    cPicture() : cProduct()
    {
        width = 0;
        hight = 0;
    }
    cPicture(string ID, string Title, float Price, string AuthorName, float width, float hight) : cProduct(ID, Title, Price, AuthorName)
    {
        this->width = width;
        this->hight = hight;
    }
    void Nhap()
    {
        cProduct::Nhap();
        cout << "\n Nhap Chieu Cao ";
        cin >> hight;
        cout << "\n Nhap Chieu Rong ";
        cin >> width;
    }
    void Xuat()
    {
        cProduct::Xuat();
        cout << "\n Chieu Dai " << hight;
        cout << "\n Chieu Rong " << width;
    }
};
class cGod
{
private:
    string IDGod;
    string NameGod;
    string PhoneNumber;

public:
    cGod()
    {
        IDGod = " ";
        NameGod = " ";
        PhoneNumber = " ";
    }
    cGod(string IDGod, string NameGod, string PhoneNumber)
    {
        this->IDGod = IDGod;
        this->NameGod = NameGod;
        this->PhoneNumber = PhoneNumber;
    }
    void Nhap()
    {
        cout << "\n Nhap Ma Khach Hang ";
        cin >> IDGod;
        cout << "\n Nhap Ten Khach Hang ";
        cin >> NameGod;
        cout << "\n Nhap SDT ";
        cin >> PhoneNumber;
    }
    void Xuat()
    {
        cout << "\n Ten khach hang " << IDGod;
        cout << "\n Ma khach hang " << NameGod;
        cout << "\n SDT " << PhoneNumber;
    }
    friend istream &operator>>(istream &input, cGod &s);
};
istream &operator>>(istream &input, cGod &s)
{   cin.ignore();
    cout << "\n Ma Khach Hang ";
    getline(input, s.IDGod);
    cin.ignore();
    cout << "\n Ten ";
    getline(cin, s.NameGod);
    cin.ignore();
    cout << "\n Nhap SDT ";
    getline(cin, s.PhoneNumber);
    return input;
}

class cBill
{
private:
    vector<cProduct *> List;
    string IDBill;
    string Date;
    cGod God;

public:
    cBill()
    {
        List = {0};
        IDBill = " ";
        Date = " ";
        God = cGod();
    }
    cBill(vector<cProduct *> List, string IDBill, string Date, cGod God)
    {
        this->List = List;
        this->IDBill = IDBill;
        this->Date = Date;
        this->God = God;
    }
    void Nhap(int &n)
    {
        cout << "\n Nhap So San Pham ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int lc;
            cout << "\n Nhap loai san pham CD(1) Tranh(2) ";
            cin >> lc;
            if (lc == 1)
            {
                cCD *s = new cCD();
                s->Nhap();
                List.push_back(s);
            }
            if (lc == 2)
            {
                cPicture *s = new cPicture();
                s->Nhap();
                List.push_back(s);
            }
        }

        cout << "\n Nhap Ma Hoa Don ";
        cin >> IDBill;
        cout << "\n Nhap Khach Hang ";
        cin >> God;
        cout << "\n Nhap Ngay ";
        cin >> Date;
    }
    void Xuat(int n)
    {
        cout << "\n Ma hoa don " << IDBill;
        cout << "\n Ngay " << Date;
        cout << "\n Thong Tin Khach Hang \n";
        God.Xuat();
        cout << "\n So san pham da mua \n";
        for (int i = 0; i < n; i++)
        {
            List[i]->Xuat();
        }
    }
    float Sum(int n)
    {
        float S = 0;
        for (int i = 0; i < n; i++)
        {
            S = List[i]->GetPrice() + S;
        }
        return S;
    }
};
class listBill
{
private:
    vector<cBill> L;

public:
    void Nhap(int k)
    {
        for (int i = 0; i < k; i++)
        {
            cBill h;
            h.Nhap(n);
            L.push_back(h);
        }
    }
    void Xuat(int k)
    {
        for (int i = 0; i < n; i++)
        {
            L[i].Xuat(n);
        }
    }
    void SumBill(int k)
    {
        int S = 0;
        for (int i = 0; i < k; i++)
        {
            S = L[i].Sum(n) + S;
        }
        cout << "\n Tong Doanh Thu " << S;
    }
};
int main()
{
    int k;
    cout << "\n Nhap so luong bill ";
    cin >> k;
    listBill L;
    L.Nhap(k);
    L.Xuat(k);
    L.SumBill(k);
}