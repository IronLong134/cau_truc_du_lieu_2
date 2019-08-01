#pragma once
#include"console.h"

void inChuoiNhap(string dauvao, int toida, int mauchu, int maunen, int x, int y);

void inPass(string dauvao, int toida, int mauchu, int maunen, int x, int y);

void xoa(string& dauvao, int key);

void nhap(string& dauvao, int key, bool dieuKien);

bool dieuKienNhap(int key);

void clrscr(int background, int x, int y, int width, int height);

string canGiuaChuoi(string dauvao, int toida);

void hienThiMenu(string menu[],int n, int luachon, int x, int y, int mauChu, int mauNen);

void thayDoiLuaChon(int& luachon, int toida, int key);
