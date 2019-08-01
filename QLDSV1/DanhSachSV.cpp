#include"DanhSachSV.h"
#include"string.h"

NodeSinhVien* KhoiTaoNodeSinhVien(SINHVIEN sv)
{
	NodeSinhVien* p = new NodeSinhVien;
	if (p == NULL)
	{
		return NULL;
	}

	p->data = sv;
	p->pNext = NULL;
	return p;
}
void XuatDanhSachSv(DanhSachSinhVien ds) {
	for (NodeSinhVien* sv = ds.pHead; sv != NULL; sv = sv->pNext)
	{
		Xuat_Thong_tin_1sv(sv->data);
	}
}
void ThemSinhVienVaoDauDanhSach(DanhSachSinhVien& ds, NodeSinhVien* ins)
{
	// nếu danh sách đang rỗng
	if (ds.pHead == NULL)
	{
		ds.pHead = ds.pTail = ins;
	}
	else
	{
		ins->pNext = ds.pHead;
		ds.pHead = ins;
	}
}
void ThemSinhVienVaoCuoiDanhSach(DanhSachSinhVien& ds, NodeSinhVien* ins)
{
	// nếu danh sách đang rỗng
	if (ds.pHead == NULL)
	{
		ds.pHead = ds.pTail = ins;
	}
	else
	{
		ds.pTail->pNext = ins;
		ds.pTail = ins;
	}
}
void Xoa_Dau_Danh_Sach(DanhSachSinhVien& ds)
{
	// danh sách đang rỗng
	if (ds.pHead == NULL)
	{
		return;
	}
	NodeSinhVien* del = ds.pHead; // Cho node del giữ node đầu để tí ta xóa node p cũng chính là xóa node đầu
	ds.pHead = ds.pHead->pNext; // cập nhật lại pHead là thằng kế tiếp
	delete del; // xóa node đầu

	// nếu sau khi xóa mà pHead đang trỏ đến NULL thì pTail cũng trỏ đến NULL
	if (ds.pHead == NULL)
	{
		ds.pTail = NULL;
	}
}

// hàm xóa 1 node cuối danh sách 
void Xoa_Cuoi_Danh_Sach(DanhSachSinhVien& ds)
{
	// nếu danh sách đang rỗng
	if (ds.pHead == NULL)
	{
		return;
	}
	// duyệt tìm node cuối bằng cách dùng node kế cuối trỏ đến cuối
	for (NodeSinhVien* prev = ds.pHead; prev != NULL; prev = prev->pNext)
	{
		// duyệt và tìm node cuối
		if (prev->pNext == ds.pTail)
		{
			prev->pNext = NULL; // cập nhật lại node kế cuối sẽ là pTail
			delete ds.pTail;
			ds.pTail = prev;
			break; // kết thúc quá trình xóa
		}
	}

	// nếu sau khi xóa mà pHead đang trỏ đến NULL thì pTail cũng trỏ đến NULL
	if (ds.pHead == NULL)
	{
		ds.pTail = NULL;
	}
}
bool Kiem_tra_ton_tai(DanhSachSinhVien ds, char* masv)
{

	for (NodeSinhVien* run = ds.pHead; run != NULL; run = run->pNext)
	{
		// mã sinh viên tồn tại
		if (run->data.MaSV == masv)
		{
			SINHVIEN sv;
			sv = run->data;
			return true;
		}
	}
	return false;
}
SINHVIEN Lay_Thong_Tin_Sinh_Vien_Theo_Ma(DanhSachSinhVien ds, char* masv)
{

	for (NodeSinhVien* run = ds.pHead; run != NULL; run = run->pNext)
	{
		// mã sinh viên tồn tại
		if (run->data.MaSV == masv)
		{
			SINHVIEN sv;
			sv = run->data;
			return sv;
		}
	}
}

void MenuSV(DanhSachSinhVien& ds)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======== QUAN LY DANH SACH SINH VIEN ========\n";
		cout << "\n1. Nhap sinh vien";
		cout << "\n2. Xuat danh sach sinh vien";
		cout << "\n3. Xoa dau danh sach";
		cout << "\n4. Xoa cuoi danh sach";
		cout << "\n51. Tìm kiếm theo mã sv";
		cout << "\n5. Them NODE k sau NODE q trong danh sach";
		cout << "\n6. Xoa 1 cai NODE sau NODE q trong danh sach";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =================== END  ==================\n";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			SINHVIEN sv;
			cout << "\n\n\t\t NHAP SINH VIEN\n";
			Nhap_thong_tin_1sv(sv);

			NodeSinhVien* p = KhoiTaoNodeSinhVien(sv);
			//ThemDau(pHead, p);
			ThemSinhVienVaoCuoiDanhSach(ds, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH SINH VIEN\n";
			XuatDanhSachSv(ds);
			system("pause");
		}
		else if (luachon == 3)
		{
			Xoa_Dau_Danh_Sach(ds);
		}
		else if (luachon == 4)
		{
			Xoa_Cuoi_Danh_Sach(ds);
		}
		else if (luachon == 5)
		{
			char mssv[10];
			cout << "nhap ma sinh vien can tim" << endl;
			gets_s(mssv);
			SINHVIEN sv;
			if (Kiem_tra_ton_tai(ds, mssv) == true) {
				sv = Lay_Thong_Tin_Sinh_Vien_Theo_Ma(ds, mssv);
				Xuat_Thong_tin_1sv(sv);
			}
			else {
				cout << "không tìm thấy sinh viên";
			}


		}
		/*	else if (luachon == 5)
			{
				SINHVIEN sv;
				cout << "\nNhap gia tri phan so cho NODE K can them: ";
				Nhap_thong_tin_1sv(sv);
				PHANSO y;
				cout << "\nNhap gia tri phan so cho NODE q can kiem tra: ";
				Nhap_Phan_So(y);
				NODE* q = KhoiTaoNode(y);
				NodeSinhVien *sv=  KhoiTaoNodeSinhVien()
				Them_Node_k_Sau_Node_q_Trong_Danh_Sach(pHead, x, q);
			}
			else if (luachon == 6)
			{
				PHANSO y;
				cout << "\nNhap gia tri phan so cho NODE q can kiem tra: ";
				Nhap_Phan_So(y);
				NODE* q = KhoiTaoNode(y);
				Xoa_Node_Sau_Node_q_Trong_Danh_Sach(pHead, q);
			}
	*/
		else
		{
			break;
		}
	}
}