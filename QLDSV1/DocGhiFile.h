#pragma once
#include "DanhSachMonHoc.h"
#include "DanhSachSV.h"
#include <fstream>
#include "DanhSachLopTC.h"

void docCay(TREE& t, ifstream &f);
//Doc sinh vien
void docSV(DanhSachSinhVien& ds, ifstream& f);
void docLopTC(DanhSachLopTC& ds, ifstream& f);
void DocFileSinhVien( DanhSachSinhVien &ds, string &pass);
void DocFileMonHoc(TREE& t);
void GhiFileNodeLeftRight(TREE t, ofstream& f);
void GhiFileSV (DanhSachSinhVien ds, string pass);

void GhiFileMonHoc(TREE t);

void DocFileTongQuat(TREE& t, DanhSachSinhVien& ds, DanhSachLopTC& tc, string& pass);
