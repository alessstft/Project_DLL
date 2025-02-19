#include "pch.h"
#include "Header.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

static string path_;
static ofstream out_;

void open_file(const char* path) {
    path_ = string(path);
    out_.open(path_, ios::app);
    
    if (!out_) {
        cerr << "Error: Unable to open file " << path_ << endl;
    }
}

void close_file() {
    if (out_.is_open()) {
        out_.close();
    }
}

void save() {
    if (out_.is_open()) {
        out_.flush();  // Ensures data is written before closing
        out_.close();
    }
}
