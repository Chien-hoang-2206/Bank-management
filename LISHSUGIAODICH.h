#ifndef LICHSUGIAODICH_h
#define LICHSUGIAODICH_h
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
class LICHSUGIAODICH
{
protected:
    string noi_dung;
    string ma_the_ATM;
public:
    static int ma_giao_dich;
    LICHSUGIAODICH(string noi_dung, string ma_the);
    void cai_dat_thong_tin();
    void in_thong_tin();
    void xoa_lich_su_giao_dich(string ma_gd);
};
int LICHSUGIAODICH::ma_giao_dich = 00000;
LICHSUGIAODICH::LICHSUGIAODICH(string noi_dung, string ma_the){
    ma_giao_dich++;
    this->noi_dung = noi_dung;
    ma_the_ATM = ma_the;
}
void LICHSUGIAODICH::xoa_lich_su_giao_dich(string ma_gd){
    string ma_the;
    ofstream fileout;    
    fileout.open("LICHSUGIAODICH.txt",ios::out);
}
#endif