#include "GiaoDienTongQuat.h"


void inChuoiNhap(string dauvao, int toida, int mauchu, int maunen, int x, int y) {
	SetColor(mauchu);
	SetBGColor(maunen);
	gotoXY(x, y);
	cout << string(toida, ' ');
	gotoXY(x, y);
	int n = dauvao.size() - toida;
	string temp = "";
	for (n = (n < 0) ? 0 : n; n < dauvao.size(); n++) {
		temp.push_back(dauvao[n]);
	}
	cout << temp << " ";
}

void inPass(string dauvao, int toida, int mauchu, int maunen, int x, int y) {

	SetColor(mauchu);
	SetBGColor(maunen);
	gotoXY(x, y);
	cout << string(toida, ' ');
	gotoXY(x, y);
	int n = dauvao.size() - toida;
	string temp = "";
	for (n = (n < 0) ? 0 : n; n < dauvao.size(); n++) {
		temp.push_back('*');
	}
	cout << temp << " ";
}

void xoa(string& dauvao, int key) {
	if (key == KEY_BACKSPACE) {
		if (dauvao.size() > 0)
			dauvao = dauvao.substr(0, dauvao.size() - 1);
	}
}

void nhap(string& dauvao, int key, bool dieuKien) {
	if (dieuKien) {
		dauvao.push_back(char(key));
	}
}

bool dieuKienNhap(int key) {
	if ((key <= 'Z' && key >= 'A') || (key <= 'z' && key >= 'a') || (key <= '9' && key >= '0')) {
		return true;
	}
	return false;
}

void clrscr(int background,int x, int y,int width, int height) {
	SetBGColor(background);
	for (int i = 0; i < height; i++) {
		gotoXY(x, y + i);
		cout << string(width, ' ');
	}
}

string canGiuaChuoi(string dauvao, int toida) {
	string temp;
	temp.resize(toida, ' ');
	int n = (temp.size() - dauvao.size()) / 2;
	for (int i = 0; i < dauvao.size(); i++) {
		temp[i + n] = dauvao[i];
	}
	return temp;
}

void hienThiMenu(string menu[], int luachon,int n, int x, int y, int mauChu, int mauNen) {
	//int n= sizeof(menu) / sizeof(string);
	for (int i = 0; i < n; i++) {
		gotoXY(x, y + i);
		if (i == luachon) {
			SetColor(mauChu);
			SetBGColor(mauNen);
		}
		else {
			SetColor(ColorCode_Black);
			SetBGColor(ColorCode_White);
		}
		cout << canGiuaChuoi(menu[i], 40);
	}
}

void thayDoiLuaChon(int& luachon, int toida, int key) {
	if (key == KEY_CONTROL) {
		key = _getch();
		if (key == KEY_UP) {
			if (luachon == 0) {
				luachon = toida - 1;
			}
			else {
				luachon--;
			}
		}
		else if (key == KEY_DOWN) {
			if (luachon == toida - 1) {
				luachon = 0;
			}
			else {
				luachon++;
			}
		}
	}
}