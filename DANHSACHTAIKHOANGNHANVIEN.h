#ifndef DANHSACHTAIKHOANGNHANVIEN_H
#define DANHSACHTAIKHOANGNHANVIEN_H
#include<iostream>
#include <unistd.h>
#include<iomanip>
#include<string>
#include<fstream>
#include "LIST.h"
#include "NHANVIEN.h"
// #include "LOPTRUNGGIAN.h"
#include "TAIKHOANGNHANVIEN.h"
using namespace std;
class DANHSACHTAIKHOANGNHANVIEN
{
protected:
    LIST<TAIKHOANNHANVIEN> ds_tk_nhan_vien;
public:
    void cai_dat_danh_sach();
    void in_danh_sach();
    TAIKHOANNHANVIEN kiem_tra_tai_khoan(TAIKHOANNHANVIEN &x);
    TAIKHOANNHANVIEN su_dung_tai_khoan(TAIKHOANNHANVIEN &x);
};
void Doc_thong_tin_1_TK_NV(ifstream &filein, TAIKHOANNHANVIEN &tk_nv){
    filein >> tk_nv.id_nhan_vien;
    filein.ignore(1);
    getline(filein,tk_nv.ho_ten, ',');
    filein.ignore(1);
    filein >> tk_nv.tuoi;
    filein.ignore(1);
    getline(filein,tk_nv.sdt, ',');
    filein.ignore(1);
    getline(filein,tk_nv.dia_chi, ',');
    filein.ignore(1);
    getline(filein,tk_nv.ten_dang_nhap, ',');
    filein.ignore(1);
    getline(filein,tk_nv.mat_khau);
}
void DANHSACHTAIKHOANGNHANVIEN::cai_dat_danh_sach(){
    ifstream filein;
    filein.open("NHANVIEN.txt",ios::in);
    filein >> ds_tk_nhan_vien.so_phan_tu;
    filein.ignore(1);
    while( !filein.eof())
    {
        TAIKHOANNHANVIEN tk_nv;
        Doc_thong_tin_1_TK_NV(filein,tk_nv);
        ds_tk_nhan_vien.add_tail(tk_nv);
    }
    filein.close();
}
TAIKHOANNHANVIEN DANHSACHTAIKHOANGNHANVIEN::kiem_tra_tai_khoan(TAIKHOANNHANVIEN &x){
    return ds_tk_nhan_vien.timkiem(x);
}
TAIKHOANNHANVIEN DANHSACHTAIKHOANGNHANVIEN::su_dung_tai_khoan(TAIKHOANNHANVIEN &x){
    return ds_tk_nhan_vien.timkiem(x);
}
void DANHSACHTAIKHOANGNHANVIEN::in_danh_sach()
{
    cout << ds_tk_nhan_vien;
}
#endif