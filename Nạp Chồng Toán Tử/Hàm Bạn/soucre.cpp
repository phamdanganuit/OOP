#include<iostream>
#include<fstream>
#include
using namespace std;

class Fraction
{
    int numerator;
    int denominator;
    public:
    friend istream &operator>>(istream &input, Fraction &f) ;
    friend ostream &operator<<(ostream &input, Fraction f) ;
    friend Fraction operator+(int a, Fraction h);
    Fraction(){
        numerator=0;
        denominator=1;
    }
    Fraction(int n,int d){
        numerator=n;
        denominator=d;
    }

    void operator-()
    {
        this->numerator=-numerator; 
    }
    Fraction operator+(Fraction other){
        Fraction tmp;
        tmp.numerator=this->denominator*other.numerator+this->numerator*other.denominator;
        tmp.denominator=this->denominator*other.denominator;
        return tmp;
    }
    Fraction operator+(int a)
    {
        Fraction tmp;
        tmp.numerator=this->numerator+a*this->denominator;
        tmp.denominator=this->denominator;
        return tmp;
    }


};
istream &operator>>(istream &input, Fraction &f)
{
    input>>f.numerator>>f.denominator;
    return input;
}
ostream &operator<<(ostream &input, Fraction f)
{
    input<<f.numerator<<"/"<<f.denominator;
    return input;
}
Fraction operator+(int a, Fraction h){
    Fraction tmp;
    tmp.numerator=a*h.denominator+h.numerator;
    tmp.denominator=h.denominator;
    return tmp;
}
int main()
{
    Fraction A(1,2), B(1,3);
    Fraction C=A+B;
    cout<<C<<endl;
    Fraction D=A+1;
    cout<<D<<endl;
    Fraction E=1+A;
    cout<<E<<endl;
    return 0;
}