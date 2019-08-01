#include "Login.h"

void logo()
{
	/*
	.___                       .____
|   |______  ____   ____   |    |    ____   ____    ____
|   \_  __ \/  _ \ /    \  |    |   /  _ \ /    \  / ___\
|   ||  | \(  <_> )   |  \ |    |__(  <_> )   |  \/ /_/  >
|___||__|   \____/|___|  / |_______ \____/|___|  /\___  /
					   \/          \/          \//_____/
	*/
	int batDau = (getXScreen() - 55) / 2;
	SetColor(ColorCode_Blue);
	SetBGColor(ColorCode_White);
	gotoXY(batDau, 3);
	cout << ".___                       .____                       ";
	gotoXY(batDau, 4);
	cout << "|   |______  ____   ____   |    |    ____   ____    ____  ";
	gotoXY(batDau, 5);
	cout << "|   \\_  __ \\/  _ \\ /    \\  |    |   /  _ \\ /    \\  / ___\\";
	gotoXY(batDau, 6);
	cout << "|   ||  | \\(  <_> )   |  \\ |    |__(  <_> )   |  \\/ /_/  >";
	gotoXY(batDau, 7);
	cout << "|___||__|   \\____/|___|  / |_______ \\____/|___|  /\\___  / ";
	gotoXY(batDau, 8);
	cout << "                       \\/          \\/          \\//_____/   ";
}

void thietKeDangNhap()
{
	SetColor(ColorCode_Blue);
	SetBGColor(ColorCode_White);
	int maxX = getXScreen(), maxY = getYScreen();
	Ve_Khung(maxX / 3, 11, maxX / 3, 9);
	gotoXY(maxX / 3 + 2, 14);
	cout << "Username:";
	Ve_Khung(maxX / 3 + 20, 13, maxX / 3 - 21, 2);
	gotoXY(maxX / 3 + 2, 17);
	cout << "Password:";
	Ve_Khung(maxX / 3 + 20, 16, maxX / 3 - 21, 2);
}



int dangNhapChinh(admin a, DanhSachSinhVien sv)
{
	logo();
	thietKeDangNhap();
	int maxX = getXScreen(), maxY = getYScreen();
	int key = 0;
	admin input;
	input.username = "";
	int check = 1; //de check con tro
	Xu_Li_Con_Tro_Chi_Vi(1);
	while (key != KEY_ESC)
	{
		inChuoiNhap(input.username, maxX / 3 - 25, ColorCode_Black, ColorCode_White, maxX / 3 + 21, 14);
		inPass(input.password, maxX / 3 - 25, ColorCode_Black, ColorCode_White, maxX / 3 + 21, 17);
		if (check) {
			if (input.username.size() < maxX / 3 - 25) {
				gotoXY(maxX / 3 + 21 + input.username.size(), 14);
			}
			else {
				gotoXY((maxX / 3 + 21) + (maxX / 3 - 25), 14);
			}
		}
		else {
			if (input.password.size() < maxX / 3 - 25) {
				gotoXY(maxX / 3 + 21 + input.password.size(), 17);
			}
			else {
				gotoXY((maxX / 3 + 21) + (maxX / 3 - 25), 17);
			}
		}
		key = _getch();
		if (key == KEY_CONTROL) {
			key = _getch();
			if (key == KEY_UP || key == KEY_DOWN) {
				check = !check;
			}
		}
		else if (key == KEY_TAB) {
			check = !check;
		}
		else if (key == KEY_ENTER) {
			if (input.username == a.username && input.password == a.password) {
				return 1;
			}
			input.password = "";
		}
		else if (check) {
			nhap(input.username, key, dieuKienNhap(key));
			xoa(input.username, key);
		}
		else {
			nhap(input.password, key, dieuKienNhap(key));
			xoa(input.password, key);
		}
	}
	return 0;
}