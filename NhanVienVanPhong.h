#pragma once
#include "NhanVien.h"
#include<iostream> 
#include<iomanip> 
#include<string> 

using namespace std;
class NhanVienVanPhong : public NhanVien
{
protected: 
    int SoNgayLamViec;//số ngày làm việc bình thường
    int SoNgayLe;//số ngày làm việc Lễ, Tết
    double DonGiaNgay;//Đơn giá ngày thường 
    double PhuCap;//Phụ cấp (có thể 0 nếu không có)
    double GioLamThemNgayThuong;//Giờ làm thêm ngày thường
    double GioLamThemCuoiTuan;//Giờ làm thêm cuối tuần
    double GioLamThemLeTet;//Giờ làm thêm ngày Lễ, Tết 
public:
    NhanVienVanPhong();
    NhanVienVanPhong(string _MaNV, string _HoTen, string _NgaySinh, string _DiaChi, int _SoNgayLamViec = 0, int _SoNgayLe = 0,
         double _DonGiaNgay = 0, double _PhuCap = 0, double _GioLamThemNgayThuong = 0, double _GioLamThemCuoiTuan = 0, double _GioLamThemLeTet = 0);
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

    virtual double TinhLuong() const;
    virtual void HienThiThongTin() const;

    friend istream& operator>>(istream& in, NhanVienVanPhong& nv);
    friend ostream& operator<<(ostream& out, const NhanVienVanPhong& nv);
}; 
