#include "lexer.h"

lexer_t* 
initLexer(char *code)
{   
    lexer_t* Lexer = (lexer_t*) malloc(sizeof(lexer_t));
    if (Lexer == NULL)
        printf("Не удалось выделить память на лексер\n");
    
    Lexer->code = (char*) malloc(sizeof(char));
     if (Lexer->code == NULL)
        printf("Не удалось выделить память на текст лексера\n");

    memcpy(Lexer->code, code, strlen(code));
    return Lexer;
}

token_t**
lexAnalysis(lexer_t* lexer)
{
    token_t* token = (token_t*) malloc(sizeof(token_t));

    while ((token = nextToken(lexer->code)) != NULL)
    {

    }
}


token_t*
nextToken(char* code)
{

}
