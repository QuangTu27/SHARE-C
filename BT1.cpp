/*
BT1: Viet chuong tr�nh thuc hien c�c y�u cau sau:
-Nhap du lieu cho c�c sinh vien (d�ng cau tr�c danh s�ch li�n ket don)
Th�ng tin cua sinh vi�n bao gom: m� sinh vi�n, ho ten, lop, diem trung b�nh
- Chuong tr�nh c� su dung to�n tu new v� delete
-In ra danh s�ch sinh vi�n sap xep theo diem trung b�nh
*/

#include<iostream>
#include<conio.h>

using namespace std;
class sinhVien {
	private:
		char msv[50];
		char ht[50];
		char lop[50];
		float diem;
			
	public:
		void nhap();
		void xuat();		
		float dtb();
		
};
void sinhVien::nhap(){
	cout << "Nhap ma sinh vien: ";
	cin.ignore();
	cin.getline(msv, sizeof(msv));

	cout << "Nhap ho ten:";
	cin.ignore(0);
	cin.getline(ht, sizeof(ht));
	
	cout << "Nhap lop: ";
	cin.ignore(0);
	cin.getline(lop, sizeof(lop));
		
	do{	
		cout << "Nhap diem trung binh: ";
		cin >> diem;
		if(diem < 0 || diem > 10){
			cout << "Diem khong hop le. YC nhap lai!! " << endl;
		}	
	} while(diem <= 0 || diem >= 10);
	
}
void sinhVien::	xuat(){
	cout << "Ma sinh vien: " << msv << endl;
	cout << "Ho ten: " << ht <<  endl;
	cout << "Lop: " << lop << endl;
}
float sinhVien:: dtb() {
	float dtb = diem;
	return dtb;	
}
int main(){
	int n;
	sinhVien *sv;
	sv = new sinhVien[n + 1];
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		cout << "Nhap thong tin cua sinh vien thu: " << i << endl;
		sv[i].nhap();	
	}
	delete sv;	
	//sap xep 
	for(int i = 1; i <= n; i++){
		for(int j = i +1; j <=n; j++){
			if(sv[i].dtb() > sv[j].dtb()){
				sinhVien temp = sv[i];
				sv[i] = sv[j];
				sv[j] = temp;
			}
		}
		cout << endl;
		cout << ">>Danh sach sinh vien theo diem tang dan<<" << endl;
		for(i = 1; i <= n; i++){
			cout << "-------------------------------" << endl;
			cout << i << "." << endl;
			sv[i].xuat();
			cout << "Diem trung binh = " << fixed << sv[i].dtb() <<endl;
		}
	}	
return 0;	
}








