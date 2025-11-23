#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class NhanVien {
private:
    string MaNV, HoTen, NgaySinh, DiaChi;
public:
    NhanVien();
    NhanVien(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi);
    NhanVien(const NhanVien& nv);
    virtual ~NhanVien() {}


    string getMaNV() const;
    string getHoTen() const;
    string getNgaySinh() const;
    string getDiaChi() const;


    void setMaNV(string);
    void setHoTen(string);
    void setNgaySinh(string);
    void setDiaChi(string);


    virtual double TinhLuong() const = 0;
    virtual void HienThiThongTin() const;

};
