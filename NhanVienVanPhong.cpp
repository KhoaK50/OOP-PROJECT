#include "NhanVienVanPhong.h"
#include<iostream> 
#include<iomanip> 
#include<string> 
using namespace std;

NhanVienVanPhong::NhanVienVanPhong() 
    : NhanVien("", "", "", ""), SoNgayLamViec(0), DonGiaNgay(0.0) {}

NhanVienVanPhong::NhanVienVanPhong(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi, int _SoNgay, double _DonGia) 
    : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi)
{
    SoNgayLamViec = _SoNgay;
    DonGiaNgay = _DonGia;
}

NhanVienVanPhong::NhanVienVanPhong(const NhanVienVanPhong& nv)
    : NhanVien(nv)
{
    SoNgayLamViec = nv.SoNgayLamViec;
    DonGiaNgay = nv.DonGiaNgay;
}

NhanVienVanPhong::~NhanVienVanPhong() {}

int NhanVienVanPhong::getSoNgayLamViec() const {return SoNgayLamViec;}
double NhanVienVanPhong::getDonGiaNgay() const {return DonGiaNgay;}
void NhanVienVanPhong::setSoNgayLamViec(int n) {SoNgayLamViec=n;}
void NhanVienVanPhong::setDonGiaNgay(double g) {DonGiaNgay=g;}

double NhanVienVanPhong::TinhLuong() const {
    return SoNgayLamViec * DonGiaNgay;
}
void NhanVienVanPhong::HienThiThongTin() const {
    cout<<"[NhanVienVanPhong]"
        <<getMaNV() <<" - "<< getHoTen()
        <<" | Ngay lam: " << SoNgayLamViec
        <<" | Don gia: " <<fixed<<setprecision(2)<<DonGiaNgay
        <<" | Luong: " <<fixed<<setprecision(2)<<TinhLuong()
        <<endl;
}

istream& operator>>(istream& in, NhanVienVanPhong& nv) {
    cout << "Nhap ma NV: ";
    getline(in, nv.MaNV);
    cout << "Nhap ho ten: ";
    getline(in, nv.HoTen);
    cout << "Nhap ngay sinh: ";
    getline(in, nv.NgaySinh);
    cout << "Nhap dia chi: ";
    getline(in, nv.DiaChi);
    cout << "Nhap so ngay lam viec: ";
    in >> nv.SoNgayLamViec;
    cout << "Nhap don gia ngay: ";
    in >> nv.DonGiaNgay;
    in.ignore();
    return in;
}

ostream& operator<<(ostream& out, const NhanVienVanPhong& nv) {
    out << "[NhanVienVanPhong] " << nv.getMaNV() << " - " << nv.getHoTen()
        << " | Ngay lam: " << nv.SoNgayLamViec
        << " | Don gia: " << fixed << setprecision(2) << nv.DonGiaNgay
        << " | Luong: " << fixed << setprecision(2) << nv.TinhLuong();
    return out;
}
