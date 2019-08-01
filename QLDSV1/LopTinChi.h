#pragma once
#include"MonHoc.h"
#include"DanhSachDK.h" // gọi lại file danh sách sinh viên

// khai báo cấu trúc lớp
struct LopTinChi
{
	int MaLopTC; // tối đa 12 kí tự
	string MaMH; // tối đa 12 kí tự
	string NienKhoa;
	int NamNhapHoc; //tối đa 4 kí tự
	DanhSachDangKi dsDangKi; // con trỏ sẽ trỏ đến danh sách sinh viên - mỗi 1 cái lớp khi khởi tạo sẽ khởi tạo kèm theo 1 danh sách sinh viên
};
typedef struct LopTinChi LOPTINCHI;
void Nhap_Thong_Tin_Lop( LOPTINCHI&);
void Xuat_Thong_Tin_Lop(LOPTINCHI);