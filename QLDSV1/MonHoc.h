#pragma once
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

struct monhoc
{
	string MaMH;
	string TenMH;
	int stclt;
	int stcth;
};
typedef struct monhoc MONHOC;
void Nhap_thong_tin_1mh(MONHOC& );
void Doc_thong_tin_1mh(ifstream,MONHOC);
void Xuat_thong_tin_1mh(MONHOC );