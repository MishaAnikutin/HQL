#ifndef TOKEN_H
#define TOKEN_H


typedef enum {
    NUMBER,
    NAME,
    COMMAND,
    SEMICOLON,
    SPACE,
    ASSIGN,
    OPERATOR,
    LPAR,
    RPAR
} EnumTokenTypes;

typedef Regex const char*;

extern Regex RegexTokenMapper[]; // mapping token to regular expression 

typedef
struct TokenType
{
    enum EnumTokenTypes name;    // name of token type 
    Regex regex;                 // regular expression of token
};

typedef
struct Token
{
    struct TokenType type;       // token type
    char* text;                  // text of token 
    int line;                    // position of token in request
} token_t;


#endif