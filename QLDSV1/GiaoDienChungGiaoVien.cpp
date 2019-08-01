#include "GiaoDienChungGiaoVien.h"
void khoiTaoMenu(string* thongTinMenuGiaoVien) {
	thongTinMenuGiaoVien[0] = "Dieu Chinh Danh Sach Mon Hoc";
	thongTinMenuGiaoVien[1] = "Dieu Chinh Danh Sach Sinh Vien";
	thongTinMenuGiaoVien[2] = "Dieu Chinh Danh Sach Lop Tin Chi";
	thongTinMenuGiaoVien[3] = "Dieu Chinh Danh Sach Dang Ky";
	thongTinMenuGiaoVien[4] = "Dang ki mon hoc cho sinh vien";
	thongTinMenuGiaoVien[5] = "Thoat";

}

void khoiTaoMenuMonHoc(string* thongTinMenuMonHoc) {
	thongTinMenuMonHoc[0] = "Xuat Thong Tin Mon Hoc";
	thongTinMenuMonHoc[1] = "Them Mon Hoc";
}
void khoiTaoMenuSinhVien(string* thongTinMenuSinhVien) {
	thongTinMenuSinhVien[0] = "Xuat Danh Sach Tat ca sinh vien";
	thongTinMenuSinhVien[1] = "Them sinh vien vao lop";
	thongTinMenuSinhVien[2] = "Nhap danh sach sinh vien cho lop moi";
	thongTinMenuSinhVien[3] = "Xuat danh sach sinh vien theo lop";
}
void khoiTaoMenuLopTC(string* thongTinMenulopTC) {
	thongTinMenulopTC[0] = "Xuat Danh Sach Tat ca cac lop TC";
	thongTinMenulopTC[1] = "Them lop tin chi";
	thongTinMenulopTC[2] = "Nhap diem";
	thongTinMenulopTC[3] = "Xem danh sach sinh vien theo lop TC";
}


int timPhanTuCuoiCung(MonHocTheoTen& mhtt, int viTriBatDau) {
	return ((viTriBatDau + 20) > mhtt.soLuong) ? (viTriBatDau + 20) - ((viTriBatDau + 20) - mhtt.soLuong) : viTriBatDau + 20;
}

