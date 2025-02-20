#include "pch.h"
#include "Header.h"
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

static string path_;
static ofstream out_;

void open_file(const char* path) {
    cerr << "Attempting to open file: " << path << endl;
    path_ = string(path);
    out_.open(path_, ios::app);
    
    if (!out_) {
        cerr << "Error: Unable to open file " << path_ << endl;
    } else {
        cerr << "File opened successfully: " << path_ << endl;
    }
}

void close_file() {
    cerr << "Attempting to close file." << endl;
    if (out_.is_open()) {
        out_.close();
        cerr << "File closed successfully." << endl;
    } else {
        cerr << "Error: File was not open." << endl;
    }
}

void save() {
    cerr << "Attempting to save file." << endl;
    if (out_.is_open()) {
        out_.flush();
        out_.close();
        cerr << "File saved and closed successfully." << endl;
    } else {
        cerr << "Error: File was not open." << endl;
    }
}


void delete_file(const char* path) {
    if (remove(path) != 0) {
        cout << "Error deleting file";
    }
    else {
        cout << "File successfully deleted";
    }
}

void count_words(const char* path) {
    ifstream file;
    file.open(path);
    std::string word;
    unsigned count = 0;
    while (file >> word)
    {
        count++;
    }
    cout << "Word count: " << count << endl;
    file.close();
}

void write(const char* path) {
    ofstream file;
    file.open(path, ios::app);
    string str = "apple pie";
    cout << "Text: ";
    getline(cin, str);
    file << str;
    file.close();
}
