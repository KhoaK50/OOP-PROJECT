#include "NhanVienVanPhong.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;
NhanVienVanPhong::NhanVienVanPhong()
    : NhanVien("", "", "", ""),
      SoNgayLamViec(0), SoNgayLe(0),
      DonGiaNgay(0.0), PhuCap(0.0),
      GioLamThemNgayThuong(0.0), GioLamThemCuoiTuan(0.0), GioLamThemLeTet(0.0) {}

NhanVienVanPhong::NhanVienVanPhong(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi,
                                   int _SoNgayLamViec, int _SoNgayLe, double _DonGiaNgay,
                                   double _PhuCap, double _GioLamThemNgayThuong, double _GioLamThemCuoiTuan, double _GioLamThemLeTet)
    : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi),
      SoNgayLamViec(_SoNgayLamViec), SoNgayLe(_SoNgayLe),
      DonGiaNgay(_DonGiaNgay), PhuCap(_PhuCap),
      GioLamThemNgayThuong(_GioLamThemNgayThuong), GioLamThemCuoiTuan(_GioLamThemCuoiTuan), GioLamThemLeTet(_GioLamThemLeTet) {}

NhanVienVanPhong::NhanVienVanPhong(const NhanVienVanPhong& nv)
    : NhanVien(nv) {
    SoNgayLamViec = nv.SoNgayLamViec;
    SoNgayLe = nv.SoNgayLe;
    DonGiaNgay = nv.DonGiaNgay;
    PhuCap = nv.PhuCap;
    GioLamThemNgayThuong = nv.GioLamThemNgayThuong;
    GioLamThemCuoiTuan = nv.GioLamThemCuoiTuan;
    GioLamThemLeTet = nv.GioLamThemLeTet;
}

NhanVienVanPhong::~NhanVienVanPhong() {}


int NhanVienVanPhong::getSoNgayLamViec() const { return SoNgayLamViec; }
int NhanVienVanPhong::getSoNgayLe() const { return SoNgayLe; }
double NhanVienVanPhong::getDonGiaNgay() const { return DonGiaNgay; }
double NhanVienVanPhong::getPhuCap() const { return PhuCap; }
double NhanVienVanPhong::getGioLamThemNgayThuong() const { return GioLamThemNgayThuong; }
double NhanVienVanPhong::getGioLamThemCuoiTuan() const { return GioLamThemCuoiTuan; }
double NhanVienVanPhong::getGioLamThemLeTet() const { return GioLamThemLeTet; }


void NhanVienVanPhong::setSoNgayLamViec(int n) { SoNgayLamViec = n; }
void NhanVienVanPhong::setSoNgayLe(int n) { SoNgayLe = n; }
void NhanVienVanPhong::setDonGiaNgay(double g) { DonGiaNgay = g; }
void NhanVienVanPhong::setPhuCap(double p) { PhuCap = p; }
void NhanVienVanPhong::setGioLamThemNgayThuong(double g) { GioLamThemNgayThuong = g; }
void NhanVienVanPhong::setGioLamThemCuoiTuan(double g) { GioLamThemCuoiTuan = g; }
void NhanVienVanPhong::setGioLamThemLeTet(double g) { GioLamThemLeTet = g; }


double NhanVienVanPhong::TinhLuong() const {
    double luongThuong = SoNgayLamViec * DonGiaNgay;//Lương ngày thường 
    double luongLe = SoNgayLe * DonGiaNgay * 3;//Ngày Lễ/Tết *3 

    double luongMotGio = DonGiaNgay / 8.0;//1 ngày làm 8 tiếng
    double luongLamThem = GioLamThemNgayThuong * luongMotGio * 1.5//làm thêm ngày thường *1.5
                   + GioLamThemCuoiTuan * luongMotGio * 2//làm thêm cuối tuần *2
                   + GioLamThemLeTet * luongMotGio * 3;//làm thêm Lễ/Tết *3

    return luongThuong + luongLe + luongLamThem + PhuCap;//Tổng thu nhập
}


void NhanVienVanPhong::HienThiThongTin() const {
    cout << left << setw(10) << getMaNV()
         << setw(20) << getHoTen()
         << setw(12) << getNgaySinh()
         << setw(15) << getDiaChi()
         << setw(8) << SoNgayLamViec
         << setw(8) << SoNgayLe
         << setw(10) << fixed << setprecision(0) << DonGiaNgay
         << setw(10) << fixed << setprecision(0) << PhuCap
         << setw(8) << GioLamThemNgayThuong
         << setw(8) << GioLamThemCuoiTuan
         << setw(8) << GioLamThemLeTet
         << setw(15) << fixed << setprecision(0) << TinhLuong() << " VND"
         << endl;
}

istream& operator>>(istream& in, NhanVienVanPhong& nv) {
    cout << "Nhap ma NV: ";
    getline(in>>ws, nv.MaNV);
    cout << "Nhap ho ten: ";
    getline(in, nv.HoTen);
    cout << "Nhap ngay sinh: ";
    getline(in, nv.NgaySinh);
    cout << "Nhap dia chi: ";
    getline(in, nv.DiaChi);
    cout << "Nhap so ngay lam viec thuong: ";
    in >> nv.SoNgayLamViec;
    cout << "Nhap so ngay lam le/tet: ";
    in >> nv.SoNgayLe;
    cout << "Nhap don gia ngay: ";
    in >> nv.DonGiaNgay;
    cout << "Nhap phu cap: ";
    in >> nv.PhuCap;
    cout << "Nhap gio lam them thuong: ";
    in >> nv. GioLamThemNgayThuong;
    cout << "Nhap gio lam them cuoi tuan: ";
    in >> nv. GioLamThemCuoiTuan;
    cout << "Nhap gio lam them le/tet: ";
    in >> nv. GioLamThemLeTet;
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}

ostream& operator<<(ostream& out, const NhanVienVanPhong& nv) {
    out << "[NhanVienVanPhong] "
        << nv.getMaNV() << " - " << nv.getHoTen()
        << " | Ngay lam thuong: " << nv.SoNgayLamViec
        << " | Ngay le: " << nv.SoNgayLe
        << " | Don gia: " << fixed << setprecision(0) << nv.DonGiaNgay
        << " | Phu cap: " << nv.PhuCap
        << " | Gio lam them ngay thuong: " << nv. GioLamThemNgayThuong
        << " | Gio lam them cuoi tuan: " << nv. GioLamThemCuoiTuan
        << " | Gio lam them le/tet: " << nv. GioLamThemLeTet
        << " | Luong: " << fixed << setprecision(0) << nv.TinhLuong();
    return out;
}
