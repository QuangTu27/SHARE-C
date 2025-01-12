#include <iostream>
#include <math.h>
using namespace std;
class sophuc{
	private:
		int thuc;
		int ao;
	public:
		sophuc(){
			thuc = 0;
			ao = 0;
		}
		sophuc(int thuc, int ao){
			thuc = thuc;
			ao = ao;
		}	
		~sophuc(){};		
		void nhap();
		void xuat();
		float module();
		sophuc operator +(sophuc a);
		sophuc operator -(sophuc b);
		sophuc operator *(sophuc c);
};
void sophuc::nhap(){
	cout << "Nhap phan thuc: ";
	cin >> thuc;
	cout << "Nhap phan ao: ";
	cin >> ao;	
}
void sophuc:: xuat(){
	cout << "So phuc = ";
	cout << thuc;
	if(ao > 0){
		cout << "+" << ao << "i" << endl;
	}
	else{
		cout << "-" << abs(ao) << "i" << endl; //abs: doi so am thanh duong
	}	
}
float sophuc::module(){
	float z;
	z = sqrt(thuc * thuc + ao * ao);
	return z;
}
//kieu gia tri tra ve + ten lop:: operator +()
sophuc sophuc::operator +(sophuc a){
	a.thuc = thuc + a.thuc;
	a.ao = ao + a.ao;
	return a;
}

sophuc sophuc::operator -(sophuc b){
	b.thuc = thuc - b.thuc;
	b.ao = ao - b.ao;
	return b;
}

sophuc sophuc::operator *(sophuc c){
	//z1 = a + bi và z2 = c + di
	//z1.z2 = (ac - bd) + (ad + bc)i
	c.thuc = thuc * c.thuc - ao * c.ao;
	c.ao = thuc * c.thuc + ao * c.ao;
	return c;	
}
int  main(){
	sophuc sp1, sp2, spcong, sptru, spnhan;
	cout << "Nhap so phuc thu 1:" << endl;
	sp1.nhap();
	sp1.xuat();
	cout << "=> Module cua so phuc = " << sp1.module() << endl;
	
	cout << "----------------------------------------" << endl;
	cout << "Nhap so phuc thu 2:" << endl;
	sp2.nhap();
	sp2.xuat();
	cout << "=> Module cua so phuc = " << sp2.module() << endl;
	
	cout << "----------------------------------------" << endl;
	cout << "***TINH TOAN***" << endl;
	spcong = sp1 + sp2;
	cout << ">>Cong: ";
	spcong.xuat();
	
	sptru = sp1 - sp2;
	cout << ">>Tru: ";
	sptru.xuat();
	
	spnhan = sp1 * sp2;
	cout << ">>Nhan: ";
	spnhan.xuat();
	
return 0;
}








