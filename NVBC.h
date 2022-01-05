#ifndef NVBC_H
#define NVBC_H
#include "NHANVIEN.h"
using namespace std;
class NVBC : public NHANVIEN
{
protected:
    double he_so_luong;
    double tham_niem_lam_viec;
public:
    NVBC():NHANVIEN::NHANVIEN(), he_so_luong(2.34), tham_niem_lam_viec(0.0) {}
    virtual void SET_NV();
    virtual void Dislay() const;
};
void NVBC::SET_NV()
{
    NHANVIEN::SET_NV();
    do
    {
        cout << " Nhap he so luong: ";
        cin >> he_so_luong;
    } while (he_so_luong < 2.34 || he_so_luong > 10);
    if (nam_lam_viec < 5)   tham_niem_lam_viec = 0;
    else  tham_niem_lam_viec = ( nam_lam_viec / 100);
    luong = (he_so_luong*1390000)*(1+tham_niem_lam_viec);
}
void NVBC::Dislay() const{
    NHANVIEN::Dislay();
    cout << setw(60) << he_so_luong << setw(20) << tham_niem_lam_viec << setw(23) << luong << endl;
}
#endif
