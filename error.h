#ifndef ERROR_H
#define ERROR_H

typedef enum {
    TOK_EOF,
    TOK_PRINT,
    TOK_STRING,
    TOK_SEMI
} TokenType;

typedef struct {
    TokenType type;
    char *text;
} Token;

void not_semi_coron(void);

#endif