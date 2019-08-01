#include"DanhSachMonHoc.h"

void Khoi_Tao_Cay(TREE& t) {
	t = NULL;

}
void Them_Node_Vao_Cay(TREE& t, MONHOC mh) {

	if (t == NULL)
	{
		NODEMONHOC* p = new NODEMONHOC;
		p->data = mh;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{

		if (mh.MaMH < t->data.MaMH)
		{
			Them_Node_Vao_Cay(t->pLeft, mh);
		}
		else if (mh.MaMH > t->data.MaMH)
		{
			Them_Node_Vao_Cay(t->pRight, mh);
		}
	}
}

void insertMonHoc(DannhSachMonHoc& ds, MONHOC mh) {

}

void Duyet_NLR(TREE t) {
	if (t != NULL)
	{
		Xuat_thong_tin_1mh(t->data); // xuất dữ liệu trong struct data ra ngoài


		Duyet_NLR(t->pLeft);
		Duyet_NLR(t->pRight);
	}
}
void Xuat_tang_dan_theo_ten(TREE t, DannhSachMonHoc& ds)
{
	Xuat_thong_tin_1mh(t->data); // xuất dữ liệu trong struct data ra ngoài
	Xuat_tang_dan_theo_ten(t->pLeft, ds);
	Xuat_tang_dan_theo_ten(t->pRight, ds);
}

void Tim_Node_The_Mang_Cho_Node_Bi_Xoa_1(NODEMONHOC*& del, NODEMONHOC*& Y) { //del la not xoa , y là not thay the
	// CÁCH 1: TÌM NODE TRÁI NHẤT CỦA CÂY CON PHẢI
	// duyệt sang bên trái nhất
	if (Y->pLeft != NULL)
	{
		Tim_Node_The_Mang_Cho_Node_Bi_Xoa_1(del, Y->pLeft);// tìm ra node trái nhất ?
	}
	else // tìm ra được node trái nhất rồi nek..
	{
		del->data = Y->data; // cập nhật cái data của node cần xóa chính là data của node thế mạng
		del = Y; // cho node X(là node mà chúng ta sẽ đi xóa sau này) trỏ đến node thế mạng ==> ra khỏi hàm thì ta sẽ xóa node X
		Y = Y->pRight; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) với node con của node thế mạng	
	}
}
void XoaNode(TREE& t, string maMH) {
	// nếu như cây đang rỗng
	if (t == NULL)
	{
		return; // kết thúc hàm
	}
	else
	{
		// nếu như data nhỏ hơn node gốc
		if (t->data.MaMH > maMH)
		{
			XoaNode(t->pLeft, maMH); // duyệt sang nhánh trái của cây 
		}
		else if (t->data.MaMH < maMH)
		{
			XoaNode(t->pRight, maMH); // duyệt sang nhánh phải của cây 
		}
		else // data == t->data - đã tìm ra cái node cần xóa
		{
			NODEMONHOC* X = t; // node X là node thế mạng -sẽ xóa
			// nếu như nhánh trái bằng NULL <=> đây là cây có 1 con chính là con phải
			if (t->pLeft == NULL)
			{
				// duyệt sang phải của cái node cần xóa để cập nhật mối liên kết giữa node 
				// cha của node cần xóa với node con của node cần xóa
				t = t->pRight;
			}
			else if (t->pRight == NULL)
			{
				// duyệt sang trái của cái node cần xóa để cập nhật mối liên kết giữa node 
				// cha của node cần xóa với node con của node cần xóa
				t = t->pLeft;
			}
			else // node cần xóa là node có 2 con
			{
				// CÁCH 1: Tìm node trái nhất của cây con phải(cây con phải của cái node cần xóa)
				Tim_Node_The_Mang_Cho_Node_Bi_Xoa_1(X, t->pRight);
				// CÁCH 2: Tìm node phải nhất của cây con trái(cây con trái của cái node cần xóa)
				//DiTimNodeTheMang(X, t->pLeft);
			}
			delete X; // xóa node cần xóa
		}
	}
}
void Menu(TREE& t) {
	int luachon;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============ MENU ============";
		cout << "\n1. Nhap phan tu";
		cout << "\n2. Duyet cay";
		cout << "\n3. Tim kiem phan tu trong cay";
		cout << "\n4. Node co 2 con";
		cout << "\n5. Node co 1 con";
		cout << "\n6. Node la";
		cout << "\n7. Tim Max";
		cout << "\n8. Xoa";
		cout << "\n0. Thoat";
		cout << "\n\n\t\t =============  END  =============";

		cout << "\nNhap lua chon: ";
		cin >> luachon;

		if (luachon == 1)
		{
			MONHOC mh;
			cout << "\nNHAP THONG TIN MON HOC CAN THEM ";
			Nhap_thong_tin_1mh(mh);
			Them_Node_Vao_Cay(t, mh);
		}
		else if (luachon == 2)
		{
			cout << "\n\t CAY NHI PHAN TIM KIEM\n";
			//Duyet_NLR(t);
			system("pause");
		}
		/*else if (luachon == 3)
		{*/
		//			int x;
		//			cout << "\nNhap phan tu can tim kiem: ";
		//			cin >> x;
		//			NODE *p = TimKiem(t, x);
		//			if (p == NULL)
		//			{
		//				cout << "\nPhan tu " << x << " khong ton tai trong cay";
		//			}
		//			else
		//			{
		//				cout << "\nPhan tu " << x << " co ton tai trong cay";
		//			}
		//			system("pause");
		//		}
		//		else if (luachon == 4)
		//		{
		//			cout << "\n\t NODE CO 2 CON: ";
		//			Node_Co_2_Con(t);
		//			system("pause");
		//		}
		//		else if (luachon == 5)
		//		{
		//			cout << "\n\t NODE CO 1 CON: ";
		//			Node_Co_1_Con(t);
		//			system("pause");
		//		}
		//		else if (luachon == 6)
		//		{
		//			cout << "\n\t NODE LA: ";
		//			Node_La(t);
		//			system("pause");
		//		}
		//		else if (luachon == 7)
		//		{
		//			// CÁCH 1:
		//			/*TimMax(t);
		//			cout << "\nMAX: " << MAX;*/
		//
		//			// CÁCH 2:
		//			cout << "\nMAX: " << TimMax(t);
		//			system("pause");
		//		}
		//		else if (luachon == 8)
		//		{
		//			int x;
		//			cout << "\nNhap gia tri can xoa: ";
		//			cin >> x;
		//			XoaNode(t, x):
	/*}*/
		else
		{
			break;
		}
	}
}
