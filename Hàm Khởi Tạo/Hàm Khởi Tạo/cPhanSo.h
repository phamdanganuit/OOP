#include<iostream>
using namespace std;
class cPhanSo

{
private:
	int TuSo, MauSo;
public:
	//constructor mac dinh
	cPhanSo() {
		this->MauSo = 1;

		this->TuSo = 0;
	}
	cPhanSo(int tu, int mau) {
		this->TuSo = tu;
		this->MauSo = mau;
	}
		//constructor co tham so truyen vao
	cPhanSo(int tu) {
		this->TuSo = tu;
		this->MauSo = 1;
	}
};

