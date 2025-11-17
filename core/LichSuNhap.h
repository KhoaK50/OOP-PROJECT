#pragma once
#include <string>
#include <vector>

using namespace std;

// Lưu 1 dòng lịch sử nhập
struct LichSuDong {
    string ThoiGian;    // thời gian thực
    string LoaiNV;      // OS/PS/MG
    string DongCoBan;   // output từ operator<< (| MaNV | HoTen | NgaySinh | DiaChi |)
};

void GhiLichSu(const string& loaiNV, const string& dong);
void XuatLichSuTong();
