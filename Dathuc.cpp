#include<iostream>
#include<math.h>
using namespace std;
class Dathuc{
	private:
		int bac;
		int *hs;
		
	public:
		void nhap();
		void xuat();
		Dathuc operator +(Dathuc b);
};

void Dathuc::nhap(){
	cout << endl <<"Nhap bac da thuc: ";
	
	cin >> bac;
	hs = new int[bac + 1];
	for(int i = 0; i <= bac; i++){
		cout << "He so thu " << i << " :";
		cin >> hs[i];
	}
}
void Dathuc::xuat(){
	for(int i = 0; i <= bac; i++){
		if(hs[i] > 0){
			cout <<" +" << hs[i] <<"*x^" <<i;
		}
		else{
			cout << " -" <<hs[i]*-1 <<"*x^" <<i;
		}
	}
}
//hs[i] < 0 ? cout << "-" hs[i]* -1 << "*x^":cout << "+" << hs[i] << "*x^" << i;
Dathuc Dathuc::operator +(Dathuc b){
	Dathuc d;
	int k;
	
	if(bac > b.bac){
		k = bac;
	}
	else{
		k = b.bac;
		d.hs = new int[k + 1];
	}
	
	for(int i = 0; i <= k ; i++){
		if(i <= bac && i <= b.bac){
			d.hs[i] = hs[i] + b.hs[i];
		}
		else if(i <= bac){
			d.hs[i] = hs[i];
		}
		else{
			d.hs[i] = b.hs[i];	
		}
	}
	d.bac = k;
	return d;
}

int main(){
	Dathuc a, b, c;
	a.nhap();
	a.xuat();
	b.nhap();
	b.xuat();
	
	c = a + b;
	cout << endl << "Tong 2 da thuc: ";
	c.xuat();
	
return 0;
}















