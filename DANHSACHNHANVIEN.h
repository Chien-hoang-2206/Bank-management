#ifndef DANHSACHNHANVIEN_H
#define DANHSACHNHANVIEN_H
#include<iostream>
#include <unistd.h>
#include<iomanip>
#include<string>
#include<fstream>
#include "LIST.h"
#include "NHANVIEN.h"
// #include "LOPTRUNGGIAN.h"
using namespace std;
class DANHSACHNHANVIEN
{
protected:
    LIST<NHANVIEN> ds_nhan_vien;
public:
    void cai_dat_danh_sach();
    void in_thong_tin();
    NHANVIEN tim_kiem_danh_sach(NHANVIEN &nv);
};
void Doc_thong_tin_1_NV(ifstream &filein, NHANVIEN &nv){
    string temp;
    filein >> nv.id_nhan_vien;
    filein.ignore(1);
    getline(filein,nv.ho_ten, ',');
    filein.ignore(1);
    filein >>nv.tuoi;
    filein.ignore(1);
    getline(filein,nv.sdt, ',');
    filein.ignore(1);
    getline(filein,nv.dia_chi, ',');
    filein.ignore(1);
    getline(filein,temp, ',');
    filein.ignore(1);
    getline(filein,temp);
}
void DANHSACHNHANVIEN::cai_dat_danh_sach(){
    ifstream filein;
    filein.open("NHANVIEN.txt",ios::in);
    filein >> ds_nhan_vien.so_phan_tu;
    filein.ignore(1);
    while( !filein.eof())
    {
        NHANVIEN nv;
        Doc_thong_tin_1_NV(filein,nv);
        ds_nhan_vien.add_tail(nv);
    }
    filein.close();
}
NHANVIEN DANHSACHNHANVIEN::tim_kiem_danh_sach(NHANVIEN &nv){
    NHANVIEN  a;
    a = ds_nhan_vien.timkiem(nv);
    return a;
}
void DANHSACHNHANVIEN::in_thong_tin(){
    cout << this->ds_nhan_vien;
}
#endif