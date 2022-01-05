#ifndef THONGTINCANHAN_H
#define THONGTINCANHAN_H
#include <iostream>
using namespace std;
#include <string>
#include <iostream>
#include <iomanip>
class NHANVIEN;
class THONGTINCANHAN
{
protected:
    string ho_ten;
    int tuoi;
    string sdt;
    string dia_chi;
public:
    THONGTINCANHAN();
    ~THONGTINCANHAN();
    THONGTINCANHAN(const THONGTINCANHAN &a);
    virtual void cai_dat_thong_tin();
    virtual void doi_thong_tin();
    virtual void in_thong_tin() const;
    friend void Doc_thong_tin_1_NV(ifstream &filein, NHANVIEN &nv);
};
THONGTINCANHAN::THONGTINCANHAN()
{
    ho_ten = "aaaaaaaaa";
    tuoi = 0;
    sdt = "0123456789";
    dia_chi = "trong";
}
THONGTINCANHAN::~THONGTINCANHAN(){
    ho_ten = "aaaaaaaaa";
    tuoi = 0;
    sdt = "0123456789";
    dia_chi = "trong";   
}
THONGTINCANHAN::THONGTINCANHAN(const THONGTINCANHAN &a)
{
    ho_ten = a.ho_ten;
    tuoi = a.tuoi;
    sdt = a.sdt;
    dia_chi = a.dia_chi;
}
void THONGTINCANHAN::cai_dat_thong_tin()
{
    cout << " Nhap ho ten : ";  fflush(stdin);  getline(cin,ho_ten);
    cout << " Nhap tuoi: "; cin >> this->tuoi;
    cout << " Nhap sdt: ";    fflush(stdin); getline(cin,sdt);
    cout << " Nhap dia chi: ";    fflush(stdin); getline(cin,dia_chi);
}
void THONGTINCANHAN::doi_thong_tin()
{
    int chose;
    do
    {
        cout << "Sua chua thong tin: " << endl;
        cout << "Tuy chon: 0(Thoat) - 1 (Sua ten) - 2(Sua tuoi) -  3(Sua sdt)  2(Sua dia chi)" << endl;
        cin >> chose;
        if (chose == 1)
        {
            cout<< "Nhap ten moi: "; cin >> this->ho_ten;
        }
        if (chose == 2)
        {
            cout<< "Nhap tuoi moi: "; cin >> this->tuoi;
        }
        if (chose == 3)
        {
            cout<< "Nhap sdt moi: "; cin >> this->sdt;
        }
        if (chose == 4)
        {
            cout<< "Nhap dia chi moi: "; cin >> this->dia_chi;
        }
    } while (chose != 0);
}
void THONGTINCANHAN::in_thong_tin() const
{
    cout << this->ho_ten << setw(15) << this->tuoi << setw(15) << this->sdt << setw(30) << this->dia_chi;
}
#endif