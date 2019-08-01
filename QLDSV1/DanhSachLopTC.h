#pragma once // tránh tình trạng đụng độ thư viện
#include"LopTinChi.h"
#include"console.h"

// khai báo cấu trúc danh sách lớp
struct DanhSachLopTC
{
	LOPTINCHI dslopTC[100]; // khai báo mảng tuyến tính lớp <=> mảng 1 chiều chứa tối đa 100 phần tử 
	int n;// số lượng phần tử của mảng 1 chiều các lớp

};
typedef struct DanhSachLopTC DanhSachLopTC;