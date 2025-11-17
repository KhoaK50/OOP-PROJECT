#pragma once
#include "NhanVien.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class QuanLi : public NhanVien
{
protected:
    double LuongCoBan;
    double LuongTrachNhiem;
    double HeSoHieuSuat;


public:
    QuanLi();
    QuanLi(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi,
           double _LuongCoBan, double _LuongTrachNhiem, double _HeSoHieuSuat);
    QuanLi(const QuanLi& nv);
    ~QuanLi();


    double getLuongCoBan() const;
    double getLuongTrachNhiem() const;
    double getHeSoHieuSuat() const;


    void setLuongCoBan(double);
    void setLuongTrachNhiem(double);
    void setHeSoHieuSuat(double);


    double TinhLuong() const;
    void HienThiThongTin() const;


    friend istream& operator>>(istream& in, QuanLi& nv);
    friend ostream& operator<<(ostream& out, const QuanLi& nv);
};
