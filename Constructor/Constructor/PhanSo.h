#pragma once
#include<iostream>
using namespace std;
class PhanSo
{
private:
	int tu, mau;
public:
	PhanSo(int tu, int mau)
	{
		this->mau = mau;
		this -> tu = tu;
	}
	void OutPut()
	{
		cout << tu;
		cout << endl << mau;
	}
};


