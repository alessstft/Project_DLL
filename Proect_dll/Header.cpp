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
    out_ = ofstream out(path_, ios::app);
}

void close_file() {
    out_.close();
}

void save() {
    out_.close();
}