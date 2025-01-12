#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

class  hv{
	protected:
		double canh;
	public:
		void nhap(){
			cout << "Nhap do rong: ";
			cin >> canh;
		}
//		double chuvi(){
//			return 4 * canh;
//		}
//		double dientich(){
//			return canh * canh;
//		}
//		void xuat(){
//			cout << "Do dai cua canh = " << canh << endl;
//			cout << "Chu vi = " << chuvi() << endl;
//			cout << "Dien tich = " << dientich() << endl; 
//		}
};
class hcn: public hv{
	private:
		double canh2;
	public:
		void nhap2(){
			hv::nhap();
			cout << "Nhap do dai: ";
			cin >> canh2;
	}	
	
	double chuvihcn(){
		return (canh + canh2) * 2;
	}
	
	double dientichhcn(){
		return canh * canh2;
	}
	void xuat2()	{
		cout << "Dai = " << canh << endl;
		cout << "Rong = " << canh2 << endl;
		cout << "=> Chu vi hcn = " << chuvihcn() << endl;
		cout << "=> Dien tich hcn = " << dientichhcn() << endl; 
	}	
};
int main(){
	int n;
	cout << "Nhap so luong hinh chu nhat: ";
	cin >> n;
	hcn *h = new hcn[n + 1];
	
	for (int i = 1; i <= n; i++){
		cout << ">>>Nhap canh hcn thu " << i << ": " << endl;
		h[i].nhap2();
	}
	cout << "+--------------------------------------------+" << endl;
	for (int i = 1; i <= n; i++){
		cout << ">>>>Thong tin hinh cn thu " << i << "<<<< " << endl;
		h[i].xuat2();		
	}
	
	//sap xep chu vi hcn giam dan
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(h[i].chuvihcn() < h[j].chuvihcn()){
				hcn temp = h[i]; //khai bien temp theo kieu du lieu cua hcn (<hcn temp> thay vi <int temp>)
				h[i] = h[j];
				h[j] = temp;			
			}
		}
	}
	cout << "+-------------------------+" << endl;	
	cout << "Danh sach giam dan la: " << endl;
	for(int i = 1; i <= n; i++){
		cout << h[i].chuvihcn() << endl;
	}
delete h;
return 0;	
}
