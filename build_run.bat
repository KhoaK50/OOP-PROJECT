@echo off
echo ==============================
echo  Building Human Resource Project
echo ==============================

g++ -std=c++17 -O2 -Wall -Wextra ^
    main.cpp ^
    models\*.cpp ^
    core\*.cpp ^
    ui\*.cpp ^
    -o run.exe

if %errorlevel% neq 0 (
    echo.
    echo Build FAILED!
    pause
    exit /b %errorlevel%
)

echo.
echo ===== Build SUCCESS =====
echo Running program...
echo.

run.exe

echo.
echo Program finished.
pause
