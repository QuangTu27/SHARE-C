//Xay dung lop can bo voi:
//attribute: ma can bo, ma don vi, ho ten, nam sinh, phu cap, he so luong, bao hiem
//method: nhap, xuat, tinh luong = he so luong * 1800 + phu cap - bao hiem
//In ket qua ra man hinh cho n can bo (cap phat va giai phong bo nho)

#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class canbo {
	//attribute
	private:
		char mcb[50];
		char mdv[50];
		char ht[50];
		int ns;
		float pc, hsl, bh;
	
	//method
	public:
		void nhap();
		void xuat();
		float luong();
};
//Dinh nghia cac method
void canbo:: 	nhap(){
	cout << "Nhap ma can bo: ";
	cin.ignore();
	cin.getline(mcb, sizeof(mcb));
	
	cout << "Nhap ma don vi: ";
	cin.ignore(0);
	cin.getline(mdv, sizeof(mdv));	
	
	cout << "Nhap Ho ten can bo: ";
	cin.ignore(0);
	cin.getline(ht, sizeof(ht));
	
	cout << "Nhap nam sinh can bo: ";
	cin >> ns;
	cout << "Nhap phu cap cua can bo: ";
	cin >> pc;
	cout << "Nhap he so luong cua can bo: ";
	cin >> hsl;
	cout << "Nhap tien bao hiem cua can bo: ";
	cin >> bh;		
}
void canbo::	xuat(){
	cout << endl << "=> Thong tin cua can bo la: " << endl;
	cout << "Ma can bo: " << mcb << endl;
	cout << "Ma don vi: " << mdv << endl;
	cout << "Ho ten: " << ht << endl;
	cout << "Nam sinh: " << ns << endl;
	cout << "Tien phu cap, he so luong, tien bao hiem: " << pc << "," << hsl << "," << bh << endl;
}
float canbo::	luong(){
	float luong = hsl * 1800 + pc - bh;
	return luong;
}
int main(){
	
	int i, n;
	cout << "NHAP SO LUONG CAN BO: ";
	cin >> n;
//Xin cap phat bo nho
	canbo *cb;
	cb = new canbo[n + 1];
	for(i = 1; i <= n; i++){
		cout << endl << "Thong tin cua can bo " << i << " la: " << endl;
		cb[i].nhap();
		
		cb[i].xuat();
		cout << "Luong cua can bo = " << cb[i].luong();
	}
//giai phong bo nho
	delete cb;

getch();
}








