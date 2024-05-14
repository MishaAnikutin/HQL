#include "token.h"


Regex RegexTokenMapper[] = {
    "[0-9]*",                          // NUMBER
    "[a-z]*",                          // NAME
    "[CREATE|DROP|SELECT|INSERT]",     // COMMAND, i will implement other in the future ... 
    ";",                               // SEMICOLON
    "[ \n\t\r]",                       // SPACE
    "[=|>=|<=|>|<]",                   // ASSIGN
    "[+|-|*|/]",                       // OPERATOR
    "(",                               // LPAR
    ")"                                // RPAR
};
