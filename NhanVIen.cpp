#include "NhanVien.h"
#include <bits/stdc++.h>
using namespace std;

//  Constructor 
NhanVien::NhanVien(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi) {
    MaNV = _MaNV;
    HoTen = _HoTen;
    NgaySinh = _NgaySinh;
    DiaChi = _DiaChi;
}

//  Getter - Setter
string NhanVien::getMaNV() const{return MaNV;}
string NhanVien::getHoTen() const{return HoTen;}
string NhanVien::getNgaySinh() const{return NgaySinh;}
string NhanVien::getDiaChi() const{return DiaChi;}

void NhanVien::setMaNV(string v){MaNV = v;}
void NhanVien::setHoTen(string v){HoTen = v;}
void NhanVien::setNgaySinh(string v){NgaySinh = v;}
void NhanVien::setDiaChi(string v){DiaChi = v;}

//  Phương thức ảo 
void NhanVien::HienThiThongTin() const{
    cout<<"Ma NV: "<<MaNV<<endl;
    cout<<"Ho ten: "<<HoTen<<endl;
    cout<<"Ngay sinh: "<<NgaySinh<<endl;
    cout<<"Dia chi: "<<DiaChi<<endl;
}

//  Quá tải nhập xuất 
istream& operator>>(istream& in, NhanVien& nv){
    cout<<"Nhap ma NV: ";
    getline(in , nv.MaNV);
    cout<<"Nhap ho ten: ";
    getline(in, nv.HoTen);
    cout<<"Nhap ngay sinh: ";
    getline(in, nv.NgaySinh);
    cout<<"Nhap dia chi: ";
    getline(in, nv.DiaChi);
    return in;
}

ostream& operator<<(ostream& out, const NhanVien& nv) {
    out<<"Ma NV: "<<nv.MaNV<<endl;
    out<<"Ho ten: "<<nv.HoTen<<endl;
    out<<"Ngay sinh: "<<nv.NgaySinh<<endl;
    out<<"Dia chi: "<<nv.DiaChi<<endl;
    return out;
}
