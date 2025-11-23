#include "TienIch.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>
#include <sstream>

using namespace std;

string getRealTime() {
    time_t now = time(NULL);
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
