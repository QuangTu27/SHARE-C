#include<iostream>

using namespace std;

class PS{
	private:
		int tu, mau;
		
	public:
		//dung get neu khong truy nhap dc vao thuoc tinh
		int gettu(){
			return tu;
		}
		int getmau(){
			return mau;
		}
		
		PS(){
			tu = 0;
			mau = 1;
		}
		PS(int tu, int mau){
			tu = tu;
			mau = mau;
		}
		~PS(){
		};
		
		friend istream &operator >> (istream &nhap, PS &p);
		friend ostream &operator << (ostream &xuat, PS &p);
};

istream &operator >> (istream &nhap, PS &p){
	cout << "Nhap tu so: ";
	nhap >> p.tu;
	do {
        cout << "Nhap mau: ";
        nhap >> p.mau;
        if (p.mau == 0) cout << "Mau so khong duoc bang 0. Vui long nhap lai!" << endl;
    } while (p.mau == 0);
    return nhap;
}

ostream &operator << (ostream &xuat, PS &p){
	cout << "=> PS = ";
	xuat << p.tu << "/" << p.mau;
	return xuat;
}

int main(){
	PS p;
	cout << "[NHAP]" << endl;
	cin >> p;
	
	cout << "[XUAT]" << endl;
	cout << p;
	return 0;
}









