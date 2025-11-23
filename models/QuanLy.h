#pragma once
#include "NhanVien.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class QuanLy : public NhanVien {
    
private:
    double LuongCoBan;
    double LuongTrachNhiem;
    double HeSoHieuSuat;

public:
    QuanLy();
    QuanLy(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi,
           double _LuongCoBan, double _LuongTrachNhiem, double _HeSoHieuSuat);
    QuanLy(const QuanLy& nv);
    ~QuanLy();


    double getLuongCoBan() const;
    double getLuongTrachNhiem() const;
    double getHeSoHieuSuat() const;


    void setLuongCoBan(double);
    void setLuongTrachNhiem(double);
    void setHeSoHieuSuat(double);


    double TinhLuong() const;
    void HienThiThongTin() const;


    friend istream& operator>>(istream& in, QuanLy& nv);
    friend ostream& operator<<(ostream& out, const QuanLy& nv);
};
