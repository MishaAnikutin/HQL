# QuickFlow
Учебный проект в рамках изучения языка Си и работы СУБД с Алексеем Владимировичем Жильчиковым 😎

# Описание проекта:
QuickFlow - быстрая колоночная In-memory СУБД с SQL-подобным языком запросов написанная на языке C. 

Предполагается, что в итоге она станет "Middleware СУБД", т.е. слоем между клиентом и другой СУБД (PostgreSQL, MySQL, etc) 

_возможно, потом будет форк на C++ для более удобной разработки_

Идейными вдохновителями проекта являются ClickHouse, Tarantool и Redis

## Use-cases:
- Преимущественно для ETL задач: Загрузка необработанных данных, валидация, агрегация данных и пр.
- Для потоковой обработки данных, временного быстрого хранилища
- Быстрая работа с маленькими данными


## Первичные требования: 
### Parser:
- [ ] Определены основные операторы:
   - [ ] Сложение
   - [ ] Вычитание
   - [ ] Умножение
   - [ ] Возведение в степень
- [ ] Определены основные математические функции:
   - [ ] min, max
   - [ ] pow
   - [ ] log
   - [ ] abs

### Core:
- [ ] Реализован API для работы с движком QF:
   - [x] **Tablespace:**
      + [x] getTablespaceInstance
      + [x] addTableToTablespace
      + [x] getTableFromTablespace
      + [x] removeTableFromTablespace
      + [x] checkTableInTablespace
   - [x] **Table:**
      + [x] createTable
      + [x] getColumnFromTable
      + [x] dropTable  
   - [x] **Column:**
      + [x] createColumn
      + [x] dropColumn  
- [ ] Реализован API для задач DDL:
   - [x] CREATE
   - [x] DROP
   - [ ] ALTER
- [ ] Реализован API для задач DML:
   - [x] INSERT
   - [x] SELECT 
   - [ ] UPDATE 
   - [ ] DELETE
- [ ] Столбцы поддерживают 6 основных типов:
   - [x] INT
   - [x] UINT
   - [x] CHAR
   - [x] FLOAT
   - [x] TEXT
   - [ ] VARCHAR()
- [ ] Имеет открытый Docker образ, размещенный на Dockerhub 

## Дальнейшее развитие:
- [ ] Реализовать асинхронную работу в обработке запросов
- [ ] Добавить дополнительные типы: Datetime, Date, Timestamp 
- [ ] Добавить JOIN'ы
- [ ] Добавить GROUP BY и AGGREGATE 
- [ ] Реализовать возможность создавать вложенные запросы
- [ ] Добавить клиент для создания кастомных функций в некоторых языках программирования: Python, R

# Структура проекта и архитектура
Проект имеет архитекруту MVC:
- За уровень представления отвечают модули CLI и TCP сервер из ./repl
- DDL, DML, AST, Parser, engine (весь домен) находится в ./core
- Для общения между слоями написаны структуры в ./models

Рассмотрим на примере работы CREATE TABLE:

1. Запрос приходит по TCP подключению, или по CLI, например: `CREATE TABLE users (username TEXT, salary UINT);`.

Далее, он проверяется на синтаксис и раскладывается на команды в ядро. Парсер отправляет запрос в DDL/DML через API:
```C
create_response_t 
create(
    char* t_name,
    char* column_names[MAX_COLUMNS], 
    char* column_types[MAX_COLUMNS],
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
column_t* createColumn(char* c_name, enum ColumnsTypes c_stype);
table_t* createTable(char* t_name, column_t** columns, size_t n_col);
```

т.е. на этом слое уже оперируют структурами движка, а не строками запроса

## Примеры
В папке ./examples лежат примеры (написанные на языке Python)

Примеры написаны на Python, поскольку язык очень читаемый, и даже если у вас не было с ним опыта, все равно будет понятно что происходит

## Тесты
- В src/core/engine/tests лежат тесты API DDL, DML и движка QF
- В src/core/parser/tests лежат тесты AST и парсера (пока нет)

# Benchmark's
_тут что то будет потом_
