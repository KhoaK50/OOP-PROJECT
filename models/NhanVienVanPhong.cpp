#include "NhanVienVanPhong.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;


NhanVienVanPhong::NhanVienVanPhong()
    : NhanVien("", "", "", ""),
      SoNgayLamViec(0), SoNgayLe(0),
      DonGiaNgay(0.0), PhuCap(0.0),
      GioLamThemNgayThuong(0.0),
      GioLamThemCuoiTuan(0.0),
      GioLamThemLeTet(0.0) {}

NhanVienVanPhong::NhanVienVanPhong(string _MaNV, string _HoTen, string _NgaySinh,
                                   string _DiaChi, int _SoNgayLamViec,
                                   int _SoNgayLe, double _DonGiaNgay,
                                   double _PhuCap,
                                   double _GioLamThemNgayThuong,
                                   double _GioLamThemCuoiTuan,
                                   double _GioLamThemLeTet)
    : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi),
      SoNgayLamViec(_SoNgayLamViec),
      SoNgayLe(_SoNgayLe),
      DonGiaNgay(_DonGiaNgay),
      PhuCap(_PhuCap),
      GioLamThemNgayThuong(_GioLamThemNgayThuong),
      GioLamThemCuoiTuan(_GioLamThemCuoiTuan),
      GioLamThemLeTet(_GioLamThemLeTet) {}

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

int    NhanVienVanPhong::getSoNgayLamViec() const          { return SoNgayLamViec;}
int    NhanVienVanPhong::getSoNgayLe() const               { return SoNgayLe;}
double NhanVienVanPhong::getDonGiaNgay() const             { return DonGiaNgay;}
double NhanVienVanPhong::getPhuCap() const                 { return PhuCap;}
double NhanVienVanPhong::getGioLamThemNgayThuong() const   { return GioLamThemNgayThuong;}
double NhanVienVanPhong::getGioLamThemCuoiTuan() const     { return GioLamThemCuoiTuan;}
double NhanVienVanPhong::getGioLamThemLeTet() const        { return GioLamThemLeTet;}

void   NhanVienVanPhong::setSoNgayLamViec(int n)           { SoNgayLamViec = n;}
void   NhanVienVanPhong::setSoNgayLe(int n)                { SoNgayLe = n;}
void   NhanVienVanPhong::setDonGiaNgay(double g)           { DonGiaNgay = g;}
void   NhanVienVanPhong::setPhuCap(double p)               { PhuCap = p;}
void   NhanVienVanPhong::setGioLamThemNgayThuong(double h) { GioLamThemNgayThuong = h;}
void   NhanVienVanPhong::setGioLamThemCuoiTuan(double h)   { GioLamThemCuoiTuan = h;}
void   NhanVienVanPhong::setGioLamThemLeTet(double h)      { GioLamThemLeTet = h;}


double NhanVienVanPhong::TinhLuong() const {
    double luongThuong = SoNgayLamViec * DonGiaNgay;
    double luongLe     = SoNgayLe * DonGiaNgay * 3.0;

    double luongMotGio = DonGiaNgay / 8.0;

    double luongOT =
        GioLamThemNgayThuong * luongMotGio * 1.5 +
        GioLamThemCuoiTuan   * luongMotGio * 2.0 +
        GioLamThemLeTet      * luongMotGio * 3.0;

    return luongThuong + luongLe + luongOT + PhuCap;
}


void NhanVienVanPhong::HienThiThongTin() const {
    cout << left
         << "|" << setw(20)  << getMaNV()
         << "|" << setw(30) << getHoTen()
         << "|"  << setw(5)  << SoNgayLamViec          
         << "|" << setw(5)  << SoNgayLe            
         << "|" << setw(5)  << fixed << setprecision(0) << DonGiaNgay  
         << "|" << setw(5)  << fixed << setprecision(0) << PhuCap      
         << "|" << setw(5)  << fixed << setprecision(1) << GioLamThemNgayThuong   
         << "|" << setw(5)  << fixed << setprecision(1) << GioLamThemCuoiTuan     
         << "|" << setw(5)  << fixed << setprecision(1) << GioLamThemLeTet       
         << "|" << setw(25) << fixed << setprecision(3) << TinhLuong() << "\n";
}


istream& operator>>(istream& in, NhanVienVanPhong& nv) {
    string ma, ten, ngay, dia;
    int    soNgayLamViec, soNgayLe;
    double donGiaNgay, phuCap, gioLamThemNgayThuong,
           gioLamThemCuoiTuan, gioLamThemLeTet;

    cout << "Nhập mã nhân viên  : ";
    getline(in >> ws, ma);
    cout << "Nhập họ tên        : ";
    getline(in, ten);
    cout << "Nhập DD/MM/YYYY    : ";
    getline(in, ngay);
    cout << "Nhập địa chỉ       : ";
    getline(in, dia);
    cout << "Nhập số ngày làm thường  : ";
    in >> soNgayLamViec;
    cout << "Nhập số ngày làm lễ/tết  : ";
    in >> soNgayLe;
    cout << "Nhập đơn giá ngày        : ";
    in >> donGiaNgay;
    cout << "Nhập phụ cấp             : ";
    in >> phuCap;
    cout << "Nhập giờ làm thêm ngày thường  : ";
    in >> gioLamThemNgayThuong;
    cout << "Nhập giờ làm thêm cuối tuần    : ";
    in >> gioLamThemCuoiTuan;
    cout << "Nhập giờ làm thêm ngày lễ/tết  : ";
    in >> gioLamThemLeTet;


    nv.setMaNV(ma);
    nv.setHoTen(ten);
    nv.setNgaySinh(ngay);
    nv.setDiaChi(dia);
    nv.setSoNgayLamViec(soNgayLamViec);
    nv.setSoNgayLe(soNgayLe);
    nv.setDonGiaNgay(donGiaNgay);
    nv.setPhuCap(phuCap);
    nv.setGioLamThemNgayThuong(gioLamThemNgayThuong);
    nv.setGioLamThemCuoiTuan(gioLamThemCuoiTuan);
    nv.setGioLamThemLeTet(gioLamThemLeTet);

    in.ignore(numeric_limits<streamsize>::max(), '\n');
    return in;
}


ostream& operator<<(ostream& out, const NhanVienVanPhong& nv) {
    out << left
        << "|" << setw(20)  << nv.getMaNV()
        << "|" << setw(30) << nv.getHoTen()
        << "|" << setw(15) << nv.getNgaySinh()
        << "|" << setw(30) << nv.getDiaChi() << "\n";
    return out;
}
