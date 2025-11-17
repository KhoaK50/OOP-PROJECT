#include "Menu.h"
#include "Banner.h"

#include "../models/NhanVienVanPhong.h"
#include "../models/NhanVienSanXuat.h"
#include "../models/QuanLi.h"

#include "../core/TienIch.h"
#include "../core/LichSuNhap.h"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

// ================== BIẾN TOÀN CỤC LƯU DỮ LIỆU ==================

static vector<NhanVienVanPhong> dsNVVP;
static vector<NhanVienSanXuat>  dsNVSX;
static vector<QuanLi>           dsQL;

// ================== HÀM HỖ TRỢ TÌM / EDIT / DELETE ==================

// ---- OFFICE STAFF ----
static void EditOfficeStaffFields(NhanVienVanPhong &nv) {
    while (true) {
        cout << "\n\033[1;36mEDIT OFFICE STAFF FIELDS\033[0m\n";
        cout << "Current: " << nv.getMaNV() << " - " << nv.getHoTen() << "\n\n";
        cout << " 1. Employee ID\n";
        cout << " 2. Full Name\n";
        cout << " 3. Date of Birth (DD/MM/YYYY)\n";
        cout << " 4. Address\n";
        cout << " 5. Normal Working Days (NWD)\n";
        cout << " 6. Holiday Working Days (HWD)\n";
        cout << " 7. Day Rate (DR)\n";
        cout << " 8. Allowance (ALW)\n";
        cout << " 9. Overtime Weekday (OTWd)\n";
        cout << "10. Overtime Weekend (OTWk)\n";
        cout << "11. Overtime Holiday (OTH)\n";
        cout << " 0. Done\n";
        cout << "Select: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "\n\033[1;32mOffice staff updated.\033[0m\n";
            break;
        }

        string s;
        int iVal;
        double dVal;

        switch (choice) {
        case 1:
            cout << "New Employee ID: ";
            getline(cin, s);
            nv.setMaNV(s);
            break;
        case 2:
            cout << "New Full Name: ";
            getline(cin, s);
            nv.setHoTen(s);
            break;
        case 3:
            cout << "New Date of Birth (DD/MM/YYYY): ";
            getline(cin, s);
            nv.setNgaySinh(s);
            break;
        case 4:
            cout << "New Address: ";
            getline(cin, s);
            nv.setDiaChi(s);
            break;
        case 5:
            cout << "New Normal Working Days (NWD): ";
            cin >> iVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setSoNgayLamViec(iVal);
            break;
        case 6:
            cout << "New Holiday Working Days (HWD): ";
            cin >> iVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setSoNgayLe(iVal);
            break;
        case 7:
            cout << "New Day Rate (DR - thousand VND/day): ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setDonGiaNgay(dVal);
            break;
        case 8:
            cout << "New Allowance (ALW - thousand VND/month): ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setPhuCap(dVal);
            break;
        case 9:
            cout << "New Overtime Weekday hours (OTWd): ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setGioLamThemNgayThuong(dVal);
            break;
        case 10:
            cout << "New Overtime Weekend hours (OTWk): ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setGioLamThemCuoiTuan(dVal);
            break;
        case 11:
            cout << "New Overtime Holiday hours (OTH): ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setGioLamThemLeTet(dVal);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

static void SearchEditDeleteOfficeStaff() {
    ClearConsole();
    PrintBannerQLNS();
    cout << "\033[1;95m=== OFFICE STAFF - SEARCH / EDIT / DELETE ===\033[0m\n\n";

    if (dsNVVP.empty()) {
        cout << "\033[1;31mNO DATA!\033[0m\n";
        PauseConsole();
        return;
    }

    string key;
    cout << "Enter Employee ID: ";
    getline(cin >> ws, key);

    vector<int> matches;
    for (int i = 0; i < (int)dsNVVP.size(); ++i) {
        if (dsNVVP[i].getMaNV().find(key) != string::npos) {
            matches.push_back(i);
        }
    }

    if (matches.empty()) {
        cout << "\n\033[1;31mNO MATCH FOUND.\033[0m\n";
        PauseConsole();
        return;
    }

    int idx = -1;

    if (matches.size() == 1) {
        idx = matches[0];
    } else {
        cout << "\nMultiple matches found:\n";
        for (int i = 0; i < (int)matches.size(); ++i) {
            const auto &nv = dsNVVP[matches[i]];
            cout << " " << (i + 1) << ". " << nv.getMaNV()
                 << " - " << nv.getHoTen() << "\n";
        }
        cout << "Select record (1-" << matches.size()
             << "), or 0 to cancel: ";
        int sel;
        if (!(cin >> sel)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid selection.\n";
            PauseConsole();
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sel == 0) {
            cout << "Cancelled.\n";
            PauseConsole();
            return;
        }
        if (sel < 1 || sel > (int)matches.size()) {
            cout << "Invalid selection.\n";
            PauseConsole();
            return;
        }
        idx = matches[sel - 1];
    }

    if (idx < 0 || idx >= (int)dsNVVP.size()) {
        cout << "Unexpected index error.\n";
        PauseConsole();
        return;
    }

    while (true) {
        NhanVienVanPhong &nv = dsNVVP[idx];

        cout << "\n\033[1;36mTARGET RECORD\033[0m: "
             << nv.getMaNV() << " - " << nv.getHoTen() << "\n\n";
        cout << " 1. Re-enter all information\n";
        cout << " 2. Edit individual fields\n";
        cout << " 3. Delete this record\n";
        cout << " 0. Cancel\n";
        cout << "Select: ";

        int act;
        if (!(cin >> act)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (act == 0) {
            cout << "\nCancelled.\n";
            PauseConsole();
            return;
        } else if (act == 1) {
            cout << "\n\033[1;95mRE-ENTER ALL INFORMATION\033[0m\n";
            NhanVienVanPhong temp;
            cin >> temp;
            dsNVVP[idx] = temp;
            cout << "\n\033[1;32mRecord updated successfully.\033[0m\n";
            PauseConsole();
            return;
        } else if (act == 2) {
            EditOfficeStaffFields(nv);
            PauseConsole();
            return;
        } else if (act == 3) {
            char conf;
            cout << "Are you sure you want to delete this record? (Y/N): ";
            cin >> conf;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (conf == 'Y' || conf == 'y') {
                dsNVVP.erase(dsNVVP.begin() + idx);
                cout << "\n\033[1;32mRecord deleted.\033[0m\n";
                PauseConsole();
                return;
            } else {
                cout << "Delete cancelled.\n";
                PauseConsole();
                return;
            }
        } else {
            cout << "Invalid selection.\n";
        }
    }
}

// ---- PRODUCTION STAFF ----
static void EditProductionStaffFields(NhanVienSanXuat &nv) {
    while (true) {
        cout << "\n\033[1;36mEDIT PRODUCTION STAFF FIELDS\033[0m\n";
        cout << "Current: " << nv.getMaNV() << " - " << nv.getHoTen() << "\n\n";
        cout << " 1. Employee ID\n";
        cout << " 2. Full Name\n";
        cout << " 3. Date of Birth (DD/MM/YYYY)\n";
        cout << " 4. Address\n";
        cout << " 5. Product Quantity\n";
        cout << " 6. Product Unit Price\n";
        cout << " 0. Done\n";
        cout << "Select: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "\n\033[1;32mProduction staff updated.\033[0m\n";
            break;
        }

        string s;
        int iVal;
        double dVal;

        switch (choice) {
        case 1:
            cout << "New Employee ID: ";
            getline(cin, s);
            nv.setMaNV(s);
            break;
        case 2:
            cout << "New Full Name: ";
            getline(cin, s);
            nv.setHoTen(s);
            break;
        case 3:
            cout << "New Date of Birth (DD/MM/YYYY): ";
            getline(cin, s);
            nv.setNgaySinh(s);
            break;
        case 4:
            cout << "New Address: ";
            getline(cin, s);
            nv.setDiaChi(s);
            break;
        case 5:
            cout << "New Product Quantity: ";
            cin >> iVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setSoSanPham(iVal);
            break;
        case 6:
            cout << "New Product Unit Price (thousand VND/product): ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setDonGiaSanPham(dVal);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

static void SearchEditDeleteProductionStaff() {
    ClearConsole();
    PrintBannerQLNS();
    cout << "\033[1;95m=== PRODUCTION STAFF - SEARCH / EDIT / DELETE ===\033[0m\n\n";

    if (dsNVSX.empty()) {
        cout << "\033[1;31mNO DATA!\033[0m\n";
        PauseConsole();
        return;
    }

    string key;
    cout << "Enter Employee ID: ";
    getline(cin >> ws, key);

    vector<int> matches;
    for (int i = 0; i < (int)dsNVSX.size(); ++i) {
        if (dsNVSX[i].getMaNV().find(key) != string::npos) {
            matches.push_back(i);
        }
    }

    if (matches.empty()) {
        cout << "\n\033[1;31mNO MATCH FOUND.\033[0m\n";
        PauseConsole();
        return;
    }

    int idx = -1;

    if (matches.size() == 1) {
        idx = matches[0];
    } else {
        cout << "\nMultiple matches found:\n";
        for (int i = 0; i < (int)matches.size(); ++i) {
            const auto &nv = dsNVSX[matches[i]];
            cout << " " << (i + 1) << ". " << nv.getMaNV()
                 << " - " << nv.getHoTen() << "\n";
        }
        cout << "Select record (1-" << matches.size()
             << "), or 0 to cancel: ";
        int sel;
        if (!(cin >> sel)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid selection.\n";
            PauseConsole();
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sel == 0) {
            cout << "Cancelled.\n";
            PauseConsole();
            return;
        }
        if (sel < 1 || sel > (int)matches.size()) {
            cout << "Invalid selection.\n";
            PauseConsole();
            return;
        }
        idx = matches[sel - 1];
    }

    if (idx < 0 || idx >= (int)dsNVSX.size()) {
        cout << "Unexpected index error.\n";
        PauseConsole();
        return;
    }

    while (true) {
        NhanVienSanXuat &nv = dsNVSX[idx];

        cout << "\n\033[1;36mTARGET RECORD\033[0m: "
             << nv.getMaNV() << " - " << nv.getHoTen() << "\n\n";
        cout << " 1. Re-enter all information\n";
        cout << " 2. Edit individual fields\n";
        cout << " 3. Delete this record\n";
        cout << " 0. Cancel\n";
        cout << "Select: ";

        int act;
        if (!(cin >> act)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (act == 0) {
            cout << "\nCancelled.\n";
            PauseConsole();
            return;
        } else if (act == 1) {
            cout << "\n\033[1;95mRE-ENTER ALL INFORMATION\033[0m\n";
            NhanVienSanXuat temp;
            cin >> temp;
            dsNVSX[idx] = temp;
            cout << "\n\033[1;32mRecord updated successfully.\033[0m\n";
            PauseConsole();
            return;
        } else if (act == 2) {
            EditProductionStaffFields(nv);
            PauseConsole();
            return;
        } else if (act == 3) {
            char conf;
            cout << "Are you sure you want to delete this record? (Y/N): ";
            cin >> conf;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (conf == 'Y' || conf == 'y') {
                dsNVSX.erase(dsNVSX.begin() + idx);
                cout << "\n\033[1;32mRecord deleted.\033[0m\n";
                PauseConsole();
                return;
            } else {
                cout << "Delete cancelled.\n";
                PauseConsole();
                return;
            }
        } else {
            cout << "Invalid selection.\n";
        }
    }
}

// ---- MANAGER ----
static void EditManagerFields(QuanLi &nv) {
    while (true) {
        cout << "\n\033[1;36mEDIT MANAGER FIELDS\033[0m\n";
        cout << "Current: " << nv.getMaNV() << " - " << nv.getHoTen() << "\n\n";
        cout << " 1. Employee ID\n";
        cout << " 2. Full Name\n";
        cout << " 3. Date of Birth (DD/MM/YYYY)\n";
        cout << " 4. Address\n";
        cout << " 5. Base Salary\n";
        cout << " 6. Responsibility Allowance\n";
        cout << " 7. Performance Coefficient\n";
        cout << " 0. Done\n";
        cout << "Select: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "\n\033[1;32mManager updated.\033[0m\n";
            break;
        }

        string s;
        double dVal;

        switch (choice) {
        case 1:
            cout << "New Employee ID: ";
            getline(cin, s);
            nv.setMaNV(s);
            break;
        case 2:
            cout << "New Full Name: ";
            getline(cin, s);
            nv.setHoTen(s);
            break;
        case 3:
            cout << "New Date of Birth (DD/MM/YYYY): ";
            getline(cin, s);
            nv.setNgaySinh(s);
            break;
        case 4:
            cout << "New Address: ";
            getline(cin, s);
            nv.setDiaChi(s);
            break;
        case 5:
            cout << "New Base Salary (million VND/month): ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setLuongCoBan(dVal);
            break;
        case 6:
            cout << "New Responsibility Allowance (million VND/month): ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setLuongTrachNhiem(dVal);
            break;
        case 7:
            cout << "New Performance Coefficient: ";
            cin >> dVal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            nv.setHeSoHieuSuat(dVal);
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }
}

static void SearchEditDeleteManager() {
    ClearConsole();
    PrintBannerQLNS();
    cout << "\033[1;95m=== MANAGER - SEARCH / EDIT / DELETE ===\033[0m\n\n";

    if (dsQL.empty()) {
        cout << "\033[1;31mNO DATA!\033[0m\n";
        PauseConsole();
        return;
    }

    string key;
    cout << "Enter Employee ID: ";
    getline(cin >> ws, key);

    vector<int> matches;
    for (int i = 0; i < (int)dsQL.size(); ++i) {
        if (dsQL[i].getMaNV().find(key) != string::npos) {
            matches.push_back(i);
        }
    }

    if (matches.empty()) {
        cout << "\n\033[1;31mNO MATCH FOUND.\033[0m\n";
        PauseConsole();
        return;
    }

    int idx = -1;

    if (matches.size() == 1) {
        idx = matches[0];
    } else {
        cout << "\nMultiple matches found:\n";
        for (int i = 0; i < (int)matches.size(); ++i) {
            const auto &nv = dsQL[matches[i]];
            cout << " " << (i + 1) << ". " << nv.getMaNV()
                 << " - " << nv.getHoTen() << "\n";
        }
        cout << "Select record (1-" << matches.size()
             << "), or 0 to cancel: ";
        int sel;
        if (!(cin >> sel)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid selection.\n";
            PauseConsole();
            return;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sel == 0) {
            cout << "Cancelled.\n";
            PauseConsole();
            return;
        }
        if (sel < 1 || sel > (int)matches.size()) {
            cout << "Invalid selection.\n";
            PauseConsole();
            return;
        }
        idx = matches[sel - 1];
    }

    if (idx < 0 || idx >= (int)dsQL.size()) {
        cout << "Unexpected index error.\n";
        PauseConsole();
        return;
    }

    while (true) {
        QuanLi &nv = dsQL[idx];

        cout << "\n\033[1;36mTARGET RECORD\033[0m: "
             << nv.getMaNV() << " - " << nv.getHoTen() << "\n\n";
        cout << " 1. Re-enter all information\n";
        cout << " 2. Edit individual fields\n";
        cout << " 3. Delete this record\n";
        cout << " 0. Cancel\n";
        cout << "Select: ";

        int act;
        if (!(cin >> act)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (act == 0) {
            cout << "\nCancelled.\n";
            PauseConsole();
            return;
        } else if (act == 1) {
            cout << "\n\033[1;95mRE-ENTER ALL INFORMATION\033[0m\n";
            QuanLi temp;
            cin >> temp;
            dsQL[idx] = temp;
            cout << "\n\033[1;32mRecord updated successfully.\033[0m\n";
            PauseConsole();
            return;
        } else if (act == 2) {
            EditManagerFields(nv);
            PauseConsole();
            return;
        } else if (act == 3) {
            char conf;
            cout << "Are you sure you want to delete this record? (Y/N): ";
            cin >> conf;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (conf == 'Y' || conf == 'y') {
                dsQL.erase(dsQL.begin() + idx);
                cout << "\n\033[1;32mRecord deleted.\033[0m\n";
                PauseConsole();
                return;
            } else {
                cout << "Delete cancelled.\n";
                PauseConsole();
                return;
            }
        } else {
            cout << "Invalid selection.\n";
        }
    }
}

// ================== HÀM XUẤT LỊCH SỬ NHẬP RIÊNG ==================

// Lịch sử nhập riêng cho Văn phòng
void XuatLichSuVanPhong() {
    ClearConsole();
    PrintBannerQLNS();

    cout << "\033[1;95m=== OFFICE EMPLOYEE ENTRY HISTORY ===\033[0m\n\n";

    if (dsNVVP.empty()) {
        cout << "\033[1;31mNO DATA!\033[0m\n";
        PauseConsole();
        return;
    }

    cout << "\033[0;33m";
    cout << "NWD = Normal Working Days: Ngày làm bình thường (ngày)\n";
    cout << "HWD = Holiday Working Days: Ngày làm kì lễ (ngày)\n";
    cout << "DR = Day Rate: Đơn giá ngày (Nghìn VNĐ/ngày)\n";
    cout << "ALW = Allowance: Phụ cấp (Nghìn VNĐ/tháng)\n";
    cout << "OTWd = Overtime Weekday: Giờ làm thêm ngày thường (giờ)\n";
    cout << "OTWk = Overtime Weekend: Giờ làm thêm cuối tuần (giờ)\n";
    cout << "OTH = Overtime Holiday: Giờ làm thêm ngày lễ (giờ)\n";
    cout << "Salary: Lương (Triệu VNĐ/tháng)\n\n";
    cout << "\033[0m";

    cout << "\033[1;36m";
    cout << left
     << "|" << setw(20) << "Employee ID"
     << "|" << setw(30) << "Full Name"
     << "|" << setw(5)  << "NWD"
     << "|" << setw(5)  << "HWD"
     << "|" << setw(5)  << "DR"
     << "|" << setw(5)  << "ALW"
     << "|" << setw(5)  << "OTWd"
     << "|" << setw(5)  << "OTWk"
     << "|" << setw(5)  << "OTH"
     << "|" << setw(25) << "Salary" << "\n";
    cout << "\033[0m";

    cout << string(120, '-') << '\n';   

    for (const auto& nv : dsNVVP) {
        nv.HienThiThongTin();
    }

    PauseConsole();
}

// Lịch sử nhập riêng cho Sản xuất
void XuatLichSuSanXuat() {
    ClearConsole();
    PrintBannerQLNS();

    cout << "\033[1;95m=== Production Employee Entry History ===\033[0m\n\n";

    if (dsNVSX.empty()) {
        cout << "\033[1;31mNO DATA!\033[0m\n";
        PauseConsole();
        return;
    }

    cout << "\033[0;33m";
    cout << "Product Quantity: Số sản phẩm (sản phẩm)\n";
    cout << "Product Unit Price: Đơn giá sản phẩm (Nghìn VNĐ/sản phẩm)\n";
    cout << "Salary: Lương (Triệu VNĐ/tháng)\n\n";
    cout << "\033[0m";

    cout << "\033[1;36m";
    cout << left
     << "|" << setw(20)  << "Employee ID"
     << "|" << setw(30) << "Full Name"
     << "|" << setw(20)  << "Product Quantity"
     << "|" << setw(20)  << "Product Unit Price"
     << "|" << setw(25) << "Salary" << "\n";
    cout << "\033[0m";

    cout << string(120, '-') << '\n';

    for (const auto& nv : dsNVSX) {
        nv.HienThiThongTin();
    }

    PauseConsole();
}

// Lịch sử nhập riêng cho Quản lí
void XuatLichSuQuanLi() {
    ClearConsole();
    PrintBannerQLNS();

    cout << "\033[1;95m=== Manager Entry History ===\033[0m\n\n";

    if (dsQL.empty()) {
        cout << "\033[1;31mNO DATA!\033[0m\n";
        PauseConsole();
        return;
    }

    cout << "\033[0;33m";
    cout << "Base Salary: Lương cơ bản (Triệu VNĐ/tháng)\n";
    cout << "Responsibility Allowance: Lương trách nhiệm (Triệu VNĐ/tháng)\n";
    cout << "Performance Coefficient: Hệ số hiệu suất\n";
    cout << "Salary: Lương (Triệu VNĐ/tháng)\n\n";
    cout << "\033[0m";

    cout << "\033[1;36m";
    cout << left
         << "|" << setw(20)  << "Employee ID"
         << "|" << setw(30) << "Full Name"
         << "|" << setw(20) << "Base Salary"
         << "|" << setw(25) << "Responsibility Allowance"
         << "|" << setw(25) << "Performance Coefficient"
         << "|" << setw(25) << "Salary" << "\n";
    cout << "\033[0m";

    cout << string(145, '-') << '\n';

    for (const auto& nv : dsQL) {
        nv.HienThiThongTin();
    }

    PauseConsole();
}

// ================== MENU CON ==================

void MenuVanPhong() {
    while (true) {
        ClearConsole();
        PrintBannerQLNS();

        cout << "\033[1;95m=== OFFICE STAFF ===\033[0m\n";
        cout << "\033[36m1.\033[0m Enter information\n";
        cout << "\033[36m2.\033[0m Entry History \n";
        cout << "\033[36m3.\033[0m Search / Edit / Delete by Employee ID\n";
        cout << "\033[36m0.\033[0m Back to Main Menu\n";
        cout << "Select: ";

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // bỏ '\n'

        if (ch == 0) break;

        switch (ch) {
        case 1: {
            ClearConsole();
            PrintBannerQLNS();
            cout << "\033[1;95m=== OFFICE STAFF - INFORMATION ENTRY ===\033[0m\n\n";

            NhanVienVanPhong nv;
            cin >> nv;                   
            dsNVVP.push_back(nv);         

            stringstream ss;
            ss << nv;                     
            GhiLichSu("OS", ss.str());

            cout << "\n\033[1;32mINFORMATION HAS BEEN ADDED SUCCESSFULLY!\033[0m\n";
            PauseConsole();
            break;
        }
        case 2:
            XuatLichSuVanPhong();
            break;
        case 3:
            SearchEditDeleteOfficeStaff();
            break;
        default:
            break;
        }
    }
}

void MenuSanXuat() {
    while (true) {
        ClearConsole();
        PrintBannerQLNS();

        cout << "\033[1;95m=== PRODUCTION STAFF ===\033[0m\n";
        cout << "\033[36m1.\033[0m Enter information\n";
        cout << "\033[36m2.\033[0m Entry History\n";
        cout << "\033[36m3.\033[0m Search / Edit / Delete by Employee ID\n";
        cout << "\033[36m0.\033[0m Back to Main Menu\n";
        cout << "Select: ";

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (ch == 0) break;

        switch (ch) {
        case 1: {
            ClearConsole();
            PrintBannerQLNS();
            cout << "\033[1;95m=== PRODUCTION STAFF - INFORMATION ENTRY ===\033[0m\n\n";

            NhanVienSanXuat nv;
            cin >> nv;
            dsNVSX.push_back(nv);

            stringstream ss;
            ss << nv;
            GhiLichSu("PS", ss.str());

            cout << "\n\033[1;32mINFORMATION HAS BEEN ADDED SUCCESSFULLY!\033[0m\n";
            PauseConsole();
            break;
        }
        case 2:
            XuatLichSuSanXuat();
            break;
        case 3:
            SearchEditDeleteProductionStaff();
            break;
        default:
            break;
        }
    }
}

void MenuQuanLi() {
    while (true) {
        ClearConsole();
        PrintBannerQLNS();

        cout << "\033[1;95m=== MANAGER ===\033[0m\n";
        cout << "\033[36m1.\033[0m Enter information\n";
        cout << "\033[36m2.\033[0m Entry History\n";
        cout << "\033[36m3.\033[0m Search / Edit / Delete by Employee ID\n";
        cout << "\033[36m0.\033[0m Back to Main Menu\n";
        cout << "Select: ";

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (ch == 0) break;

        switch (ch) {
        case 1: {
            ClearConsole();
            PrintBannerQLNS();
            cout << "\033[1;95m=== MANAGER - INFORMATION ENTRY ===\033[0m\n\n";

            QuanLi ql;
            cin >> ql;
            dsQL.push_back(ql);

            stringstream ss;
            ss << ql;
            GhiLichSu("MG", ss.str());

            cout << "\n\033[1;32mINFORMATION HAS BEEN ADDED SUCCESSFULLY!\033[0m\n";
            PauseConsole();
            break;
        }
        case 2:
            XuatLichSuQuanLi();
            break;
        case 3:
            SearchEditDeleteManager();
            break;
        default:
            break;
        }
    }
}

// ================== MENU CHÍNH ==================

void MenuChinh() {
    while (true) {
        ClearConsole();
        PrintBannerQLNS();

        cout << "\033[1;95m=== HUMAN RESOURCE MANAGEMENT SYSTEM ===\033[0m\n";
        cout << "\033[36m1.\033[0m Office Staff\n";
        cout << "\033[36m2.\033[0m Production Staff\n";
        cout << "\033[36m3.\033[0m Manager\n";
        cout << "\033[36m4.\033[0m All Records\n";
        cout << "\033[36m0.\033[0m Exit\n";
        cout << "Select: ";

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (ch) {
        case 1:
            MenuVanPhong();
            break;
        case 2:
            MenuSanXuat();
            break;
        case 3:
            MenuQuanLi();
            break;
        case 4:
            XuatLichSuTong();  
            break;
        case 0:
            ClearConsole();
            cout << "\033[1;32mGoodbye from Human Resource Management System!\033[0m\n";
            return;
        default:
            break;
        }
    }
}
