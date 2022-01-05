#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <string>
#include <iostream>
#include <iomanip>
#include "THONGTINCANHAN.h"
using namespace std;
class NHANVIEN: public THONGTINCANHAN
{
protected:
    int id_nhan_vien;
public:
    static int sonv;
    NHANVIEN();
    ~NHANVIEN();
    NHANVIEN(const NHANVIEN &a);
    bool  operator ==(NHANVIEN &nv );
    virtual void cai_dat_thong_tin() ;
    virtual void doi_thong_tin();
    virtual void in_thong_tin() const;
    friend void Doc_thong_tin_1_NV(ifstream &filein, NHANVIEN &nv);
};
int NHANVIEN::sonv=0;
NHANVIEN::NHANVIEN():THONGTINCANHAN::THONGTINCANHAN()
{   
    // ofstream fileout;
    id_nhan_vien = this->sonv++ ;
}
NHANVIEN::~NHANVIEN(){
    this->sonv--;
}
bool NHANVIEN::operator ==(NHANVIEN &nv ){
    if (this->ho_ten == nv.ho_ten && this->dia_chi == nv.dia_chi && this->sdt == nv.sdt && this->tuoi == nv.tuoi)
    return true;
    else return false;
}
NHANVIEN::NHANVIEN(const NHANVIEN &a){
    this->id_nhan_vien = a.id_nhan_vien;
    this->ho_ten = a.ho_ten;
    this->tuoi = a.tuoi;
    this->sdt = a.sdt;
    this->dia_chi = a.dia_chi;
}
void NHANVIEN::cai_dat_thong_tin()
{   THONGTINCANHAN::cai_dat_thong_tin();
    // ofstream fileout;
    // fileout.open("NHANVIEN.txt",ios::out);
    // fileout << this->id_nhan_vien << ", ";
    // fileout << this->ho_ten <<", ";
    // fileout << this->tuoi<< ", ";
    // fileout << this->sdt<< ", ";
    // fileout << this->dia_chi ", ";
    // fileout<<endl;
    // fileout.close();
}
void NHANVIEN::doi_thong_tin()
{
    // THONGTINCANHAN::cai_dat_thong_tin();
    // ofstream fileout;
    // fileout.open("NHANVIEN.txt",ios::out);
    // fileout << this->id_nhan_vien << ", ";
    // fileout << this->ho_ten <<", ";
    // fileout << this->tuoi<< ", ";
    // fileout << this->sdt<< ", ";
    // fileout << this->dia_chi ", ";
    // fileout<<endl;
    // fileout.close();   
}
void NHANVIEN::in_thong_tin() const
{
    cout << this->id_nhan_vien << setw(25) ;
    THONGTINCANHAN::in_thong_tin();
}
#endif