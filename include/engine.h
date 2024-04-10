#ifndef ENGINE_H
#define ENGINE_H
/* Definition of QuickFlow engine */

#define INT_T int 
#define UINT_T unsigned int  
#define CHAR_T char 
#define FLOAT_T float 


/* Enum of columns data types*/
typedef enum columns_types 
{
    QF_INT,
    QF_UINT,
    QF_CHAR,
    QF_FLOAT 
} coltype_t;


/* Structure of column */ 
typedef struct
{
    char*       c_name;   // column name 
    coltype_t   c_stype;  // column string of type
    void*       data;     // column data
    int         data_size;
    int         data_capacity;
} column_t;


/* Structure of table */ 
#define MAX_COLUMNS 1024
typedef struct
{
    char*     t_name; 
    column_t* columns[MAX_COLUMNS];
    int       shape[2]; // [columns, rows]
} table_t;


#endif