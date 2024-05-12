# QuickFlow
Учебный проект в рамках изучения языка Си и работы СУБД с Алексеем Владимировичем Жильчиковым 😎

# Описание проекта:
QuickFlow - быстрая колоночная In-memory СУБД для ETL процессов с SQL-подобным языком запросов написанная на языке C

_возможно, потом будет форк на C++ для более удобной разработки_

Идейными вдохновителями проекта являются ClickHouse и Redis

## Use-cases:
- Преимущественно для ETL задач: Загрузка необработанных данных, валидация, агрегация данных и пр.
- Для потоковой обработки данных, временного быстрого хранилища
- Быстрая работа с маленькими данными


## Первичные требования: 
### Parser:
- [] Определены основные операторы:
   - [] Сложение
   - [] Вычитание
   - [] Умножение
   - [] Возведение в степень
- [] Определены основные математические функции:
   - [] min, max
   - [] pow
   - [] log
   - [] abs

### Core:
- [] Реализован API для задач DDL:
   - [] CREATE
   - [] DROP
   - [] ALTER
- [] Реализован API для задач DML:
   - [] INSERT
   - [] SELECT 
   - [] UPDATE 
   - [] DELETE
- [] Поддерживать 4 основных типа:
   - [] INT
   - [] UINT
   - [] CHAR
   - [] FLOAT
   - [] TEXT
   - [] VARCHAR()
- [] Имеет открытый Docker образ, размещенный на Dockerhub 

## Дальнейшее развитие:
- [] Добавить асинхронную работу в обработке запросов
- [] Добавить дополнительные типы: Datetime, Date, Timestamp 
- [] Добавить Join'ы (inner, outer)
- [] Добавить GroupBy и Aggregate 
- [] Реализовать возможность создавать вложенные запросы
- [] Добавить клиент для создания кастомных функций в некоторых языках программирования: Python, R

# Структура проекта и архитектура
Проект имеет архитекруту MVC:
- За уровень представления отвечают модули CLI и TCP сервер из ./repl
- За DDL, DML, AST, Parser, engine (весь домен) находится в ./core
- Для общения между слоями - структуры в ./models

Рассмотрим на примере работы CREATE TABLE:

1. Запрос приходит по TCP подключению, или по CLI, например: `CREATE TABLE users (username TEXT, salary UINT);`.

Далее, он проверяется на синтаксис и раскладывается на команды в ядро. Парсер отправляет запрос в DDL/DML через API:
```C
create_response_t 
create(
    char* t_name,
    char* column_names[MAX_COLUMNS], 
    enum ColumnsTypes column_types[MAX_COLUMNS],
    size_t n_col,
    bool if_not_exists
)
```

Для общения ядра и парсера реализованы модели:

```C
typedef
struct CreateResponse
{
    enum DDLStatusCode status_code,
    char* message;
} create_response_t;
```

Сам движок QF изолирован от парсера слоем DML/DDL. Внутри DML/DDL происходят вызовы API движка QF:


```C
if (if_not_exists && checkTableInTablespace(t_name))
   return response_builder(DDLStatusCode.NAME_ERROR, "Table with name already exisis");

column_t* columns[MAX_COLUMNS];

for (size_t i = 0; i < n_col; ++i)
{
   column_t* column_i = createColumn(column_names[i], column_types[i]);
   if (column_i == NULL) 
      return response_builder(DDLStatusCode.TYPE_ERROR, "Unsupported data type");


   columns[i] = column_i;
}

table_t* table = createTable(t_name, columns, n_col);

if (table == NULL)
   return response_builder(DDLStatusCode.MEMORY_ERROR, "Memory error");

addTableToTablespace(table);
```


## Примеры
В папке ./examples лежат примеры (написанные на языке Python)

Примеры написаны на Python, поскольку язык очень читаемый, и даже если у вас не было с ним опыта, все равно будет понятно что происходит

## Тесты
- В src/core/engine/tests лежат тесты API DDL, DML и движка QF
- В src/core/parser/tests лежат тесты AST и парсера (пока нет)

# Benchmark's
_тут что то будет потом_
