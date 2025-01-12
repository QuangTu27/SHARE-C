//Xay dung lop cho sinh vien
//Thuoc tinh: ho ten, nam sinh, Diem toan, ly, hoa, ÐTB
//Phuong thuc: Nhap, Xuat, Tinh ÐTB

#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class sinhvien {
	//thuoc tinh
	private:
		char ht[50];
		int ns;
		float t, l, h;
		
	//phuong thuc
	public:
		void nhap();
		void xuat();
		float tinhdtb();
};
//dinh nghia cac phuong thuc
void sinhvien:: nhap(){
	cout << "Nhap ho ten sinh vien: ";
	cin.ignore();
	cin.getline(ht, sizeof(ht));
	
	cout << "Nhap diem: " << endl;
	cin >> t >>l >> h;
}
void sinhvien::	xuat(){
	cout << endl << "Ho ten sinh vien la: " << ht << endl;
	cout << "Diem t = " << t << endl;
	cout << "Diem l = " << l << endl;
	cout << "Diem h = " << h << endl;
}
float sinhvien:: tinhdtb(){
	float dtb = (t + l + h) / 3;
	return dtb;
}
int main(){
	//<doi voi 1 sinh vien>
	/* 	
		sinhvien sv;
		sv.nhap();
		sv.xuat();
		cout << "Diem TB cua sv = " << sv.tinhdtb(); 
	*/
	
	//<doi voi n sinh vien>
	int n, i;
	cout <<"Nhap so luong sinh vien: ";
	cin >> n;
	//xin cap phat bo nho
	sinhvien *sv;
	sv = new sinhvien[n + 1];
	for (i = 1; i <= n; i++){
		cout << "Nhap sinh vien so " << i << ":" << endl;
		sv[i].nhap();
		cout << "=> Diem trung binh = " << sv[i].tinhdtb();
		sv[i].xuat();	
	}
	//giai phong bo nho
	delete sv;
}













