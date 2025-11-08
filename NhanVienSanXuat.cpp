#include "NhanVienSanXuat.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

NhanVienSanXuat::NhanVienSanXuat()
    : NhanVien("", "", "", ""), SoSanPham(0), DonGiaSanPham(0.0) {}
NhanVienSanXuat::NhanVienSanXuat(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi,
        int _SoSP, double _DonGia) : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi){
           SoSanPham= _SoSP;
           DonGiaSanPham= _DonGia; 
        }
NhanVienSanXuat::NhanVienSanXuat(const NhanVienSanXuat& nv)
    : NhanVien(nv)
{
    SoSanPham = nv.SoSanPham;
    DonGiaSanPham = nv.DonGiaSanPham;
}

NhanVienSanXuat::~NhanVienSanXuat(){}

int NhanVienSanXuat::getSoSanPham() const {return SoSanPham; }
double NhanVienSanXuat::getDonGiaSanPham() const{return DonGiaSanPham; }
void NhanVienSanXuat::setSoSanPham(int sp) {SoSanPham=sp; }
void NhanVienSanXuat::setDonGiaSanPham(double dg) {DonGiaSanPham=dg; }

double NhanVienSanXuat::TinhLuong() const {
    return SoSanPham * DonGiaSanPham;
}

void NhanVienSanXuat::HienThiThongTin() const {
    cout << "[NhanVienSanXuat] "
         << getMaNV() << " - " << getHoTen()
         << " | San pham: " << SoSanPham
         << " | Don gia: " << fixed << setprecision(2) << DonGiaSanPham
         << " | Luong: " << fixed << setprecision(2) << TinhLuong()
         << endl;
}

istream& operator>>(istream& in, NhanVienSanXuat& nv) {
    cout << "Nhap ma NV: ";
    getline(in, nv.MaNV);
    cout << "Nhap ho ten: ";
    getline(in, nv.HoTen);
    cout << "Nhap ngay sinh: ";
    getline(in, nv.NgaySinh);
    cout << "Nhap dia chi: ";
    getline(in, nv.DiaChi);
    cout << "Nhap so san pham: ";
    in >> nv.SoSanPham;
    cout << "Nhap don gia: ";
    in >> nv.DonGiaSanPham;
    in.ignore();
    return in;
}
ostream& operator<<(ostream& out, const NhanVienSanXuat& nv) {
    out << "[NhanVienSanXuat] " << nv.getMaNV() << " - " << nv.getHoTen()
        << " | San pham: " << nv.SoSanPham
        << " | Don gia: " << fixed << setprecision(2) << nv.DonGiaSanPham
        << " | Luong: " << fixed << setprecision(2) << nv.TinhLuong();
    return out;
}
