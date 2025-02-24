#ifndef HEADER_H
#define HEADER_H

#ifdef EXPORTING_DLL
#define DLL_API __declspec(dllexport)  // Для экспорта функций
#else
#define DLL_API __declspec(dllimport)
#endif

extern "C" {
    DLL_API void open_file(const char* path);
    DLL_API void close_file();
    DLL_API void save();
    DLL_API void delete_file(const char* path);
    DLL_API void count_words(const char* path);
    DLL_API void write(const char* path, const char* str);
}

#endif
