#ifndef ATM_H
#define ATM_H
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "LISHSUGIAODICH.h"
using namespace std;
class ATM
{
protected:
    string ma_so_the;
    string mat_khau;
    double so_du;
    int id_khach_hang;
 //   LIST<LICHSUGIAODICH> lich_su;
public:
    ATM(string ma = "MA TAI KHOAN", string mk= "mat_khau" ,double du=0,int id =0);
    ATM(const ATM& x);
    double sua_file(double (*phep_toan)(double , double ),double du, double tien );
    void naptien(double so_tien, string noi_dung);
    bool operator ==(ATM &x);
    void in_thong_tin_the()const;
    void chuyen_tien();
    string lay_ma_so_the();
    string lay_mat_khau();
    double lay_so_du();
    void in_lich_su_giao_dichh();
    void cai_dat_the(string ma, string mk, double du, int id);
    void xoa_the_atm();
};
ATM::ATM(string ma, string mk,double du, int id):ma_so_the(ma),mat_khau(mk),so_du(du),id_khach_hang(id){}
ATM::ATM(const ATM& x){
    this->ma_so_the = x.ma_so_the;
    this->mat_khau = x.mat_khau;
    this->so_du = x.so_du; 
    this->id_khach_hang = x.id_khach_hang;
}
bool ATM::operator ==(ATM &x){
    if ( this->ma_so_the == x.ma_so_the && this->mat_khau == x.mat_khau )   
            return true;
    else {
        return false;
    }
}
double cong(double a,double b){
    return a+b;
}
double tru(double a,double b){
    return a-b;
}
double ATM::sua_file(double (*phep_toan)(double , double ),double du, double tien )
{   
    so_du = phep_toan(du,tien);
    // ofstream fileout;
    // fileout.open("KHACHHANG.txt",ios::out);
    // do{
    //     fileout.ignore(1);
    // }while(fileout != id_khach_hang )
    return so_du;
}
void ATM::naptien(double so_tien, string noi_dung ="Nap tien vao the"){
    so_du = (sua_file)(cong,so_du,so_tien);
    LICHSUGIAODICH a(noi_dung,ma_so_the);
}
void ATM::cai_dat_the(string ma, string mk, double du, int id){
    this->ma_so_the = ma;
    this->mat_khau = mk;
    this->so_du = du; 
    this->id_khach_hang = id;
}
void ATM::in_thong_tin_the()const{
    cout << this->ma_so_the << setw(20) << this->mat_khau <<setw(20) << this->so_du ;
}
string ATM::lay_ma_so_the(){
    return this->ma_so_the;
}
string ATM::lay_mat_khau(){
    return this->mat_khau;
}
double ATM::lay_so_du(){
    return this->so_du;
}
#endif