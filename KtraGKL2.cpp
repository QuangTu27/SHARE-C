#include<iostream>
#include<math.h>

using namespace std;
class SP{
	private:
		int thuc, ao;
	public:
		SP(){
			thuc = 0;
			ao = 0;
		}
		SP(int thuc, int ao){
			this->thuc = thuc;
			this->ao = ao;
		}
		~SP(){
		}
		
		friend istream &operator >> (istream &nhap, SP &p);
		friend ostream &operator << (ostream &xuat, SP &p);
		float module();
};
istream &operator >> (istream &nhap, SP &p){
	cout << "thuc: ";
	cin >> p.thuc;
	cout << "ao: ";
	cin >> p.ao;
	return nhap;
}

ostream &operator << (ostream &xuat, SP &p){
	cout << ">>So phuc = ";
	cout << p.thuc;
	if(p.ao > 0){
		cout << " + " << p.ao << "i" << endl;
	}
	else{
		cout << " - " << abs(p.ao) << "i" << endl; 
	}
	return xuat;
}

float SP::module(){
	return sqrt(thuc * thuc + ao * ao);
}

int main(){
	int n;
	cout << "Ban muon nhap may so phuc: ";
	cin >> n;
	
	SP *sophuc;
	sophuc = new SP[n];
	for(int i = 0; i < n; i++){
		cout << "+------------------------+" << endl;
		cout << "Nhap so phuc thu " << i + 1 << endl;
		cin >> sophuc[i];
		cout << sophuc[i];
		cout << ">>>>Module = " << sophuc[i].module() << endl;
		
	}
	SP temp;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(sophuc[i].module() > sophuc[j].module()){
				temp = sophuc[i];
				sophuc[i] = sophuc[j];
				sophuc[j] = temp;
			}
		}
	}
	cout << "[Danh sach tang dan theo module]" << endl;
	for(int i = 0; i < n; i++){
		 cout << i + 1 << ". Module = " << sophuc[i].module() << endl;
	}
	
	delete[] sophuc;
	return 0;
}
