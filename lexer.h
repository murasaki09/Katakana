#ifndef LEXER_H
#define LEXER_H

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

void lexer_init(const char *source);
Token lexer_next(void);

#endif
