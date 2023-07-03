#include <iostream>
#include<string>
using namespace std;
class Date
{
private:
    int ngay, thang, nam;

public:
    Date(int n, int t, int na) : ngay(n), thang(t), nam(na) {}
    void PrintDate()
    {
        cout << ngay << "/ " << thang << "/ " << nam << endl;
    }
};
class Time
{
private:
    int gio, phut, giay;

public:
    Time(int h, int m, int s) : gio(h), phut(m), giay(s)
    {
    }
    void PrintTime()
    {
        cout << gio << " gio " << phut << " phut " << giay<<" giay\n";
    }
};
class Event{
    private:
    string TenSukien;
    Time time;
    Date date;
    public:
    Event(string ten,int ngay,int thang,int nam,int gio,int phut,int giay): TenSukien(ten),time(gio,phut,giay),date(ngay,thang,nam){}
    void printEvent(){
        cout<<"Ten su kien : "<<TenSukien<<endl;
        cout<<"Thoi gian: ";
        time.PrintTime();
        cout<<"Ngay: ";
        date.PrintDate();
    }
};
int main()
{
    Event s1("Sinh nhat",4,9,2023,12,36,24);
    s1.printEvent();
}