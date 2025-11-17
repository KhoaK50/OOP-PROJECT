Lệnh chạy trên terminal:
C:\msys64\ucrt64\bin\g++.exe -std=c++17 -O2 -Wall -Wextra *.cpp -o run.exe
.\run.exe

Lệnh build mới:
C:\msys64\ucrt64\bin\g++.exe -std=c++17 -O2 -Wall -Wextra main.cpp models/*.cpp core/*.cpp ui/*.cpp -o run.exe

g++ -std=c++17 -O2 -Wall -Wextra `
    models/NhanVien.cpp models/NhanVienVanPhong.cpp models/NhanVienSanXuat.cpp models/QuanLi.cpp `
    core/LichSuNhap.cpp core/TienIch.cpp `
    ui/Banner.cpp ui/Menu.cpp `
    main.cpp -o run.exe
