#pragma once
#include"MonHoc.h"
struct nodemonhoc
{
	MONHOC data;
	struct nodemonhoc* pLeft;
	struct nodemonhoc* pRight;
};
typedef struct nodemonhoc NODEMONHOC;
typedef NODEMONHOC* TREE;

struct DSmonhoc
{
	MONHOC danhsachmonhoc[10000];
	int n;
};
typedef struct DSmonhoc DannhSachMonHoc;
void Khoi_Tao_Cay(TREE&);


void Them_Node_Vao_Cay(TREE&, MONHOC);



void Tim_Node_The_Mang_Cho_Node_Bi_Xoa_1(NODEMONHOC *&, NODEMONHOC *&);
//void In_Tieu_De(int);
//
//
//void Nhap_Thong_Tin_1_Mon_Hoc(MONHOC &); 
//
//
//void Xuat_Du_Lieu(MONHOC);
//
//

//void Tim_Node_The_Mang_Cho_Node_Bi_Xoa_2(NODEMONHOC *&, NODEMONHOC *&);
//
//
//void XoaNode(TREE &, MONHOC);

void Duyet_NLR(TREE t);

void Xuat_tang_dan_theo_ten(TREE t,DannhSachMonHoc& ds);

void Menu(TREE&);