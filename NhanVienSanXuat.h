#pragma once
#include "NhanVien.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class NhanVienSanXuat : public NhanVien
{
private:
    int SoSanPham;
    double DonGiaSanPham;
public:
    NhanVienSanXuat(string _MaNV = "", string _HoTen = "", string _NgaySinh = "", string _DiaChi = "",
                    int _SoSP = 0, double _DonGia = 0);
    ~NhanVienSanXuat();

    int getSoSanPham() const;
    double getDonGiaSanPham() const;
    void setSoSanPham(int);
    void setDonGiaSanPham(double);

    virtual double TinhLuong() const;
    virtual void HienThiThongTin() const;

    friend istream& operator>>(istream& in, NhanVienSanXuat& nv);
    friend ostream& operator<<(ostream& out, const NhanVienSanXuat& nv);
};


