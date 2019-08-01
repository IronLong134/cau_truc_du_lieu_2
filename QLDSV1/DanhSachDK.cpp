#include"DanhSachDK.h"

void KhoiTaoDanhSachDangKi(DanhSachDangKi& ds) {
	ds.pHead = NULL;
	ds.pTail = NULL;
}
NodeDangKi* KhoiTaoNodeDangKi(DANGKI dk)
{
	NodeDangKi* p = new NodeDangKi;
	if (p == NULL)
	{
		return NULL;
	}

	p->data = dk;
	p->pNext = NULL;
	return p;
}
void XuatDanhSachDangKi(DanhSachDangKi ds) {
	for (NodeDangKi* dk = ds.pHead; dk != NULL; dk = dk->pNext)
	{
		Xuat_tt_1suat_dk(dk->data);
	}
}
void ThemVaoDauDanhSach(DanhSachDangKi& ds, NodeDangKi* ins)
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
void ThemVaoCuoiDanhSach(DanhSachDangKi& ds, NodeDangKi* ins)
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
void Xoa_Dau_Danh_Sach_DK(DanhSachDangKi& ds)
{
	// danh sách đang rỗng
	if (ds.pHead == NULL)
	{
		return;
	}
	NodeDangKi* del = ds.pHead; // Cho node del giữ node đầu để tí ta xóa node del cũng chính là xóa node đầu
	ds.pHead = ds.pHead->pNext; // cập nhật lại pHead là thằng kế tiếp
	delete del; // xóa node đầu

	// nếu sau khi xóa mà pHead đang trỏ đến NULL thì pTail cũng trỏ đến NULL
	if (ds.pHead == NULL)
	{
		ds.pTail = NULL;
	}
}

// hàm xóa 1 node cuối danh sách 
void Xoa_Cuoi_Danh_Sach_DK(DanhSachDangKi& ds)
{
	// nếu danh sách đang rỗng
	if (ds.pHead == NULL)
	{
		return;
	}
	// duyệt tìm node cuối bằng cách dùng node kế cuối trỏ đến cuối
	for (NodeDangKi* prev = ds.pHead; prev != NULL; prev = prev->pNext)
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
bool Kiem_tra_ton_tai_Dk(DanhSachDangKi ds, string masv)
{

	for (NodeDangKi* run = ds.pHead; run != NULL; run = run->pNext)
	{
		// mã sinh viên tồn tại
		if (run->data.MaSV == masv)
		{
			return true;
		}
	}
	return false;
}
DANGKI Lay_Thong_Tin_Dang_Ki_Theo_Ma(DanhSachDangKi ds, char* masv)
{

	for (NodeDangKi* run = ds.pHead; run != NULL; run = run->pNext)
	{
		// mã sinh viên tồn tại
		if (run->data.MaSV == masv)
		{
			DANGKI dk;
			dk = run->data;
			return dk;
		}
	}
}
void MenuDK(DanhSachDangKi& ds)
{
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ======== QUAN LY DANH SACH DANG KI ========\n";
		cout << "\n1. Nhap sinh vien";
		cout << "\n2. Xuat danh sach sinh vien";
		cout << "\n3. Xoa dau danh sach";
		cout << "\n4. Xoa cuoi danh sach";
		cout << "\n5. tim kiem";
		cout << "\n5. Them NODE k sau NODE q trong danh sach";
		cout << "\n6. Xoa 1 cai NODE sau NODE q trong danh sach";
		cout << "\n0. Ket thuc";
		cout << "\n\n\t\t =================== END  ==================\n";

		int luachon;
		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			DANGKI dk;
			cout << "\n\n\t\t NHAP SINH VIEN\n";
			Nhap_tt_1suat_dk(dk);

			NodeDangKi* p = KhoiTaoNodeDangKi(dk);
			//ThemDau(pHead, p);
			ThemVaoCuoiDanhSach(ds, p);
		}
		else if (luachon == 2)
		{
			cout << "\n\n\t\t DANH SACH SINH VIEN\n";
			XuatDanhSachDangKi(ds);
			system("pause");
		}
		else if (luachon == 3)
		{
			Xoa_Dau_Danh_Sach_DK(ds);
		}
		else if (luachon == 4)
		{
			Xoa_Cuoi_Danh_Sach_DK(ds);
		}
		else if (luachon == 5) {
			cin.ignore();
			char mssv[12];
			cout << "nhap ma sinh vien can tim" << endl;
			gets_s(mssv);
			DANGKI dk;
			if (Kiem_tra_ton_tai_Dk(ds, mssv) == true) {
				dk = Lay_Thong_Tin_Dang_Ki_Theo_Ma(ds, mssv);
				Xuat_tt_1suat_dk(dk);
				system("pause");
			}
			else {
				cout << "Khong tim thay sinh vien";
				system("pause");
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
			cout << "nhap sai " << endl;
		}
	}
}