import threading
from ctypes import CDLL, c_char_p

# загружаем библиотеку
file = CDLL("D:\\proect_dll\\Proect_dll\\x64\\Debug\\Proect_dll.dll")
# Указываем типы аргументов и возвращаемых значений
file.open_file.argtypes = [c_char_p]
file.open_file.restype = None
file.close_file.restype = None
file.save.restype = None
# путь к файлу
path = b"D:\\proect_dll\\test.txt"

def open_file_thread():
    file.open_file(path)

while True:
    var = int(input('''Выберите вариант:
1 - открыть файл
2 - закрыть файл
3 - сохранить файл

Вариант: '''))

    if var == 1:
        threading.Thread(target=open_file_thread, daemon=True).start()
    # закрыть файл
    elif var == 2:
        file.close_file()
    # сохранить файл
    elif var == 3:
        file.save()
    else:
        print("Выберите вариант от 1 до 3")
