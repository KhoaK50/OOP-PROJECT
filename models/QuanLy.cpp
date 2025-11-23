#include "QuanLy.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;


QuanLy::QuanLy()
    : NhanVien("", "", "", ""),
      LuongCoBan(0.0),
      LuongTrachNhiem(0.0),
      HeSoHieuSuat(0.0) {}

QuanLy::QuanLy(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi,
               double _LuongCoBan, double _LuongTrachNhiem, double _HeSoHieuSuat)
    : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi),
      LuongCoBan(_LuongCoBan),
      LuongTrachNhiem(_LuongTrachNhiem),
      HeSoHieuSuat(_HeSoHieuSuat) {}

QuanLy::QuanLy(const QuanLy& nv)
    : NhanVien(nv),
      LuongCoBan(nv.LuongCoBan),
      LuongTrachNhiem(nv.LuongTrachNhiem),
      HeSoHieuSuat(nv.HeSoHieuSuat) {}

QuanLy::~QuanLy() {}


double QuanLy::getLuongCoBan() const        { return LuongCoBan; }
double QuanLy::getLuongTrachNhiem() const   { return LuongTrachNhiem; }
double QuanLy::getHeSoHieuSuat() const      { return HeSoHieuSuat; }

void QuanLy::setLuongCoBan(double x)        { LuongCoBan = x; }
void QuanLy::setLuongTrachNhiem(double x)   { LuongTrachNhiem = x; }
void QuanLy::setHeSoHieuSuat(double x)      { HeSoHieuSuat = x; }


double QuanLy::TinhLuong() const {
    return LuongCoBan + LuongTrachNhiem + (LuongCoBan * HeSoHieuSuat);
}


void QuanLy::HienThiThongTin() const {
    cout << left
         << "|" << setw(20)  << getMaNV()
         << "|" << setw(30) << getHoTen()
         << "|" << setw(20) << fixed << setprecision(3) << LuongCoBan
         << "|" << setw(25) << fixed << setprecision(3) << LuongTrachNhiem
         << "|" << setw(25)  << fixed << setprecision(3) << HeSoHieuSuat
         << "|" << setw(25) << fixed << setprecision(3) << TinhLuong() << "\n";
}


istream& operator>>(istream& in, QuanLy& nv) {
    string ma, ten, ngay, dia;
    double coban, trachnhiem, hieusuat;

    cout << "Nhập mã nhân viên      : ";
    getline(in >> ws, ma);
    cout << "Nhập họ tên            : ";
    getline(in, ten);
    cout << "Nhập DD/MM/YYYY        : ";
    getline(in, ngay);
    cout << "Nhập địa chỉ           : ";
    getline(in, dia);
    cout << "Nhập lương cơ bản      : ";
    in >> coban;
    cout << "Nhập lương trách nhiệm : ";
    in >> trachnhiem;
    cout << "Nhập hệ số hiệu suất   : ";
    in >> hieusuat;

    nv.setMaNV(ma);
    nv.setHoTen(ten);
    nv.setNgaySinh(ngay);
    nv.setDiaChi(dia);
    nv.setLuongCoBan(coban);
    nv.setLuongTrachNhiem(trachnhiem);
    nv.setHeSoHieuSuat(hieusuat);
    

    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

ostream& operator<<(ostream& out, const QuanLy& nv) {
    out << left
        << "|" << setw(20)  << nv.getMaNV()
        << "|" << setw(30) << nv.getHoTen()
        << "|" << setw(15) << nv.getNgaySinh()
        << "|" << setw(30) << nv.getDiaChi() << "\n";
    return out;
}
