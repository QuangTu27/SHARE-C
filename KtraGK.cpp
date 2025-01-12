#include<iostream>

using namespace std;
class Nguoi{
	protected:
		char hoten[50];
		int namSinh;
		int tuoi;
	public:
		void nhapNG(){
			cout << "Nhap ho ten: ";
			cin.ignore();
			cin.getline(hoten, sizeof(hoten));
			
			cout << "Nhap nam sinh: ";
			cin >> namSinh;		
			tuoi = 2024 - namSinh;
		}
		void xuatNG(){
			cout << "Ho ten: " << hoten << endl;
			cout << "Nam sinh: " << namSinh << endl;
			cout << "tuoi: " << tuoi << endl;	
		}
};
class GiangVien: public Nguoi{
	private:
		int namCongTac;
		int soMonDay;
	public:
		void nhapGV(){
			Nguoi::nhapNG();
			cout << "Nhap so nam cong tac: ";
			cin >> namCongTac;
			
			cout << "Nhap so mon giang day: ";
			cin >> soMonDay;
		}		
		void xuatGV(){			
			cout << "+-----------XUAT-----------+" << endl;
			Nguoi::xuatNG();
			cout << "So nam cong tac: " << namCongTac << endl;
			cout << "So mon giang day:  " << soMonDay << endl;
		}		
		void xuatDK(){
			if(namCongTac > 20 && tuoi > 50){
				cout << "+--------------------------+" << endl;
				Nguoi::xuatNG();
				cout << "So nam cong tac: " << namCongTac << endl;
				cout << "So mon giang day:  " << soMonDay << endl;			
			}			
		}
};
int main(){
	int n;
	GiangVien *gv;
	gv = new GiangVien[n + 1];
	
	cout << "Nhap so luong giang vien: ";
	cin >> n;
	for(int i = 1; i <= n; i++){
		cout << "+-------------------------------+" << endl;
		cout << "Nhap thong tin giang vien thu " << i << endl;
		gv[i].nhapGV();
	}
	
	cout << "[Danh sach giang vien co: Nam cong tac > 20 va Tuoi > 50]" << endl;
	for(int i = 1; i <= n; i++){
		gv[i].xuatDK();
	}		
	delete[] gv; //giai phong bo nho dong (them [] thay vi: delete gv;)
	return 0;
}


