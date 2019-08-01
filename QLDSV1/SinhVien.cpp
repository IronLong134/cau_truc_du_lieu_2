#include"SinhVien.h"



void Nhap_thong_tin_1sv(SINHVIEN& sv) {
	/*cin.ignore();

	cout << "Nhap ma sinh vien" << endl;
	gets_s(sv.MaSV);
	cin.ignore();
	cout << "Nhap ho sinh vien" << endl;
	getline(cin, sv.HoSV);
	cout << "Nhap ten sinh vien" << endl;
	getline(cin, sv.TenSV);
	cout << "Nhap gioi tinh sinh vien" << endl;
	cin >> sv.Phai;
	cout << "Nhap sdt sinh vien" << endl;
	getline(cin, sv.SDT);
	cout << "Nhap ma lop sinh vien" << endl;
	getline(cin, sv.MaLop);
	cout << "Nhap nam nhap hoc" << endl;
	cin >> sv.NamNhapHoc;*/
}
void Xuat_Thong_tin_1sv(SINHVIEN sv) {
	cout << "-----------------------------" << endl;
	cout << "\nMa sinh vien: " << sv.MaSV;
	cout << "\nHo sinh vien: " << sv.HoSV;
	cout << "\nten sinh vien: " << sv.TenSV;
	cout << "\nGioi tinh: " << sv.Phai;
	cout << "\nso dien thoai: " << sv.SDT;
	cout << "\nMa lop: " << sv.MaLop;
	cout << "\nNam nhap hoc: " << sv.NamNhapHoc;
	cout << "-----------------------------" << endl;
}
