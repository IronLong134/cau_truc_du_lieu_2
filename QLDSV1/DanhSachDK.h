#pragma once
#pragma once
#include"DangKi.h"
struct nodedangki
{
	DANGKI data; // dữ liệu của node
	struct nodedangki* pNext; // con trỏ liên kết
};
typedef struct nodedangki NodeDangKi;
struct listDK
{
	NodeDangKi* pHead = NULL;
	NodeDangKi* pTail = NULL;
};
typedef struct listDK DanhSachDangKi;

// hàm khởi tạo danh sách liên kết đơn
void KhoiTaoDanhSachDangKi(DanhSachDangKi&);

void XuatDanhSachDangKi(DanhSachDangKi);
// hàm khởi tạo node
NodeDangKi* KhoiTaoNodeDangKi(DANGKI);
// hàm thêm vào đầu danh sách
void ThemVaoDauDanhSach(DanhSachDangKi&, NodeDangKi*);
// hàm thêm vào cuối danh sách
void ThemVaoCuoiDanhSach(DanhSachDangKi&, NodeDangKi*);

// hàm xóa 1 node đầu danh sách 
void Xoa_Dau_Danh_Sach_DK(DanhSachDangKi&);
// hàm xóa 1 node cuối danh sách 
void Xoa_Cuoi_Danh_Sach_DK(DanhSachDangKi&);

void MenuDK(DanhSachDangKi&);