#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "THONGTINCANHAN.h"
#include "KHACHHANG.h"
using namespace std;
template<typename T>
class LIST;
template<typename T>
class node
{
    friend class LIST<T>;
    private:
        T *data;
        node *pre;
        node *next;
    public:  
        node(T);
        template <typename U>
        friend istream &operator >>(istream &in, LIST<U> &a);
        template <typename U>
        friend ostream &operator <<(ostream &out ,LIST<U> &a);        
};
template<typename T>
class LIST 
{
protected:
    node<T> *head, *tail;
public:
    int so_phan_tu;
    LIST():head(NULL),tail(NULL){}
    ~LIST();
    T timkiem(T &x);
    int tim_kiem_atm(string tai_khoan, string mat_khau);
    ATM tim_kiem_atm(int id);
    void add_tail(T );
    void del_node(T );
    void delete_tail();
    void del_list();
    T operator [](int ); 
    void ghi_ra_file_danh_sach(string file_name);
    template <typename U>
    friend istream &operator >>(istream &in, LIST<U> &a);
    template <typename U>
    friend ostream &operator <<(ostream &out ,LIST<U> &a); 
};
template <typename T>
LIST<T>::~LIST(){
    node<T> *p= this->head;
    while ( head != NULL){
        head =  head->next;
        delete [] p ; p = NULL; 
        p = head;
    }
}
template <typename T>
node<T>::node(T data){
    this->data = new T(data);
    this->next = NULL;
    this->pre = NULL;
}
template <typename T>
void LIST<T>::add_tail(T x){
    node<T> *p = new node<T>(x);
    if (head == NULL) {
        head = tail = p;
        }
    else{
        p->pre = tail;
        tail->next = p;
        tail = p; 
    }
}
template<typename T>
void LIST<T>::del_node(T x){
    node<T> *p= head;
    for (p ; p!= NULL; p=p->next)
        if (*p->data == x){
            p->pre->next = p->next;
            delete []p;
            p = NULL;
            return;
        }
}
template <typename T>
void LIST<T>::del_list(){
    node<T> *p= this->head;
    while ( head != NULL){
        head =  head->next;
        delete [] p ; p = NULL; 
        p = head;
    }
}
template <typename T>
T LIST<T>::timkiem(T &x)
{   
    T y;
    node<T> *p= this->head;
    while (p != NULL){
        if (*p->data == x){ return *p->data;}
        else
        {
            p = p->next;
        }
    }
    return y;
}
template <typename T>
int LIST<T>::tim_kiem_atm(string tai_khoan, string mat_khau){
    KHACHHANG x(tai_khoan,mat_khau);
    int i=0;
    node<T> *p= this->head;
    while (p != NULL)
    {   
        i++;
        if (*p->data == x){ return i;}
        else
            p = p->next;
    }
    return -1;
}
template <typename T>
ATM LIST<T>::tim_kiem_atm(int id){
    ATM x;
    int i=0;
    node<T> *p= this->head;
    while (p != NULL)
    {   
        i++;
        if (*p->data == x){ return x;}
        else
            p = p->next;
    }
    return x;
}
template <typename T>
void LIST<T>::ghi_ra_file_danh_sach(string file_name){
    ofstream fileout;
    fileout.open(file_name,ios::out);
    int n = this->so_phan_tu;
    fileout << n;
    fileout<<endl;
    node<T> *p = this->head;
    while (p!= NULL)
    {
        Ghi_thong_tin_1_KH(fileout,*p->data);
        p = p->next;
    }
    fileout.close();
}
template <typename T>
T LIST<T>::operator [](int x )
{
    node<T> *p= this->head;
    int i = 1;
    while (i < this->so_phan_tu){
        if (i == x){ return *p->data;}
        else{
            i++;
            p = p->next;
        }
    }
    return *p->data;
}
template <typename T>
istream &operator >>(istream &in , LIST<T> &a){
    int chose;
    do{
        cout << "Nhap danh sach "<< endl;
        cout << "Tuy chon: 0(Thoat) - 1 (Nhap) - 2(NV bien che)"<<endl;
        cin >> chose;
        if (chose == 1 ){
            T f;
            f.cai_dat_thong_tin();
            a.add_tail(f);
        }
        // if (chose == 1 ){
        //     cout << "--------------------------------------------"<<endl;
        //     node *p = create_node_NVHD();
        //     a.add_tail(p);
        //     cout << "--------------------------------------------"<<endl;
        // }
        // if (chose == 2) {
        //     cout << "--------------------------------------------"<<endl;
        //     node *p = create_node_NVBC();
        //     a.add_tail(p);
        //     cout << "--------------------------------------------"<<endl;
        // }
    }while(chose != 0 );
    return in;
}
template <typename U>
ostream &operator <<(ostream &out , LIST<U> &a){
    cout << "------------------------------------------------------------------"<<endl;
    cout << "                DANH SACH QUAN LI THONg TIN            "<<endl;
    cout << "so phan tu: "<< a.so_phan_tu << endl;
    //cout << " Ma NV" << setw(15) << "Ten NV"<<setw(20)<< "So nam lam viec"<< setw(20) << "Gioi tinh "<< setw(20) << "Luong cong nhat" << setw(20) << "So ngay di lam " << setw(20) << "He so luong "<<setw(20)<< "Tham nien lam viec "<< setw(20)<<"Luong "<< endl; 
    for ( node<U> *p = a.head ; p != NULL ; p = p->next){
       p->data->in_thong_tin();
       cout << endl;
    }
    return out;
}
#endif