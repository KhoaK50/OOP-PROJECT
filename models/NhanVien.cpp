#include "NhanVien.h"
#include <iostream>
#include <iomanip>
using namespace std;


NhanVien::NhanVien()
    : MaNV(""), HoTen(""), NgaySinh(""), DiaChi("") {}

NhanVien::NhanVien(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi)
    : MaNV(_MaNV), HoTen(_HoTen), NgaySinh(_NgaySinh), DiaChi(_DiaChi) {}

NhanVien::NhanVien(const NhanVien& nv)
    : MaNV(nv.MaNV), HoTen(nv.HoTen), NgaySinh(nv.NgaySinh), DiaChi(nv.DiaChi) {}



string NhanVien::getMaNV() const      { return MaNV; }
string NhanVien::getHoTen() const     { return HoTen; }
string NhanVien::getNgaySinh() const  { return NgaySinh; }
string NhanVien::getDiaChi() const    { return DiaChi; }

void NhanVien::setMaNV(string v)      { MaNV = v; }
void NhanVien::setHoTen(string v)     { HoTen = v; }
void NhanVien::setNgaySinh(string v)  { NgaySinh = v; }
void NhanVien::setDiaChi(string v)    { DiaChi = v; }



void NhanVien::HienThiThongTin() const {
    cout << left
         << "|" << setw(20) << MaNV
         << "|" << setw(30) << HoTen
         << "|" << setw(15) << NgaySinh
         << "|" << setw(30) << DiaChi
         << "|";
}
