#include "MonHoc.h"
void Nhap_thong_tin_1mh(MONHOC& mh)
{
	//fflush(stdin);
	cin.ignore();
	cout << "Nhap ma mon hoc " << endl;
	getline(cin, mh.MaMH);
	fflush(stdin);
	cout << "Nhap ten mon hoc" << endl;
	getline(cin, mh.TenMH);
	cout << "Nhap so tin chi li thuyet " << endl;
	cin >> mh.stclt;
	cout << "Nhap so tin chi thuc hanh " << endl;
	cin >> mh.stcth;
}
//void Doc_thong_tin_1mh(ifstream &file, MONHOC) {
//	
//}
void Xuat_thong_tin_1mh(MONHOC mh)
{
	cout << "-----------------------------" << endl;
	cout << "\nMa mon hoc: " << mh.MaMH;
	cout << "\nTen mon hoc: " << mh.TenMH;
	cout << "\nSo tin chi ly thuyet: " << mh.stclt;
	cout << "\nSo tin chi thuc hanh: " << mh.stcth;
	cout << "-----------------------------" << endl;
}