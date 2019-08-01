#include "LopTinChi.h"


void Nhap_Thong_Tin_Lop(LOPTINCHI& lopTC)
{
	DanhSachDangKi ds1;
	ThemVaoCuoiDanhSach(ds1, KhoiTaoNodeDangKi({ "n14300",10 }));
	ThemVaoCuoiDanhSach(ds1, KhoiTaoNodeDangKi({ "n14280",9 }));
	ThemVaoCuoiDanhSach(ds1, KhoiTaoNodeDangKi({ "n14281",7 }));
	cin.ignore();
	cout << "Nhap ma top tc" << endl;
	cin >> lopTC.MaLopTC;
	cout << "Nhap ma MH" << endl;


}
void Xuat_Thong_Tin_Lop(LOPTINCHI)
{
}
