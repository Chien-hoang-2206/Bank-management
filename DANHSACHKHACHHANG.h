#ifndef DANHSACHTAIKHOANKHACHHANG_H
#define DANHSACHTAIKHOANKHACHHANG_H
#include<iostream>
#include <unistd.h>
#include<iomanip>
#include<string>
#include<fstream>
#include "LIST.h"
#include "KHACHHANG.h"
#include "ATM.h"
using namespace std;
class DANHSACHKHACHHANG
{
protected:
    LIST<KHACHHANG> DS_KHACH_HANG;
public:
    DANHSACHKHACHHANG();
    void cai_dat_danh_sach();
    void them_moi_vao_danh_sach();
    void doi_thong_tin(KHACHHANG &kh);
    KHACHHANG operator [](int x );
    int kiem_tra_the_ATM(string tai_khoan, string mat_khau);
    ATM kiem_tra_the_ATM(int id);
    void in_ra_danh_sach_khach_hang();
    void ghi_ra_file_danh_sach();
    // ATM lay_thong_tin_the_ATM(string tai_khoan, string mat_khau);
};
DANHSACHKHACHHANG::DANHSACHKHACHHANG(){
    this->cai_dat_danh_sach();
}
void DANHSACHKHACHHANG::cai_dat_danh_sach(){
    ifstream filein;
    filein.open("KHACHHANG.txt",ios::in);
    filein >> DS_KHACH_HANG.so_phan_tu;
    filein.ignore(1);
    while( !filein.eof())
    {
        KHACHHANG kh;
        Doc_thong_tin_1_KH(filein,kh);
        DS_KHACH_HANG.add_tail(kh);
    }
    filein.close();
}
void DANHSACHKHACHHANG::doi_thong_tin(KHACHHANG &kh){
    kh.doi_thong_tin();
}
int DANHSACHKHACHHANG::kiem_tra_the_ATM(string tai_khoan, string mat_khau){

    return DS_KHACH_HANG.tim_kiem_atm(tai_khoan,mat_khau);
}
// int DANHSACHKHACHHANG::kiem_tra_the_ATM(int id){
//     return DS_KHACH_HANG.tim_kiem_atm(id);
// }

// ATM DANHSACHKHACHHANG::lay_thong_tin_the_ATM(string tai_khoan, string mat_khau){
//     // ATM *p;
//     // if (kiem_tra_the_ATM(tai_khoan,mat_khau))
//     // {
//     // }
//     // else 
// }

void DANHSACHKHACHHANG::in_ra_danh_sach_khach_hang(){
    cout << this->DS_KHACH_HANG;
}
void DANHSACHKHACHHANG::them_moi_vao_danh_sach(){
    KHACHHANG new_kh;
    new_kh.cai_dat_thong_tin();  
    this->DS_KHACH_HANG.add_tail(new_kh); 
    this->DS_KHACH_HANG.ghi_ra_file_danh_sach("KHACHHANG.txt");
}
KHACHHANG DANHSACHKHACHHANG::operator[](int x ){
    return DS_KHACH_HANG[x];
}
void DANHSACHKHACHHANG::ghi_ra_file_danh_sach(){
    DS_KHACH_HANG.ghi_ra_file_danh_sach("KHACHHANG.txt");
}
#endif