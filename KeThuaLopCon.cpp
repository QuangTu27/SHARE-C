#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class nguoi{
	protected:
		char maso[50];
		char hoten[50];	
	public:
		void nhap(){
			//Dinh nghia trong lop:
			cout << "Nhap ma so: ";
			cin.ignore();
			cin.getline(maso, sizeof(maso));
			
			cout << "Nhap ho ten: ";
			cin.ignore(0);
			cin.getline(hoten, sizeof(hoten));
		}
		void xuat(){
			//Dinh nghia xuat
			cout << "Ma so la: " << maso << endl;
			cout << "Ho ten la: " << hoten;
		}
};
class nhanVien: public nguoi{
	private:
		float hsl, pc, luong;	
	public:
		void nhapnv(){
			nguoi::	nhap();
			cout << "Nhap he so luong: ";
			cin >> hsl;
			cout << "Nhap phu cap: ";
			cin >> pc;
		}
		void xuatnv(){
			nguoi::xuat();
			cout << endl;
//			cout << setioflags(ios::showpoint) << setprecision(2);
			cout << "He so luong = " << hsl << endl;
			cout << "Phu cap = " << pc << endl;
 		}
};
int main(){
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	nhanVien *nv = new nhanVien[n + 1];
	for(int i = 1; i <=n; i++){
		cout << "+----------------------------------------+" << endl;
		cout << "Nhap thong tin nhan vien thu " << i << " la : " << endl;
		nv[i].nhapnv();
		cout << endl << ">>Thong tin nhan vien thu " << i << "<<" << endl;
		nv[i].xuatnv();	
	}
delete nv;
return 0;
}








