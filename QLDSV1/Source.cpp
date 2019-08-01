#include "console.h"
#include"DanhSachDK.h"
#include"DanhSachMonHoc.h"
#include"DanhSachSV.h"
#include <string>
#include"DocGhiFile.h"
#include"GiaoDienTongQuat.h"
#include"Login.h"
#include "DanhSachMonHocGiaoDien.h"
#include "DanhSachLopTC.h"
#include "GiaoDienChungGiaoVien.h"
/*
http://patorjk.com/software/taag/?fbclid=IwAR3zsc1Y6s7j8RBigDgEH5mIZIDZHS5eVnbRSpvWbtMdOWyY1eVt7RMqyGk#p=display&f=Stop&t=quan%20li%20sinh%20vien%20theo%20tin%20chi
*/

void khoiTao(DanhSachSinhVien& ds, admin& a, TREE& t, DanhSachLopTC& dsTC, string &pass) {
	system("color F0");//set background và text mặt định
	fullScreen();
	Xu_Li_Con_Tro_Chi_Vi(FALSE);
	RemoveScroll();
	DocFileTongQuat(t, ds, dsTC, pass);
}

int main() {
	DanhSachSinhVien ds;
	admin a;
	TREE t = NULL;
	DanhSachLopTC dsTC;
	khoiTao(ds, a, t, dsTC, a.password);
	a.username = a.password = "";
	int n = 0;
	int maxX = getXScreen(), maxY = getYScreen();
	while (true)
	{
		clrscr(ColorCode_White, 0, 0, maxX, maxY);
		int check = dangNhapChinh(a, ds); ///check: 1 vô admin, 2 vô user, 0 thoát
		if (check == 1) {
			clrscr(ColorCode_White, 0, 0, maxX, maxY);
			menuAdmin(ds, a,t, dsTC);
		}
		else if(check == 2) {
			clrscr(ColorCode_White, 0, 0, maxX, maxY);
		}
		else if (check == 0) {
			break;
		}
	}

	////XuatDanhSachSv(ds);
	////cout << a.username << " " << a.password << endl;
	//MonHocTheoTen m;
	//insertAllList(m, t);
	//for (int i = 0; i < m.soLuong; i++) {
	//	cout << m.data[i].TenMH << endl;
	//}
	//Them_Node_Vao_Cay(t, { "asdsad", "tri tue nhan tao",4,1 });
	//GhiFileMonHoc(t);
	//_getch();
	//dangNhapChinh(a, ds);

	//GhiFile(t, ds, a.password);

	/*int luachonGV = 0;
	string b = "dsadasd";
	int a = 0;
	int key = 0;
	while (true)
	{
		hienThiMenu(thongTinMenuGiaoVien, luachonGV, 5, 5, 3, ColorCode_White, ColorCode_Blue);
		hienThiMenu(thongTinMenuSinhVien, 0, 5, 5, 10, ColorCode_Black, ColorCode_White);
		inChuoiNhap(b, 50, ColorCode_White, ColorCode_Blue, 50, 10);
		key = _getch();
		thayDoiLuaChon(luachonGV, 5, key);
		if (key == KEY_ENTER) {
			hienThiMenu(thongTinMenuGiaoVien, luachonGV, 5, 5, 3, ColorCode_Black, ColorCode_Cyan);
			luaChon(luachonGV, key, b);
			a = atoi(b.c_str());
			gotoXY(30, 29);
			cout << a;
		}
	}*/
	//Ve_Khung(1, 5, 100, 20);
	/*KhoiTaoDanhSachDangKi(ds);
	MenuDK(ds);*/
	/*Khoi_Tao_Cay(t);
	Menu(t);*/
	//Them_Node_Vao_Cay(t, { "askdd\0", "asdasd\0", 4, 3 });
	//Them_Node_Vao_Cay(t, { "vfdfv\0", "asdasd\0", 2, 3 });
	//Them_Node_Vao_Cay(t, { "qweq\0", "asdasd\0", 4, 3 });
	//Them_Node_Vao_Cay(t, { "zxc\0", "asdasd\0", 4, 3 });
	//Them_Node_Vao_Cay(t, { "a12wdq\0", "asdasd\0", 4, 3 });
	//Them_Node_Vao_Cay(t, { "cvger\0", "asdasd\0", 4, 3 });
	//Them_Node_Vao_Cay(t, { "edfzxc\0", "asdasd\0", 4, 3 });


	/*ThemSinhVienVaoCuoiDanhSach(ds, KhoiTaoNodeSinhVien({ "sdasd","123456","asda","asdasd",6,"asdasd","asdad",1 }));
	ThemSinhVienVaoCuoiDanhSach(ds, KhoiTaoNodeSinhVien({ "kjgh","123456","hgj","ewr",6,"zxc","eqwe",1 }));
	ThemSinhVienVaoCuoiDanhSach(ds, KhoiTaoNodeSinhVien({ "cxzczc","123456","asdasd","wqeqw",6,"sadas","sada",1 }));
	ThemSinhVienVaoCuoiDanhSach(ds, KhoiTaoNodeSinhVien({ "zxcxz","123456","rewr","sdasd",6,"czxc","qweqw",1 }));
	ThemSinhVienVaoCuoiDanhSach(ds, KhoiTaoNodeSinhVien({ "hfgh","123456","weqe","ytut",6,"qweq","tert",1 }));*/
	//Menu(t);
	/*MenuSV(ds);*/
}