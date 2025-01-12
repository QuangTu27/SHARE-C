#include<iostream>
#include<math.h>

using namespace std;
class phanso{
	private:
		int tu;
		int mau;
	public:
		//Ham tao khong tham so
		phanso(){
			tu = 0;
			mau = 1;	
		}
		//Ham tao co tham so
		phanso(int tu, int mau){
			tu = tu;
			mau = mau;
		}
		//Ham huy
		~phanso(){};
		void nhap();
		void xuat();
		int ucln(int tu, int mau);		
		void rutgon();
		//Dinh nghia chong toan tu
		phanso operator +(phanso a);
		phanso operator -(phanso b);
		phanso operator *(phanso c);
		phanso operator /(phanso d);
};

void phanso::nhap(){
	cout << "Nhap tu: ";
	cin >> tu;
//	cout << "Nhap mau: ";
	do{
		cout << "Nhap mau:  ";
		cin >> mau;
	}while(mau == 0);//mau con = 0 thi con quay lai nhap
}

void phanso::xuat(){
	if(mau < 0){
		mau = -mau;
		tu = -tu;
	}
	else if(tu < 0 && mau < 0){
		mau = mau;
		tu = tu;
	}
	else if(mau == 1){
		cout << tu;
	}
	else{
		cout << tu << "/" << mau;
	}
}

// Hàm tìm UCLN
int phanso::ucln(int tu, int mau) {
    while (mau != 0) {
        int temp = mau;
        mau = tu % mau;
        tu = temp;
    }
    return tu;
}

void phanso::rutgon(){
	int u = ucln(tu, mau);
	tu = tu / u;
	mau = mau / u;
}

phanso phanso::operator +(phanso a){
	a.tu = tu * a.mau + mau * a.tu;
	a.mau = mau * a.mau;
	return a;
}

phanso phanso::operator -(phanso b){
	b.tu = tu * b.mau - mau * b.tu;
	b.mau = mau * b.mau;
	return b;
}

phanso phanso::operator *(phanso c){
	c.tu = tu * c.tu;
	c.mau = mau * c.mau;
	return c;
}

phanso phanso::operator /(phanso d){
	d.tu = tu * d.mau;
	d.mau = mau * d.tu;
	return d;
}
int main(){
	phanso ps1, ps2, pscong, pstru, psnhan, pschia;
	cout << "Nhap phan so thu 1:" << endl;
	ps1.nhap();
	ps1.rutgon();
	ps1.xuat();
	
	cout << endl << "Nhap phan so thu 2:" << endl;
	ps2.nhap();
	ps2.rutgon();
	ps2.xuat();
	
	//tinh toan
	cout << endl << "+--- TINH TOAN ---+";
	cout << endl << ">>Tong = ";
	pscong = ps1 + ps2;
	pscong.rutgon();
	pscong.xuat();
	
	cout << endl << ">>Hieu = ";
	pstru = ps1 - ps2;
	pstru.rutgon();
	pstru.xuat();
	
	cout << endl << ">>Tich = ";
	psnhan = ps1 * ps2;
	psnhan.rutgon();
	psnhan.xuat();
	
	cout << endl << ">>Thuong = ";
	pschia = ps1 / ps2;
	pschia.rutgon();
	pschia.xuat();
	
return 0;	
}



