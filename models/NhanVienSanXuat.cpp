#include "NhanVienSanXuat.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;


NhanVienSanXuat::NhanVienSanXuat()
    : NhanVien("", "", "", ""), SoSanPham(0), DonGiaSanPham(0.0) {}

NhanVienSanXuat::NhanVienSanXuat(string _MaNV, string _HoTen, string _NgaySinh,
                                 string _DiaChi, int _SoSP, double _DonGia)
    : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi),
      SoSanPham(_SoSP), DonGiaSanPham(_DonGia) {}

NhanVienSanXuat::NhanVienSanXuat(const NhanVienSanXuat& nv)
    : NhanVien(nv),
      SoSanPham(nv.SoSanPham),
      DonGiaSanPham(nv.DonGiaSanPham) {}

NhanVienSanXuat::~NhanVienSanXuat() {}


int    NhanVienSanXuat::getSoSanPham() const      { return SoSanPham; }
double NhanVienSanXuat::getDonGiaSanPham() const  { return DonGiaSanPham; }

void NhanVienSanXuat::setSoSanPham(int sp)        { SoSanPham = sp; }
void NhanVienSanXuat::setDonGiaSanPham(double dg) { DonGiaSanPham = dg; }


double NhanVienSanXuat::TinhLuong() const {
    return SoSanPham * DonGiaSanPham / 1000.0;
}

void NhanVienSanXuat::HienThiThongTin() const {
    cout << left
         << "|" << setw(20)  << getMaNV()
         << "|" << setw(30) << getHoTen()
         << "|" << setw(20)  << SoSanPham
         << "|" << setw(20)  << fixed << setprecision(0) << DonGiaSanPham
         << "|" << setw(25) << fixed << setprecision(3) << TinhLuong() << "\n";
}


istream& operator>>(istream& in, NhanVienSanXuat& nv) {
    string ma, ten, ngay, dia;
    int soSP;
    double donGia;

    cout << "Nhập mã nhân viên  : ";
    getline(in >> ws, ma);
    cout << "Nhập họ tên        : ";
    getline(in, ten);
    cout << "Nhập DD/MM/YYYY    : ";
    getline(in, ngay);
    cout << "Nhập địa chỉ       : ";
    getline(in, dia);
    cout << "Nhập số sản phẩm         : ";
    in >> soSP;
    cout << "Nhập đơn giá sản phẩm    : ";
    in >> donGia;

    nv.setMaNV(ma);
    nv.setHoTen(ten);
    nv.setNgaySinh(ngay);
    nv.setDiaChi(dia);
    nv.setSoSanPham(soSP);
    nv.setDonGiaSanPham(donGia);

    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

ostream& operator<<(ostream& out, const NhanVienSanXuat& nv) {
    out << left
        << "|" << setw(20)  << nv.getMaNV()
        << "|" << setw(30) << nv.getHoTen()
        << "|" << setw(15) << nv.getNgaySinh()
        << "|" << setw(30) << nv.getDiaChi() << "\n";
    return out;
}
