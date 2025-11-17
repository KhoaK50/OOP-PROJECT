// QuanLi.cpp
#include "QuanLi.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;


QuanLi::QuanLi()
    : NhanVien("", "", "", ""),
      LuongCoBan(0.0),
      LuongTrachNhiem(0.0),
      HeSoHieuSuat(0.0) {}

QuanLi::QuanLi(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi,
               double _LuongCoBan, double _LuongTrachNhiem, double _HeSoHieuSuat)
    : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi),
      LuongCoBan(_LuongCoBan),
      LuongTrachNhiem(_LuongTrachNhiem),
      HeSoHieuSuat(_HeSoHieuSuat) {}

QuanLi::QuanLi(const QuanLi& nv)
    : NhanVien(nv),
      LuongCoBan(nv.LuongCoBan),
      LuongTrachNhiem(nv.LuongTrachNhiem),
      HeSoHieuSuat(nv.HeSoHieuSuat) {}

QuanLi::~QuanLi() {}


double QuanLi::getLuongCoBan() const        { return LuongCoBan; }
double QuanLi::getLuongTrachNhiem() const   { return LuongTrachNhiem; }
double QuanLi::getHeSoHieuSuat() const      { return HeSoHieuSuat; }

void QuanLi::setLuongCoBan(double x)        { LuongCoBan = x; }
void QuanLi::setLuongTrachNhiem(double x)   { LuongTrachNhiem = x; }
void QuanLi::setHeSoHieuSuat(double x)      { HeSoHieuSuat = x; }


double QuanLi::TinhLuong() const {
    return LuongCoBan + LuongTrachNhiem + (LuongCoBan * HeSoHieuSuat);
}


void QuanLi::HienThiThongTin() const {
    cout << left
         << "|" << setw(20)  << getMaNV()
         << "|" << setw(30) << getHoTen()
         << "|" << setw(20) << fixed << setprecision(3) << LuongCoBan
         << "|" << setw(25) << fixed << setprecision(3) << LuongTrachNhiem
         << "|" << setw(25)  << fixed << setprecision(3) << HeSoHieuSuat
         << "|" << setw(25) << fixed << setprecision(3) << TinhLuong() << "\n";
}


istream& operator>>(istream& in, QuanLi& nv) {
    string ma, ten, ngay, dia;

    cout << "Nhập mã nhân viên      : ";
    getline(in >> ws, ma);
    cout << "Nhập họ tên            : ";
    getline(in, ten);
    cout << "Nhập DD/MM/YYYY        : ";
    getline(in, ngay);
    cout << "Nhập địa chỉ           : ";
    getline(in, dia);

    nv.setMaNV(ma);
    nv.setHoTen(ten);
    nv.setNgaySinh(ngay);
    nv.setDiaChi(dia);

    cout << "Nhập lương cơ bản      : ";
    in >> nv.LuongCoBan;
    cout << "Nhập lương trách nhiệm : ";
    in >> nv.LuongTrachNhiem;
    cout << "Nhập hệ số hiệu suất   : ";
    in >> nv.HeSoHieuSuat;

    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

ostream& operator<<(ostream& out, const QuanLi& nv) {
    out << left
        << "|" << setw(20)  << nv.getMaNV()
        << "|" << setw(30) << nv.getHoTen()
        << "|" << setw(15) << nv.getNgaySinh()
        << "|" << setw(30) << nv.getDiaChi() << "\n";
    return out;
}
