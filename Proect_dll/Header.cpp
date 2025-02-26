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

void save_and_close() {
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
    int status = remove(path);
    if (status != 0) {
        cout << "Error deleting file";
    }
    else {
        cout << "File successfully deleted";
    }
}

int count_words(const char* path) {
    ifstream file;
    file.open(path);
    string word;
    int count = 0;
    while (file >> word)
    {
        count++;
    }
    file.close();
    return count;
}

void write(const char* path, const char* str) {
    ofstream file;
    file.open(path, ios::app);
    file << str;
    file.close();
}

const char* read_file(const char* path) {
    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        return "Error!";
    }
    string line;
    char* content = new char[0] {};
    while (getline(file, line)) {
        strcpy_s(content, strlen(content) + line.size(), line.c_str());
    }
    file.close();

    return content;
}


bool search_in_file(const char* path, const char* thing) {
    ifstream file;
    string line, text, thing_str;

    file.open(path);
    while (getline(file, line)) {
        text += line + '\n';
    }
    file.close();
    thing_str.assign(thing, strlen(thing));
    
    return text.find(thing) != string::npos;
}


size_t get_file_size(const char* path)
{
    cerr << "Attempting to get file size for: " << path << endl;
    ifstream in(path, ios::binary | ios::ate);
    if (!in) {
        cerr << "Error: Unable to open file " << path << " to determine size." << endl;
        return 0;
    }

    size_t size = static_cast<size_t>(in.tellg());
    in.close();

    cerr << "File size is " << size << " bytes." << endl;
    return size;
}
