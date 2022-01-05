#include <iostream>
#include <string>
#include "LIST.h"
#include "DANHSACHKHACHHANG.h"
#include "KHACHHANG.h"
#include "DANHSACHNHANVIEN.h"
#include "DANHSACHTAIKHOANGNHANVIEN.h"
using namespace std;
void Dang_nhap_tai_khoan_khach_hang()
{
  DANHSACHKHACHHANG ds_khach_hang;
  string T;
  do
  {
    ds_khach_hang.in_ra_danh_sach_khach_hang();
    cout << "------------------------------------------------------------" << endl;
    cout << "Chon mot ma the ATM va mat khau trong danh sach vua in ra de dang nhap" << endl;
    cout << "Giao dien dang nhap" << endl;
    string tk, mk;
    cout << "Ma the ATM:";
    cin >> tk;
    cout << "Mat khau the ATM:";
    cin >> mk;
    if (ds_khach_hang.kiem_tra_the_ATM(tk, mk))
    {
      cout << "DANG NHAP THANH CONG" << endl;
      T = "Cho phep truy cap";
    }
    else
    {
      cout << "Sai ten tai khoan hoac mat khau" << endl;
      T = "Tu choi truy cap";
    }
  } while (T != "Cho phep truy cap");
  cout << "Chao mung ban, xin moi nhap lua chon:";
  cout << "1,Rut tien ATM" << endl;
  cout << "2,Nap tien" << endl;
  cout << "3,Chuyen tien" << endl;
  cout << "4,Xem so du tai khoan" << endl;
  int t;
  cin >> t;
  switch (t)
  {
  case 1:
    break;
  default:
    break;
  }
}
void Giao_dien_nhan_vien()
{
  DANHSACHKHACHHANG ds_khach_hang;
  int c;
  int id;
  do
  {
    cout << "------------------------------------------------------------" << endl;
    cout << "Giao dien nhan vien ngan hang" << endl;
    cout << "1, Xem danh sach khach hang." << endl;
    cout << "2, Tao tai khoan khach hang moi." << endl;
    cout << "3, Sua thong tin khach hang." << endl;
    cout << "0, Quay lai." << endl;
    cout << "------------------------------------------------------------" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
    {
      cout << "------------------------------------------------------------" << endl;
      ds_khach_hang.in_ra_danh_sach_khach_hang();
      cout << "------------------------------------------------------------" << endl;
      break;
    }
    case 2:
    {
      cout << "------------------------------------------------------------" << endl;
      cout << "Nhap khach hang moi:" << endl;
      ds_khach_hang.them_moi_vao_danh_sach();
      cout << "------------------------------------------------------------" << endl;
      break;
    }
    case 3:
      cout << "------------------------------------------------------------" << endl;
      cout << "HAM DANG BI LOI, TIEP TUC SU DUNG CO THE LAM MAT DU LIEU TRONG FILE KHACHHANG.txt" << endl;
      cout << "Nhan 0 de thoat chuc nang nay" << endl;
      cout << "ID khach hang muon chinh sua thong tin:" << endl;
      cin >> id;
      // ds_khach_hang.doi_thong_tin(ds_khach_hang[id]);
      ds_khach_hang.ghi_ra_file_danh_sach();
      cout << "------------------------------------------------------------" << endl;
      break;
    default:
      break;
    }
  } while (c != 0);
}
void Giao_dien_khach_hang()
{
  DANHSACHKHACHHANG ds_khach_hang;
  int c;
  int id;
  do
  {
    cout << "------------------------------------------------------------" << endl;
    cout << " Giao dien khach hang" << endl;
    cout << "1, Dang ki tai khoan moi." << endl;
    cout << "2, Dang nhap vao tai khoan." << endl;
    cout << "------------------------------------------------------------" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
    {
      cout << "------------------------------------------------------------" << endl;
      cout << "Nhap khach hang moi:" << endl;
      ds_khach_hang.them_moi_vao_danh_sach();
      cout << "------------------------------------------------------------" << endl;
      break;
    }
    case 2:
      Dang_nhap_tai_khoan_khach_hang();
      break;
    default:
      break;
    }
  } while (c != 0);
}
void Giao_dien_quan_ly_ngan_hang()
{
  int chose;
  do
  {
    cout << "------------------------------------------------------------" << endl;
    cout << "---------------Giao dien quan ly ngan hang-----------------" << endl;
    cout << "1,In danh sach nhan vien ngan haang" << endl;
    cout << "2,In danh sach nhan vien ngan haang cung tai khoan truy cap" << endl;
    cout << "0, thoat" << endl;
    cin >> chose;
    switch (chose)
    {
    case 1:
    {
      DANHSACHNHANVIEN a;
      a.cai_dat_danh_sach();
      a.in_thong_tin();
      break;
    }
    case 2:
    {
      DANHSACHTAIKHOANGNHANVIEN tai_khoan_nhan_vien;
      tai_khoan_nhan_vien.cai_dat_danh_sach();
      tai_khoan_nhan_vien.in_danh_sach();
      break;
    }
    default:
      break;
    }
  } while (chose != 0);
}
int main()
{
  int chose;
  do
  {
    cout << "------------------------------------------------------------" << endl;
    cout << "---------------Giao dien ung dung ngan hang-----------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "---------------1(Nhan Vien)  -  2(Khach Hang)---------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "---------------          3(Quan ly)         ----------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    cin >> chose;
    switch (chose)
    {
    case 1:
      Giao_dien_nhan_vien();
      break;
    case 2:
      Giao_dien_khach_hang();
      break;
    case 3:
      Giao_dien_quan_ly_ngan_hang();
      break;
    default:
      break;
    }
  } while (chose != 0);
  return 0;
}