void hienThiThongTinMonHoc(MonHocTheoTen& mhtt, int viTriBatDau, int dangChon, int mauNen) {//  hàm hiển thị list thông tin môn học lên giao diện
	int phanTuCuoi = timPhanTuCuoiCung(mhtt, viTriBatDau);
	for (int i = viTriBatDau; i < phanTuCuoi; i++) {
		if (i == dangChon) {
			SetBGColor(mauNen);
			SetColor(ColorCode_White);
		}
		else {
			SetBGColor(ColorCode_White);
			SetColor(ColorCode_Black);
		}
		gotoXY(60, 11 + i);
		cout << mhtt.data[i].TenMH;
	}
}
//xu lí cho menu mon hoc
void hienThiMenuMonHoc(string* thongTinMenuMonHoc, MonHocTheoTen& mhtt) { //Hiển thị menu con môn học, 
	int luaChon = 0;
	int key = 0;
	while (key != KEY_ESC)
	{
		hienThiMenu(thongTinMenuMonHoc, luaChon, 2, 4, 25, ColorCode_White, ColorCode_Blue);
		if (luaChon == 0) {

			hienThiThongTinMonHoc(mhtt, 0, 0, ColorCode_Cyan);// gọi hàm hiển thị môn học lên gd

		}
		key = _getch();
		thayDoiLuaChon(luaChon, 2, key);
	}
}
//xử lí cho menu sinh viên
void hienThiMenuSinhVien(string* thongTinMenuSinhVien) { //Hiển thị menu con sinh vien, 
	int luaChon = 0;
	int key = 0;
	while (key != KEY_ESC)
	{
		hienThiMenu(thongTinMenuSinhVien, luaChon, 4, 4, 25, ColorCode_White, ColorCode_Blue);
		if (luaChon == 0) {
			// gọi hàm hiển thị môn học lên gd
		}
		key = _getch();
		thayDoiLuaChon(luaChon, 4, key);
	}
}
void hienThiMenuLopTC(string* thongTinMenuLopTC) { //Hiển thị menu con sinh vien, 
	int luaChon = 0;
	int key = 0;
	while (key != KEY_ESC)
	{
		hienThiMenu(thongTinMenuLopTC, luaChon, 4, 4, 25, ColorCode_White, ColorCode_Blue);
		if (luaChon == 0) {
			// gọi hàm hiển thị môn học lên gd
		}
		key = _getch();
		thayDoiLuaChon(luaChon, 4, key);
	}
}
//xử lí các thao tác lựa chọn trong menu lớn
void luaChonGiaoVien(string* thongTinMenuMonHoc, string* thongTinMenuSinhVien ,string* thongTinMenuLopTC, int luaChon, MonHocTheoTen& mhtt) {//.lựa chọn cho menu lớn của gv
	if (luaChon == 0) {
		//clrscr(ColorCode_White, 1, , 100, 100);
		hienThiMenuMonHoc(thongTinMenuMonHoc, mhtt);
	}
	else if (luaChon == 1) {
		//clrscr(ColorCode_White, 4, 70, 100,100);
		hienThiMenuSinhVien(thongTinMenuSinhVien);
	}
	else if (luaChon == 2) {
		hienThiMenuLopTC(thongTinMenuLopTC);
	}
}
void tieuDe() {
	int batDau = (getXScreen() - 65) / 2;
	SetColor(ColorCode_Blue);
	SetBGColor(ColorCode_White);
	gotoXY(batDau, 3);
	cout << "                        ___       _      __          _ ";
	gotoXY(batDau, 4);
	cout << " ___ ___ _____ ____    / (_) ___ (_)__  / /    _  __(_)__ ___ ";
	gotoXY(batDau, 5);
	cout << "/ _ `/ // / _ `/ _ \\  / / / (_-</ / _ \\/ _ \\  | |/ / / -_) _ \\";
	gotoXY(batDau, 6);
	cout << "\\_, /\\_,_/\\_,_/_//_/ /_/_/ /___/_/_//_/_//_/  |___/_/\\__/_//_/";
	gotoXY(batDau, 7);
	cout << " /_/ ";
}
void VeKhungLamViec() {


	
//                        ___       _      __          _        
// ___ ___ _____ ____    / (_) ___ (_)__  / /    _  __(_)__ ___ 
/// _ `/ // / _ `/ _ \  / / / (_-</ / _ \/ _ \  | |/ / / -_) _ \
//\_, /\_,_/\_,_/_//_/ /_/_/ /___/_/_//_/_//_/  |___/_/\__/_//_/
// /_/                                                          

	tieuDe();
	Ve_Khung(3,9,41,10);//x,y.width,height
	Ve_Khung(3,22, 41, 7);
	Ve_Khung(50, 9, 140, 40);
}

void menuAdmin(DanhSachSinhVien& ds, admin& a, TREE& t, DanhSachLopTC& dsTC) {
	int luachonGV = 0;
	//khai báo các menu
	string thongTinMenuGiaoVien[6];
	string thongTinMenuMonHoc[2];
	string thongTinMenuSinhVien[4];
	string thongTinMenuLopTC[4];
	MonHocTheoTen mhtt;
	insertAllList(mhtt, t);
	//khoi tao menu
	khoiTaoMenu(thongTinMenuGiaoVien);
	khoiTaoMenuMonHoc(thongTinMenuMonHoc);
	khoiTaoMenuSinhVien(thongTinMenuSinhVien);
	khoiTaoMenuLopTC(thongTinMenuLopTC);
	int key = 0;
	Xu_Li_Con_Tro_Chi_Vi(0);
	while (true)
	{
		VeKhungLamViec();
		hienThiMenu(thongTinMenuGiaoVien, luachonGV, 6, 4, 11, ColorCode_White, ColorCode_Blue);
		//hienThiMenu(thongTinMenuMonHoc, 0, 2, 4, 25, ColorCode_White, ColorCode_Cyan);
		//hienThiThongTinMonHoc(mhtt, 0, 0, ColorCode_Cyan);
		key = _getch();
		thayDoiLuaChon(luachonGV, 6, key);
		if (key == KEY_ENTER) {
			if (luachonGV == 5) {
				return;
			}
			else {
				hienThiMenu(thongTinMenuGiaoVien, luachonGV, 5, 4, 11, ColorCode_White, ColorCode_Cyan);
				luaChonGiaoVien(thongTinMenuMonHoc, thongTinMenuSinhVien,thongTinMenuLopTC, luachonGV, mhtt);
			}
		}
	}
}