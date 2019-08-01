#pragma once
#include "console.h"
#include "MonHoc.h"
#include "DanhSachMonHoc.h"
#define MAXDSMON 5000

struct MonHocTheoTen {
	MONHOC data[MAXDSMON];
	int soLuong = 0;
};

void demSLMonHoc(TREE t, int &soluong);

void insertOder(MonHocTheoTen& t, MONHOC m);

void insertAllList(MonHocTheoTen& ds, TREE t);