#ifndef VIDIENTU_H
#define VIDIENTU_H
#include <iostream>
#include <string>
#include <iostream>
#include "NHANVIEN.h"
#include "TAIKHOAN.h"
#include "LIST.h"
#include "ATM.h"
using namespace std;
class VIDIENTU:public TAIKHOAN
{
protected:
    LIST<ATM> Ds_atm;
    int tong_so_du;
public:
    VIDIENTU(string );
    void nap_tien_vao_vi();
    void rut_tien_khoi_vi();
    void chuyen_tien_den_the();
    void chuyen_tien_den_vi();
    void lien_ket_toi_the_atm();
    void cai_dat_vi();
    void xoa_lien_ket_atm();
    void su_dung_vi();
};
void VIDIENTU::nap_tien_vao_vi()
{
    cout << this->Ds_atm;
    
}
#endif