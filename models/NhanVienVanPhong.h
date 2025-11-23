#pragma once
#include "NhanVien.h"
#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class NhanVienVanPhong : public NhanVien {

private:
    int SoNgayLamViec;
    int SoNgayLe;
    double DonGiaNgay;
    double PhuCap;
    double GioLamThemNgayThuong;
    double GioLamThemCuoiTuan;
    double GioLamThemLeTet;
    
public:
    NhanVienVanPhong();
    NhanVienVanPhong(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi, int _SoNgayLamViec, int _SoNgayLe,
         double _DonGiaNgay, double _PhuCap, double _GioLamThemNgayThuong, double _GioLamThemCuoiTuan, double _GioLamThemLeTet);
    NhanVienVanPhong(const NhanVienVanPhong& nv);
    ~NhanVienVanPhong();
   
    int getSoNgayLamViec() const;
    int getSoNgayLe() const;
    double getDonGiaNgay() const;
    double getPhuCap() const;
    double getGioLamThemNgayThuong() const;
    double getGioLamThemCuoiTuan() const;
    double getGioLamThemLeTet() const;


    void setSoNgayLamViec(int);
    void setSoNgayLe(int);
    void setDonGiaNgay(double);
    void setPhuCap(double);
    void setGioLamThemNgayThuong(double);
    void setGioLamThemCuoiTuan(double);
    void setGioLamThemLeTet(double);


    double TinhLuong() const;
    void HienThiThongTin() const;


    friend istream& operator>>(istream& in, NhanVienVanPhong& nv);
    friend ostream& operator<<(ostream& out, const NhanVienVanPhong& nv);
};