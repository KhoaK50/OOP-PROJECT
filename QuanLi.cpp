#include "QuanLi.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


QuanLi::QuanLi()
    : NhanVien("", "", "", ""),
      LuongCoBan(0.0),
      LuongTrachNhiem(0.0),
      HeSoHieuSuat(0.0)
{}

QuanLi::QuanLi(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi,
               double _LuongCoBan, double _LuongTrachNhiem, double _HeSoHieuSuat)
    : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi)
{
    LuongCoBan = _LuongCoBan;
    LuongTrachNhiem = _LuongTrachNhiem;
    HeSoHieuSuat = _HeSoHieuSuat;
}

QuanLi::QuanLi(const QuanLi& nv)
    : NhanVien(nv)
{
    LuongCoBan = nv.LuongCoBan;
    LuongTrachNhiem = nv.LuongTrachNhiem;
    HeSoHieuSuat = nv.HeSoHieuSuat;
}

QuanLi::~QuanLi() {}

double QuanLi::getLuongCoBan() const { return LuongCoBan; }
double QuanLi::getLuongTrachNhiem() const { return LuongTrachNhiem; }
double QuanLi::getHeSoHieuSuat() const { return HeSoHieuSuat; }

void QuanLi::setLuongCoBan(double x) { LuongCoBan = x; }
void QuanLi::setLuongTrachNhiem(double x) { LuongTrachNhiem = x; }
void QuanLi::setHeSoHieuSuat(double x) { HeSoHieuSuat = x; }


double QuanLi::TinhLuong() const
{
    return LuongCoBan + LuongTrachNhiem + (LuongCoBan * HeSoHieuSuat);
}

void QuanLi::HienThiThongTin() const {
    cout << left << setw(10) << getMaNV()
         << setw(20) << getHoTen()
         << setw(12) << getNgaySinh()
         << setw(18) << getDiaChi()
         << setw(12) << fixed << setprecision(2) << LuongCoBan
         << setw(12) << fixed << setprecision(2) << LuongTrachNhiem
         << setw(10) << fixed << setprecision(2) << HeSoHieuSuat
         << setw(12) << fixed << setprecision(2) << TinhLuong()
         << endl;
}

istream& operator>>(istream& in, QuanLi& nv) {
    cout << "Nhap ma NV: ";
    getline(in, nv.MaNV);

    cout << "Nhap ho ten: ";
    getline(in, nv.HoTen);

    cout << "Nhap ngay sinh: ";
    getline(in, nv.NgaySinh);

    cout << "Nhap dia chi: ";
    getline(in, nv.DiaChi);

    cout << "Nhap luong co ban: ";
    in >> nv.LuongCoBan;

    cout << "Nhap luong trach nhiem: ";
    in >> nv.LuongTrachNhiem;

    cout << "Nhap he so hieu suat: ";
    in >> nv.HeSoHieuSuat;

    in.ignore();
    return in;
}


ostream& operator<<(ostream& out, const QuanLi& nv) {
    out << "[QuanLi] " << nv.getMaNV() << " - " << nv.getHoTen()
        << " | LuongCoBan: " << nv.LuongCoBan
        << " | LuongTrachNhiem: " << nv.LuongTrachNhiem
        << " | HeSoHieuSuat: " << nv.HeSoHieuSuat
        << " | Luong: " << fixed << setprecision(2) << nv.TinhLuong();

    return out;
}
