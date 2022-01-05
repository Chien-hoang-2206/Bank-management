#ifndef KHACHHANG_H
#define KHACHHANG_H
#include <string>
#include <iostream>
#include <iomanip>
#include "THONGTINCANHAN.h"
#include "ATM.h"
using namespace std;
class KHACHHANG:public THONGTINCANHAN, public ATM
{
protected:
    int id_khach_hang;
    ATM* atm;
public:
    static int so_kh;
    KHACHHANG(string tai_khoan = "tai khoan", string mat_khau = "mat khau");
    ~KHACHHANG();
    KHACHHANG(const KHACHHANG &a);
    bool operator ==(KHACHHANG &x); 
    virtual void cai_dat_thong_tin() ;
    virtual void doi_thong_tin();
    virtual void in_thong_tin() const;
    void xoa_khach_hang();
    friend void Doc_thong_tin_1_KH(ifstream &filein, KHACHHANG &kh);
    friend void Ghi_thong_tin_1_KH(ofstream &fileout, KHACHHANG &kh);
    friend bool tim_kiem_atm(string tai_khoan, string mat_khau);
};
int KHACHHANG::so_kh=1;
KHACHHANG::KHACHHANG(string tai_khoan, string mat_khau):THONGTINCANHAN(),ATM(){
    atm->cai_dat_the(tai_khoan,mat_khau,0,0);
    this->id_khach_hang= so_kh++;
    cout << so_du;
}
KHACHHANG::~KHACHHANG(){
}
KHACHHANG::KHACHHANG(const KHACHHANG &a){
    this->id_khach_hang = a.id_khach_hang;
    this->ho_ten = a.ho_ten;
    this->tuoi = a.tuoi;
    this->sdt = a.sdt;
    this->dia_chi = a.dia_chi;
    this->atm = a.atm;
}
bool KHACHHANG::operator ==(KHACHHANG &x){
    if ( this->atm == x.atm )   
        return true;        
    else 
        return false;
}
void KHACHHANG::cai_dat_thong_tin()
{   THONGTINCANHAN::cai_dat_thong_tin();
    this->id_khach_hang = so_kh++;
    cout << "Nhap ma so the ATM:";
    cin >> this->ma_so_the;
    cout << "Nhap mat khau:";
    cin >> this->mat_khau;
    this->so_du = 0;
    this->atm->cai_dat_the(this->ma_so_the,this->mat_khau,this->so_du,this->id_khach_hang);
}
void KHACHHANG::doi_thong_tin()
{   
    int chose;
    cout <<"Sua thong tin khach hang"<<endl;
    cout <<"Thong tin can sua la:"<<endl;
    cout <<"1(Ho ten) 2(tuoi) 3(Sdt) 4(Dia chi) 0(Thoat)"<<endl;
    cin >> chose;
    switch (chose)
    {
    case 1:
    {   cout << "Nhap ho ten moi cua khach hang:"<<endl;
        string ten;
        cin >> ten;
        this->ho_ten = ten;
        break;
    }
    case 2:
    {
        cout << "Nhap tuoi moi cua khach hang:"<<endl;
        int tuoi;
        cin >> tuoi;
        this->tuoi = tuoi;
        break;
    }
    case 3:
    {
        cout << "Nhap Sdt moi cua khach hang:"<<endl;
        string sdt;
        cin >> sdt;
        this->sdt = sdt;
        break;
    }
    case 4:
    { 
        cout << "Nhap tuoi moi cua khach hang:"<<endl;
        string new_dia_chi;
        cin >> dia_chi;
        this->dia_chi = new_dia_chi;
        break;
    }
    default:
        break;
    }
}
void KHACHHANG::in_thong_tin() const
{
    cout << this->id_khach_hang << setw(15) ;
    THONGTINCANHAN::in_thong_tin();
    cout << setw(20);
    this->atm->in_thong_tin_the();
}
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
    kh.atm->cai_dat_the(ma,mk,du,kh.id_khach_hang);
}
void Ghi_thong_tin_1_KH(ofstream &fileout, KHACHHANG &kh)  
{
    fileout << kh.id_khach_hang << ", ";
    fileout << kh.ho_ten <<", ";
    fileout << kh.sdt<< ", ";
    fileout << kh.tuoi<< ", ";
    fileout << kh.dia_chi << ", ";
    kh.ma_so_the = kh.atm->lay_ma_so_the();
    kh.mat_khau = kh.atm->lay_mat_khau();
    kh.so_du = kh.atm->lay_so_du();
    fileout << kh.ma_so_the<< ",  ";
    fileout << kh.mat_khau << ", ";
    fileout << kh.so_du;
    fileout << endl;
}
#endif