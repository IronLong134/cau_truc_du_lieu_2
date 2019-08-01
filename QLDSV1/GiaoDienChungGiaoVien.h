#pragma once
#include "console.h"
#include "GiaoDienTongQuat.h"
#include "DanhSachMonHocGiaoDien.h"
#include "DanhSachLopTC.h"
#include "Login.h"



void khoiTaoMenu(string* thongTinMenuGiaoVien);

void khoiTaoMenuMonHoc(string* thongTinMenuMonHocGiaoVien);

void khoiTaoMenuSinhVien(string* thongTinMenuSinhVien);

void hienThiMenuMonHoc(string* thongTinMenuMonHocGiaoVien, MonHocTheoTen& mhtt);

void hienThiMenuSinhVien(string* thongTinMenuSinhVien);

void hienThiMenuLopTC(string* thongTinMenuLopTC);

void luaChonGiaoVien(string* thongTinMenuMonHocGiaoVien, int luaChon, MonHocTheoTen& mhtt);

void menuAdmin(DanhSachSinhVien& ds, admin& a, TREE& t, DanhSachLopTC& dsTC);
