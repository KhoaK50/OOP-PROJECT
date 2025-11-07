#include "NhanVienSanXuat.h"
#include <bits/stdc++.h>
using namespace std;

NhanVienSanXuat::NhanVienSanXuat(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi,
        int _SoSP, double _DonGia) : NhanVien(_MaNV, _HoTen, _NgaySinh, _DiaChi){
           SoSanPham= _SoSP;
           DonGiaSanPham= _DonGia; 
        }

int NhanVienSanXuat::getSoSanPham() const {return SoSanPham; }
double NhanVienSanXuat::getDonGiaSanPham() const{return DonGiaSanPham; }
void NhanVienSanXuat::setSoSanPham(int sp) {SoSanPham=sp; }
void NhanVienSanXuat::setDonGiaSanPham(double dg) {DonGiaSanPham=dg; }

double NhanVienSanXuat::TinhLuong() const {
    return SoSanPham * DonGiaSanPham;
}

void NhanVienSanXuat::HienThiThongTin() const {
    cout << "===== NHAN VIEN SAN XUAT =====" << endl;
    cout << "Ma NV: " << getMaNV() << endl;
    cout << "Ho ten: " << getHoTen() << endl;
    cout << "Ngay sinh: " << getNgaySinh() << endl;
    cout << "Dia chi: " << getDiaChi() << endl;
    cout << "So san pham: " << SoSanPham << endl;
    cout << "Don gia san pham: " << fixed << setprecision(2) << DonGiaSanPham << endl;
    cout << "Luong thang: " << fixed << setprecision(2) << TinhLuong() << endl;
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
