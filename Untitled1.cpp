#include<iostream>
#include<math.h>
using namespace std;

class PS{
	private:
		int tu, mau;
	public:
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
		
		int UCLN(int tu, int mau){
			int temp;
			while(mau != 0){
				temp = mau;
				mau = tu % mau;
				tu = temp;
			}
			return tu;
		}

		void rutGon(){
			int u = UCLN(abs(tu), abs(mau));
			tu = tu / u;
			mau = mau / u;
			if (mau < 0) { 
            	tu = -tu;
            	mau = -mau;
        	}
		}
};

istream &operator >> (istream &nhap, PS &p){
	cout << "Nhap tu so: ";
	cin >> p.tu;
	do{
		cout << "Nhap mau:  ";
		cin >> p.mau;
		if(p.mau == 0){
			cout << "Mau so khong duoc bang 0. Vui long nhap lai!" << endl;
		} 
	}while(p.mau == 0);//mau con = 0 thi con quay lai nhap
	
	p.rutGon();
	return nhap;
}

ostream &operator << (ostream &xuat, PS &p){
	cout << "=>>>Phan so = ";
	if (p.mau == 1) {
        xuat << p.tu; 
    } else {
        xuat << p.tu << "/" << p.mau;
    }
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










