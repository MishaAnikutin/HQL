#ifndef LEXER_H
#define LEXER_H

#include "../../models/parser/token.h"


typedef
struct Lexer 
{
    char*    code;     
    size_t   line;
    token_t** tokenList;
    size_t   len;
    size_t   capacity;
} lexer_t;

lexer_t* initLexer(char* code);
token_t** lexAnalysis(lexer_t* lexer);

#endif 