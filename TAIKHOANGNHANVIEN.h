#ifndef TAIKHOANNHANVIEN_H
#define TAIKHOANNHANVIEN_H
#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
#include "NHANVIEN.h"
#include "TAIKHOAN.h"
using namespace std;
class TAIKHOANNHANVIEN:public TAIKHOAN,public NHANVIEN
{
private:

public:
    NHANVIEN lay_thong_tin_nhan_vien(NHANVIEN &);
    TAIKHOANNHANVIEN();
    void cai_dat_thong_tin();
    void in_thong_tin();
    bool operator ==(TAIKHOANNHANVIEN &x);
    friend void Doc_thong_tin_1_TK_NV(ifstream &filein, TAIKHOANNHANVIEN &tk_nv);
};
TAIKHOANNHANVIEN::TAIKHOANNHANVIEN(){
    NHANVIEN();
    this->ten_dang_nhap = "KO TON TAI";
    this->mat_khau = "KO TON TAI";
}
NHANVIEN TAIKHOANNHANVIEN::lay_thong_tin_nhan_vien(NHANVIEN &nv){
    return nv;
}
void TAIKHOANNHANVIEN::cai_dat_thong_tin(){
    NHANVIEN();
    NHANVIEN::cai_dat_thong_tin();
    cout << "nhap ten dang nhap: "; cin>> this->ten_dang_nhap;
    cout << "nhap mat khau: "; cin>> this->mat_khau;
}
void TAIKHOANNHANVIEN::in_thong_tin(){
    NHANVIEN::in_thong_tin();
    cout << setw(20) << this->ten_dang_nhap << setw(20) << this->mat_khau;
}
bool TAIKHOANNHANVIEN::operator== (TAIKHOANNHANVIEN &x){
    if (this->ten_dang_nhap == x.ten_dang_nhap && this->sdt == x.sdt )
        return true;
    else
        return false;
}
#endif