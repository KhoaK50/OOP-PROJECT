#include "TienIch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

string LayThoiGianHeThong() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << put_time(ltm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void ClearConsole() {
    system("cls");    
}

void PauseConsole() {
    cout << "\n\033[1;33mPress ENTER to continue...\033[0m";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
