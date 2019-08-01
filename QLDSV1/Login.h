#pragma once
#include "console.h"
#include "GiaoDienTongQuat.h"
#include "DanhSachSV.h"
using namespace std;

struct admin {
	string username = "admin";
	string password;
};

void logo();

void thietKeDangNhap();

int dangNhapChinh(admin a, DanhSachSinhVien sv);