#include "DocGhiFile.h"
#include "DanhSachLopTC.h"



void docCay(TREE& t, ifstream& f)
{
	string line;
	getline(f, line);

	MONHOC m;
	int n;
	string temp;
	while (!f.eof())
	{
		n = 0;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		m.MaMH = temp;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		m.TenMH = temp;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		m.stclt = atoi(temp.c_str());
		temp = "";
		for (int i = 0; n < line.size(); i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		m.stcth = atoi(temp.c_str());

		Them_Node_Vao_Cay(t, m);
		getline(f, line);
	}


}


void docSV(DanhSachSinhVien& ds, ifstream& f)
{
	string line;
	getline(f, line);
	SINHVIEN sv;
	int n;
	string temp;
	while (!f.eof()) {
		n = 0;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		sv.MaSV = temp;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		sv.Password = temp;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		sv.HoSV = temp;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		sv.TenSV = temp;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		sv.Phai = atoi(temp.c_str());
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		sv.SDT = temp;
		temp = "";
		for (int i = 0; line[n] != ','; i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		sv.MaLop = temp;
		temp = "";
		for (int i = 0; n < line.size(); i++, n++) {
			temp.push_back(line[n]);
		}
		n++;
		sv.NamNhapHoc = atoi(temp.c_str());

		ThemSinhVienVaoCuoiDanhSach(ds, KhoiTaoNodeSinhVien(sv));
		getline(f, line);

	}
}
void docLopTC(DanhSachLopTC& ds, ifstream& f) {

}

void DocFileSinhVien(DanhSachSinhVien& ds, string& pass)
{
	ifstream f("sinhvien.txt");
	if (f.is_open()) {
		/*	if (!f.peek() == EOF) {
				getline(f, pass);
				docCay(t, f);
				docSV(ds, f);
				f.close();
			}*/
		getline(f, pass);
		docSV(ds, f);
		f.close();
	}
}
void DocFileMonHoc(TREE& t)
{
	ifstream f("monhoc.txt");
	if (f.is_open()) {
		/*	if (!f.peek() == EOF) {
				getline(f, pass);
				docCay(t, f);
				docSV(ds, f);
				f.close();
			}*/
		docCay(t, f);
		f.close();
	}
}
void GhiFileNodeLeftRight(TREE t, ofstream& f)
{
	if (t != NULL) {
		f << t->data.MaMH << "," << t->data.TenMH << "," << t->data.stclt << "," << t->data.stcth << endl;
		GhiFileNodeLeftRight(t->pLeft, f);
		GhiFileNodeLeftRight(t->pRight, f);
	}
}

void GhiFileSV(DanhSachSinhVien ds, string pass)
{
	/*
	string MaSV; // tối đa 10 kí tự
	string HoSV; // tối đa 15 kí tự
	string TenSV; // tối đa 20 kí tự
	int Phai; // tối đa 5 kí tự
	string SDT; // tối đa 11 kí tự
	string MaLop;
	int NamNhapHoc;
	*/
	ofstream f("sinhvien.txt");
	if (f.is_open()) {
		f << pass << endl;
		NodeSinhVien* sv;
		for (sv = ds.pHead; sv != NULL; sv = sv->pNext) {
			f << sv->data.MaSV << "," <<
				sv->data.Password << "," <<
				sv->data.HoSV << "," <<
				sv->data.TenSV << "," <<
				sv->data.Phai << "," <<
				sv->data.SDT << "," <<
				sv->data.MaLop << "," <<
				sv->data.NamNhapHoc << endl;
		}
		f.close();
	}
}
void GhiFileMonHoc(TREE t)
{
	ofstream f("monhoc.txt");
	if (f.is_open()) {
		GhiFileNodeLeftRight(t, f);
		f.close();
	}
}

void DocFileTongQuat(TREE& t, DanhSachSinhVien& ds, DanhSachLopTC& tc, string &pass) {
	DocFileMonHoc(t);
	DocFileSinhVien(ds, pass);
}