#include<iostream>
#include<math.h>

using namespace std;
class tamGiac;
class Diem{
	private:
		float x, y;
	public:
		Diem(){
			x = 0;
			y = 0;
		}
		Diem(float x1, float y1){
			x = x1;
			y = y1;
		}
		~Diem(){
		};
		
		void nhap(){
			cout << "x: "; cin >> x;
			cout << "y: "; cin >> y;
		}
		void xuat(){
			cout << " (" << x << ", " << y << ")" << endl;
		}
		
		friend float KC2D(Diem d1, Diem d2);	
		
		friend class tamGiac;
};

float KC2D(Diem d1, Diem d2){
	return sqrt(pow((d2.x - d1.x), 2) + pow((d2.y - d1.y), 2));
}

class tamGiac{
	private:
		Diem d1, d2, d3;
		float AB, AC, BC;
	public:
		float chuVi(), dienTich();
		void nhapTG();
		void xuatTG();
		
		bool checktg();
		bool checktgDeu();
		bool checktgCan();
		bool checktgVuong();
};

void tamGiac::nhapTG(){
	cout << "Nhap toa do dinh A: " << endl; d1.nhap();
	cout << "Nhap toa do dinh B: " << endl; d2.nhap();
	cout << "Nhap toa do dinh C: " << endl; d3.nhap();
	
	AB = KC2D(d1, d2);
	AC = KC2D(d1, d3);
	BC = KC2D(d2, d3);
}

void tamGiac::xuatTG(){
	cout << "[TOA DO]" << endl;
	cout << "A ="; d1.xuat(); cout;
	cout << "B ="; d2.xuat(); cout;
	cout << "C ="; d3.xuat(); cout << endl;
	
	cout << "[DO DAI]" << endl;
	cout << "AB = " << AB << endl;	
	cout << "AC = " << AC << endl;
	cout << "BC = " << BC << endl;
}

float tamGiac::chuVi(){
	return AB + AC + BC;
}

float tamGiac::dienTich(){
	float p = chuVi() / 2;
	return sqrt(p * (p - AB) * (p - AC) * (p - BC));
}
bool tamGiac::checktg(){
	if(AB + AC > BC && AB + BC > AC && AC + BC > AB){
		return true;
	}
	return false;
}

bool tamGiac::checktgDeu(){
	if( checktg() == true && AB == AC && AC == BC){
		return true;
	}
	return false;
}

bool tamGiac::checktgCan(){
	if(checktg() == true){
		if(AB == AC || AB == BC || AC == BC){
			return true;
		}
	}
	return false;
}

bool tamGiac::checktgVuong(){
	if(checktg() == true){
		if(pow(AB, 2) + pow(AC, 2) == pow(BC, 2) || pow(AB, 2) + pow(BC, 2) == pow(AC, 2) || 
												pow(BC, 2) + pow(AC, 2) > pow(AB, 2)){
			return true;
		}
	}
	return false;
}
int main(){
//	Diem d1, d2;
//	d1.nhap();
//	d1.xuat();
//	
//	d2.nhap();
//	d2.xuat();
//
//	float res = KC2D(d1, d2);
//	cout << "Khoang cach 2 diem = " << res;

	tamGiac tg;
	tg.nhapTG();
	tg.xuatTG();
	
	if (!tg.checktg()) { 
        cout << "Day khong phai tam giac!!" << endl; // 00,11,22
        return 0; 
    }

    if (tg.checktgDeu()) {
        cout << ">>Day la Tam giac deu co: " << endl; //00,20,1 1.732
        cout << "Chu vi = " << tg.chuVi() << endl;
        cout << "Dien tich = " << tg.dienTich() << endl;
	} else if (tg.checktgCan()) {
        cout << ">>Day la Tam giac can co: " << endl; // 00,20,12
        cout << "Chu vi = " << tg.chuVi() << endl;
        cout << "Dien tich = " << tg.dienTich() << endl;
    } else if (tg.checktgVuong()) {
        cout << ">>Day la Tam giac vuong co: " << endl; // 00,30,04
        cout << "Chu vi = " << tg.chuVi() << endl;
        cout << "Dien tich = " << tg.dienTich() << endl;
    } else {
        cout << ">>Day la mot tam giac thuong co: " << endl; //00,40,23
        cout << "Chu vi = " << tg.chuVi() << endl;
        cout << "Dien tich = " << tg.dienTich() << endl;
    }

return 0;
}
