#ifdef STATUS_CODES_H
#define STATUS_CODES_H

enum DMLStatusCode
{
    SUCCEED,      
    NAME_ERROR,   // ошибка имени, нет такого стобца/таблицы
    TYPE_ERROR,   // ошибка типов (передали "abc" в столбец типа INT)
    VALUE_ERROR,  // ошибка значения (умножили 1 на "abc")
    MEMORY_ERROR  // ошибка выделения памяти
};

enum DDLStatusCode
{
    SUCCEED,      
    NAME_ERROR,   // ошибка имени, нет такого стобца/таблицы
    MEMORY_ERROR  // ошибка выделения памяти
};

#endif