#pragma once
#include "NhanVien.h"
#include<iostream> 
#include<iomanip> 
#include<string> 
using namespace std;
class NhanVienVanPhong : public NhanVien
{
protected: 
    int SoNgayLamViec;
    double DonGiaNgay;
public:
    NhanVienVanPhong();
    NhanVienVanPhong(string _MaNV="", string _HoTen="", string _NgaySinh="", string _DiaChi="", int _SoNgay=0,double _DonGia=0);
    NhanVienVanPhong(const NhanVienVanPhong& nv);
    ~NhanVienVanPhong();
    
    int getSoNgayLamViec() const;
    double getDonGiaNgay() const;
    void setSoNgayLamViec(int);
    void setDonGiaNgay(double);

    virtual double TinhLuong() const;
    virtual void HienThiThongTin() const;

    friend istream& operator>>(istream& in, NhanVienVanPhong& nv);
    friend ostream& operator<<(ostream& out, const NhanVienVanPhong& nv);
};
