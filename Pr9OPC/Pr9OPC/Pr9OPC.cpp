#include <iostream>
#include <windows.h>
#include "sqlite3.h"

int main() {
    // Встановлюємо кодування консолі для підтримки кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    sqlite3* db;
    char* errorMessage = nullptr;

    int rc = sqlite3_open("mydb.db", &db);

    if (rc) {
        std::cerr << "Не вдалося відкрити базу: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    else {
        std::cout << "Базу даних створено або відкрито успішно!" << std::endl;
    }

    const char* createTableSQL =
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "grade INTEGER);";

    rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errorMessage);

    if (rc != SQLITE_OK) {
        std::cerr << "Помилка створення таблиці: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
    }
    else {
        std::cout << "Таблицю 'students' створено успішно!" << std::endl;
    }

    sqlite3_close(db);
    return 0;
}

