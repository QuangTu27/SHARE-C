#include<iostream>
#include<iomanip>
using namespace std;
class maTran{
	private:
		int n;
		int i, j;
		int a[10][10];		
	public:
		void nhap();
		void xuat();
		void dcc();
		void dcp();
		void vien();
		void maxMin();
		void chanLe();
};
int main(){
	
	maTran *mt;
	mt = new maTran[10*10 + 1]; // [n*m +1]; theo phan tu khai bao trong attribute
	mt -> nhap();
	mt -> xuat();
	mt -> dcc();
	mt -> dcp();
	mt -> vien();

	delete mt;
return 0;
}
void maTran:: nhap(){
	cout << "Nhap so phan tu cua ma tran: ";
	cin >> n;
	
	for(i =1; i <= n; i++){
		for(j = 1; j <= n; j++){
			cout << "a[" << i << j << "]= ";
			cin >> a[i][j];
		}
	}
}

void maTran:: xuat(){
	cout << "Ma tran la: " << endl;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			cout << setw(5) << a[i][j];			
		}
		cout << endl; 
	}
	
}
void maTran:: dcc(){
	//Tong phan tu nam tren duong cheo chinh
		int sum = 0;
	cout << "Cac phan tu nam tren dcc la: ";
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(i == j){
				cout << setw(3) << a[i][j];
				sum += a[i][j];
			}
		}
	}
	cout << endl;
	cout << "Tong dcc = " << sum << endl;
	
	
} 
void maTran:: dcp(){
	//Tong phan tu nam tren duong cheo phu
		int sump = 0;
	cout << "Cac phan tu nam tren dcp la: ";
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			if(n + 1 == i + j){
				cout << setw(3) << a[i][j];
				sump += a[i][j];
			}
		}
	}
	cout << endl;
	cout << "Tong dcp = " << sump;
}
//Tinh tong vien ma tran
void maTran::vien() {
	int sumv = 0;
	for(i = 1; i <= n; i++){
		sumv += a[i][1] + a[i][n];
	}
	for(j = 2; j <= n - 1; j++){
		sumv += a[1][j] + a[n][j];			
	}
		
	cout << "Tong vien = " << sumv;
}
void maTran::maxMin() {
	int max = 0;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			max = 
		}
	}
}









