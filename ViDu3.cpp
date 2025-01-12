#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	struct{
		char ht[50];
		float t, l, h, td;
	} ts[50], tg;
	
	int n, i;
	cout << "Nhap vao so thi sinh: ";
	cin >> n;
	for(i = 1; i <= n; i++){
		cout << "Nhap ten sv " << i << ": ";
		cin.ignore();
		cin.getline(ts[i].ht, sizeof(ts[i].ht));
		
		cout << "Nhap diem toan: "; cin >> ts[i].t; 
		cout << "Nhap diem ly: "; cin >> ts[i].l;
		cout << "Nhap diem hoa: "; cin >> ts[i].h;
		
		//tong diem
		ts[i].td = ts[i].t + ts[i].l + ts[i].h;
		cout << "=> Tong diem = " << ts[i].td << endl;
	}
	//Danh sach tong diem cua cac thi sinh
	cout << "Danh sach tong diem cua cac thi sinh la:" << endl;
	for(i = 1; i <= n; i++){
		cout << ts[i].ht << ": " << ts[i].td << endl;
	}
	//sap xep tang dan td
	int j;
	for(i = 1; i <= n; i++){
		for(j = 1 + i;j <= n; j++){
			if(ts[i].td > ts[j].td){
				tg = ts[i];
				ts[i] = ts[j];
				ts[j] = tg;
			}
		}
	}
	cout << "Danh sach tang dan la: " << endl;
	for(i = 1; i <= n; i++){
		 cout << ts[i].ht << ": " << ts[i].td << endl;
	}
return 0;
}
