#include "pch.h"
#include "Header.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;
static string path_;

void open_file(const char* path) {
    path_ = string(path);
    ofstream out(path_, ios::app);
    system(("notepad " + string(path)).c_str());
}

void close_file() {
    system("taskkill /IM notepad.exe /F");
}

void save() {
    ofstream out(path_, ios::app);
    if (!out.is_open()) {
        cerr << "Error saving file: " << path_ << endl;
    }
    else {
        cout << "File saved: " << path_ << endl;
    }
    out.close();
}


