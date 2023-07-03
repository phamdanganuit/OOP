#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

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
        ID = "";
        Title = "";
        Price = 0;
        AuthorName = "";
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
        cout << "Nhap Ma San Pham: ";
        cin.ignore();
        getline(cin, ID);
        cout << "Nhap Tieu De: ";
        getline(cin, Title);
        cout << "Nhap Gia: ";
        cin >> Price;
        cout << "Nhap ten tac gia: ";
        cin.ignore();
        getline(cin, AuthorName);
    }

    virtual void Xuat()
    {
        cout << "Ma San Pham: " << ID << endl;
        cout << "Tieu De: " << Title << endl;
        cout << "Gia: " << Price << endl;
        cout << "Ten Tac Gia: " << AuthorName << endl;
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
        Unit = "";
    }

    cCD(string ID, string Title, float Price, string AuthorName, string Unit)
        : cProduct(ID, Title, Price, AuthorName)
    {
        this->Unit = Unit;
    }

    void Nhap()
    {
        cProduct::Nhap();
        cout << "Nhap ten don vi san xuat: ";
        getline(cin, Unit);
    }

    void Xuat()
    {
        cProduct::Xuat();
        cout << "Ten don vi san xuat: " << Unit << endl;
    }
};

class cPicture : public cProduct
{
private:
    float width;
    float height;

public:
    cPicture() : cProduct()
    {
        width = 0;
        height = 0;
    }

    cPicture(string ID, string Title, float Price, string AuthorName, float width, float height)
        : cProduct(ID, Title, Price, AuthorName)
    {
        this->width = width;
        this->height = height;
    }

    void Nhap()
    {
        cProduct::Nhap();
        cout << "Nhap Chieu Cao: ";
        cin >> height;
        cout << "Nhap Chieu Rong: ";
        cin >> width;
    }

    void Xuat()
    {
        cProduct::Xuat();
        cout << "Chieu Cao: " << height << endl;
        cout << "Chieu Rong: " << width << endl;
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
        IDGod = "";
        NameGod = "";
        PhoneNumber = "";
    }
    string GetIDGod()
    {
        return IDGod;
    }

    cGod(string IDGod, string NameGod, string PhoneNumber)
    {
        this->IDGod = IDGod;
        this->NameGod = NameGod;
        this->PhoneNumber = PhoneNumber;
    }

    void Nhap()
    {
        cout << "Nhap Ma Khach Hang: ";
        cin.ignore();
        getline(cin, IDGod);
        cout << "Nhap Ten Khach Hang: ";
        getline(cin, NameGod);
        cout << "Nhap SDT: ";
        getline(cin, PhoneNumber);
    }

    void Xuat()
    {
        cout << "Ten khach hang: " << NameGod << endl;
        cout << "Ma khach hang: " << IDGod << endl;
        cout << "SDT: " << PhoneNumber << endl;
    }

    friend istream &operator>>(istream &input, cGod &s);
};

istream &operator>>(istream &input, cGod &s)
{
    cout << "Nhap Ten Khach Hang cua Bill: ";
    cin.ignore();
    getline(input, s.NameGod);
    cout << "Nhap ID khach hang trong Bill: ";
    getline(input, s.IDGod);
    cout << "Nhap SDT khach hang trong Bill: ";
    getline(input, s.PhoneNumber);
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
        IDBill = "";
        Date = "";
        God = cGod();
    }
    cGod GetGod()
    {
        return God;
    }
    cBill(vector<cProduct *> List, string IDBill, string Date, cGod God)
    {
        this->List = List;
        this->IDBill = IDBill;
        this->Date = Date;
        this->God = God;
    }

    void Nhap()
    {
        int n;
        cout << "Nhap so luong san pham: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int lc;
            cout << "Nhap loai san pham CD(1) Tranh(2): ";
            cin >> lc;
            if (lc == 1)
            {
                cCD *s = new cCD();
                s->Nhap();
                List.push_back(s);
            }
            else if (lc == 2)
            {
                cPicture *s = new cPicture();
                s->Nhap();
                List.push_back(s);
            }
        }

        cin.ignore();
        cout << "Nhap Ma Hoa Don: ";
        getline(cin, IDBill);
        cout << "Nhap Khach Hang: ";
        cin >> God;
        cin.ignore();
        cout << "Nhap Ngay: ";
        getline(cin, Date);
    }

    void Xuat()
    {
        cout << "Ma hoa don: " << IDBill << endl;
        cout << "Ngay: " << Date << endl;
        cout << "Thong Tin Khach Hang:" << endl;
        God.Xuat();
        cout << "So san pham da mua:" << endl;
        for (cProduct *product : List)
        {
            product->Xuat();
        }
    }

    float Sum()
    {
        float total = 0;
        for (cProduct *product : List)
        {
            total += product->GetPrice();
        }
        return total;
    }
};

class listBill
{
private:
    vector<cBill> L;

public:
    void Nhap()
    {
        int k;
        cout << "Nhap so luong bill: ";
        cin >> k;

        for (int i = 0; i < k; i++)
        {
            cBill h;
            h.Nhap();
            L.push_back(h);
        }
    }

    void Xuat()
    {
        for (cBill &bill : L)
        {
            bill.Xuat();
        }
    }

    void SumBill()
    {
        float total = 0;
        for (cBill &bill : L)
        {
            total += bill.Sum();
        }
        cout << "Tong Doanh Thu: " << total << endl;
    }
    void FindTopCustomers()
    {
        vector<pair<string, float>> customerTotal;

        for (cBill &bill : L)
        {
            float total = bill.Sum();
            customerTotal.push_back(make_pair(bill.GetGod().GetIDGod(), total));
        }

        sort(customerTotal.begin(), customerTotal.end(), [](const pair<string, float> &a, const pair<string, float> &b)
             { return a.second > b.second; });

        float maxTotal = customerTotal[0].second;

        cout << "Khach hang mua nhieu nhat:" << endl;
        for (const pair<string, float> &customer : customerTotal)
        {
            if (customer.second == maxTotal)
            {
                cout << "Ma khach hang: " << customer.first << endl;
                cout << "Tong gia tri hoa don: " << customer.second << endl;
            }
        }
    }
};

int main()
{
    listBill lb;
    lb.Nhap();
    cout << "--------------------------------------------------" << endl;
    lb.Xuat();
    cout << "--------------------------------------------------" << endl;
    lb.SumBill();
    cout << "--------------------------------------------------" << endl;
    lb.FindTopCustomers();

    return 0;
}