#include"DangKi.h"

void Nhap_tt_1suat_dk(DANGKI& dk) {
	cin.ignore();
	cout << "Nhap ma sinh vien" << endl;
	getline(cin,dk.MaSV);
	//cin.ignore();
	cout << "Nhap diem " << endl;
	cin>>dk.Diem;
}
void Xuat_tt_1suat_dk(DANGKI dk) {
	cout << "-----------------------------" << endl;
	cout << "\nMa sinh vien: " << dk.MaSV;
	cout << "\nDiem: " << dk.Diem << endl;
	cout << "-----------------------------" << endl;
}