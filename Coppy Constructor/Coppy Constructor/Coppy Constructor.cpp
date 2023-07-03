#include<iostream>
#include"ThamChieu.h"
using namespace std;
void ThamTri(int x) {
	x++;
	cout << &x;
}
void ThamChieu(int& x)
{
	//x++;
	
}
int main() {
	int a = 12;
	int& b = a;
	//tham chieu;
	b = 3;
	int x = 1;
	cout << &x << endl;
	ThamTri(x);
	

}