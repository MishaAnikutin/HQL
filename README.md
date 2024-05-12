# QuickFlow
## **QuickFlow** - быстрая колоночная In-memory СУБД с SQL-подобным языком запросов написанная на языке C. 
- Учебный проект в рамках изучения языка C, работы СУБД и реляционной алгебры с Алексеем Владимировичем Жильчиковым 😎
- Предполагается, что в итоге она станет __"Middleware СУБД"__. _т.е. слоем между клиентом и другой СУБД (PostgreSQL, MySQL, etc)_
- _возможно, потом будет форк на C++ для более удобной разработки_
- Идейными вдохновителями проекта являются: __ClickHouse, Tarantool и Redis__

## Use-cases:
- Data Middleware (Слой между клиентом и СУБД. Например, для быстрой изолированной агрегации запросов, __aka Relational Data Middleware__)
- Для ETL задач: Загрузка необработанных данных, валидация, агрегация данных и пр.
- Быстрого временного хранилища
- Просто как СУБД

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

## Разграничение ответственности по слоям
Рассмотрим работу на примере команды `CREATE TABLE users (username TEXT, salary UINT);`:

1. Запрос приходит по TCP подключению или по CLI

2. Далее, он проверяется лексически и синтаксически, если все хорошо, то раскладывается на команды в ядро.

3. Парсер отправляет запрос в DDL через API:
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

4. Для общения ядра и парсера реализованы модели:

   ```C
   typedef
   struct CreateResponse
   {
       enum DDLStatusCode status_code,
       char* message;
   } create_response_t;
   ```
   Сам движок QF изолирован от парсера слоем DDL. Внутри DDL происходят вызовы API движка QF:

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
