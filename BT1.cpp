/*
BT1: Viet chuong trình thuc hien các yêu cau sau:
-Nhap du lieu cho các sinh vien (dùng cau trúc danh sách liên ket don)
Thông tin cua sinh viên bao gom: mã sinh viên, ho ten, lop, diem trung bình
- Chuong trình có su dung toán tu new và delete
-In ra danh sách sinh viên sap xep theo diem trung bình
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








