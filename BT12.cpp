#include <iostream>

using namespace std;
//khai bao kieu tap hop theo mang
int month_table[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_month_table[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class DATE{
	private: 
		int d, m, y;
	public:
		DATE(){
			int d = 0;
			int m = 0;
			int y = 0;
		}
		
		~DATE(){}

		void nhap(){
			cout << "Nhap ngay: "; cin >> d;
			cout << "Nhap thang: "; cin >> m;
			cout << "Nhap nam: "; cin >> y;
		}
		void xuat(){
			cout << "\n" << d << "/" << m << "/" << y;
		} 
		
		bool isLeapYear() {
        	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    	}
		
		bool check(){
			if(d < 1 || d > 31 || m < 1 || m > 12 || y < 1){
				return false;
			}
			if(isLeapYear()){
				if(d > leap_month_table[m - 1] ){
					return false;
				}
			}
			else {
				if(d > month_table[m -1] ){
					return false;
				}
			}
			return true;	
		}
	void tangNgay(){
		d++;
		if (isLeapYear() && m == 2 && d == 29) {
            d = 1;
            m++;
        } else {
            if (d < (isLeapYear() ? leap_month_table[m - 1] : month_table[m - 1])){
                d++;
            } else {
                d = 1;
                m++;
                if (m > 12) {
                    m = 1;
                    y++;
                }
            }
        }
    } 
    void giamNgay(){
    	if(d > 1){
    		d--;
		}
		else{
			if(m == 1){
				m = 12;
				d = 31;
				y--;
			}
			else{
				m--;
				if(isLeapYear() && m == 2){
					d = 29;
				}
				else{
					d = month_table[m - 1];
				}
			}
		}
	}
};

int main(){
	DATE *date = new DATE;
	date->nhap();
	if (date->check()) {
        cout << "\nNgay mai:";
        date->tangNgay();
        date->xuat();
    }  
    else{
		cout << "\nNgay thang nam khong hop le!";
	}
	
	if (date->check()) {
        cout << "\nNgay hom qua:";
        date->giamNgay();
        date->giamNgay();
        date->xuat();
    } else {
        cout << "\nNgay thang nam khong hop le!";
    }
delete date;
return 0;
}


