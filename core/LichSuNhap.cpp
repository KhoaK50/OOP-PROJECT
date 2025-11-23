#include "LichSuNhap.h"
#include "TienIch.h"        

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

static vector<LichSuDong> dsLichSu;

void GhiLichSu(const string& loaiNV, const string& dong) {
    LichSuDong log;
    log.ThoiGian  = getRealTime();
    log.LoaiNV    = loaiNV;
    log.DongCoBan = dong;       
    dsLichSu.push_back(log);

    bool fileEmpty = true;
    {
        ifstream fin("output.txt");
        if (fin.good() && fin.peek() != EOF) {
            fileEmpty = false;
        }
    }

    ofstream fout("output.txt", ios::app);
    if (!fout) return; // không ghi được thì thôi, nhưng chương trình vẫn chạy

    if (fileEmpty) {
        fout << "==== ALL RECORDS ====\n\n";

        fout << left
             << setw(30) << "Time"
             << "|" << setw(6)  << "Type"
             << "|" << setw(20) << "Employee ID"
             << "|" << setw(30) << "Full Name"
             << "|" << setw(15) << "DD/MM/YYYY"
             << "|" << setw(30) << "Address"
             << '\n';

        fout << string(140, '-') << '\n';
    }

    stringstream row;
    row << left
        << setw(30) << log.ThoiGian
        << "|" << setw(6) << log.LoaiNV
        << log.DongCoBan;  

    fout << row.str() << '\n';
}


void XuatLichSuTong() {
    ClearConsole();
    
    cout << "\033[1;95m==== ALL RECORDS ====\033[0m\n\n";

    if (dsLichSu.empty()) {
        cout << "\033[1;31mNO DATA.\033[0m\n\n";
        PauseConsole();
        return;
    }

    
    cout << "\033[1;36m"; 
    cout << left
         << setw(30) << "Time"
         << "|" << setw(10)  << "Type"
         << "|" << setw(20) << "Employee ID"
         << "|" << setw(30) << "Full Name"
         << "|" << setw(15) << "DD/MM/YYYY"
         << "|" << setw(30) << "Address"
         << '\n';
    cout << "\033[0m";

    cout << string(140, '-') << '\n';

    for (const auto& log : dsLichSu) {
        cout << left
             << setw(30) << log.ThoiGian
             << "|" << setw(10) << log.LoaiNV
             << log.DongCoBan
             << '\n';
    }

    cout << "\n";
    PauseConsole();
}
