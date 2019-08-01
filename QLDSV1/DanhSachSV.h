#pragma once
#include"SinhVien.h"
struct nodesinhvien
{
	SINHVIEN data; // dữ liệu của node
	struct nodesinhvien* pNext; // con trỏ liên kết
};
typedef struct nodesinhvien NodeSinhVien;
struct listSV
{
	NodeSinhVien* pHead = NULL;
	NodeSinhVien* pTail = NULL;
};
typedef struct listSV DanhSachSinhVien;


void XuatDanhSachSv(DanhSachSinhVien);
// hàm khởi tạo node
NodeSinhVien* KhoiTaoNodeSinhVien(SINHVIEN);
// hàm thêm vào đầu danh sách
void ThemSinhVienVaoDauDanhSach(DanhSachSinhVien&, NodeSinhVien*);
// hàm thêm vào cuối danh sách
void ThemSinhVienVaoCuoiDanhSach(DanhSachSinhVien&, NodeSinhVien*);

// hàm xóa 1 node đầu danh sách 
void Xoa_Dau_Danh_Sach(DanhSachSinhVien&);
// hàm xóa 1 node cuối danh sách 
void Xoa_Cuoi_Danh_Sach(DanhSachSinhVien&);


void MenuSV(DanhSachSinhVien&);