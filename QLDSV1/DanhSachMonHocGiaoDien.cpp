#include "DanhSachMonHocGiaoDien.h"

void demSLMonHoc(TREE t, int& soluong)
{
	if (t != NULL) {
		soluong++;
		demSLMonHoc(t->pLeft, soluong);
		demSLMonHoc(t->pRight, soluong);
	}
}

void insertOder(MonHocTheoTen& t, MONHOC m)
{
	if (t.soLuong < MAXDSMON) {
		int n = 0;
		while ( n < t.soLuong ){ //chi de tang n neu du dk la tenMh lon hon ten mon hoc cuoi cung
			if (m.TenMH < t.data[n].TenMH) {
				break;
			}
			n++;
		}
		t.soLuong++;
		for (int i = t.soLuong - 1; i > n; i--) {
			t.data[i] = t.data[i - 1];
		}

		t.data[n] = m;
	}
}

void insertAllList(MonHocTheoTen& ds, TREE t)
{
	if (t != NULL) {
		insertOder(ds, t->data);
		insertAllList(ds, t->pLeft);
		insertAllList(ds, t->pRight);
	}
}

/*
void addOder(PointerArray &Arr, int data){
	if(Arr.n < 5){
		int n;

		for(n = 0;n < Arr.n && data >= *Arr.node[n]; n++);
		Arr.n++;
		for(int i = Arr.n - 1; i > n ; i--){
			Arr.node[i] = Arr.node[i - 1];
		}

		Arr.node[n] = new int(data);
	}
}
*/
