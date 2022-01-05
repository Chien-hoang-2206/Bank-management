#ifndef DANHSACHVIDIENTU_H
#define DANHSACHVIDIENTU_H
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include "LIST.h"
#include "VIDIENTU.h"
#include "ATM.h"
using namespace std;
class DANHSACHVIDIENTU
{
protected:
    LIST<VIDIENTU> DS_vi_dien_tu;
public:
    void cai_dat_danh_sach();
    int kiem_tra_the_ATM(string tai_khoan, string mat_khau);
    int kiem_tra_the_ATM(int id);
    ATM lay_thong_tin_the_ATM(string tai_khoan, string mat_khau);
};
void Doc_thong_tin_1_KH(ifstream &filein, KHACHHANG &kh){
    string ma,mk;
    int du;
    filein >> kh.id_khach_hang;
    filein.ignore(1);
    getline(filein,kh.ho_ten, ',');
    filein.ignore(1);
    filein >>kh.tuoi;
    filein.ignore(1);
    getline(filein,kh.sdt, ',');
    filein.ignore(1);
    getline(filein,kh.dia_chi, ',');
    filein.ignore(1);
    getline(filein,ma, ',');
    filein.ignore(1);
    getline(filein,mk, ',');
    filein.ignore(1);
    filein>>du;
    kh.atm.cai_dat_the(ma,mk,du,kh.id_khach_hang);
}
void DANHSACHVIDIENTU::cai_dat_danh_sach(){
    ifstream filein;
    filein.open("VIDIENTU.txt",ios::in);
    filein >> DS_vi_dien_tu.so_phan_tu;
    filein.ignore(1);
    while( !filein.eof())
    {
        VIDIENTU vi;
        Doc_thong_tin_1_VI(filein,vi);
        DS_vi_dien_tu.add_tail(vi);
    }
    filein.close();
    cout << DS_vi_dien_tu;
}
int DANHSACHVIDIENTU::kiem_tra_the_ATM(string tai_khoan, string mat_khau){

    return DS_vi_dien_tu.tim_kiem_atm(tai_khoan,mat_khau);
}
int DANHSACHVIDIENTU::kiem_tra_the_ATM(int id){
    return DS_vi_dien_tu.tim_kiem_atm()
}
ATM DANHSACHVIDIENTU::lay_thong_tin_the_ATM(string tai_khoan, string mat_khau){
    // ATM *p;
    // if (kiem_tra_the_ATM(tai_khoan,mat_khau))
    // {
        
    // }
    // else 
}
#endif