#pragma once // tránh tình trạng đụng độ thư viện
#include"MonHoc.h"


// khai báo cấu trúc của 1 thằng sinh viên
struct sinhvien
{
	string MaSV; // tối đa 10 kí tự
	string Password = "123456";
	string HoSV; // tối đa 15 kí tự
	string TenSV; // tối đa 20 kí tự
	int Phai; // tối đa 5 kí tự
	string SDT; // tối đa 11 kí tự
	string MaLop;
	int NamNhapHoc;

	//DanhSachDiem dsDiem; // con trỏ trỏ đến danh sách điểm - Mỗi 1 thằng sinh viên sẽ có 1 danh sách điểm riêng
};
typedef struct sinhvien SINHVIEN;
void Nhap_thong_tin_1sv(SINHVIEN&);
void Xuat_Thong_tin_1sv(SINHVIEN);