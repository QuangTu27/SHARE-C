#include<iostream>
using namespace std;

class HOUR{
	private:
		int giay, phut, gio;
	public:
		HOUR(){
			int giay = 0;
			int phut = 0;
			int gio = 0;
		}
		
		void nhap(){
			cout << "Nhap gio : "; cin >> gio;
			cout << "Nhap phut: "; cin >> phut;
			cout << "Nhap giay: "; cin >> giay;
		}
		void xuat(){
			cout << "\n" << gio << ":" << phut << ":" << giay;
		}
		
		bool check(int gio, int phut, int giay){
			if(gio < 0 || gio > 24 || phut < 0 || phut >= 60 || giay < 0 || giay >= 60){
				return false;
			}
			return true;
		}
		
		void tangGiay(){
			giay++;
			if(!check(gio, phut, giay)){
			if(!check(gio, phut, giay)){
				giay = 0;
				phut++;
				if(!check(gio, phut, giay)){
					giay = 0;
					phut = 0;
					gio++;
					if(!check(gio, phut, giay)){
						gio = 0;
						phut = 0;
						giay = 0;
					}
				}
			}
		}
		else{
		cout << "Gio khong hop le!!";
		}
	}
};

int main(){
	HOUR *h = new HOUR;
		h->nhap();
		h->tangGiay();
		cout << "\n>>Gio sau khi tang la: ";
		h->xuat();
delete h;
return 0;
}








