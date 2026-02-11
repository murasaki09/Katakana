#include <stdio.h>
#include "parser.h"
#include "lexer.h"

// 単語（トークン）識別
static Token currentToken;

// 構文解析
void parser_run(void) {
    // 単語を取得
    currentToken = lexer_next();
    // 空文字以外
    while (currentToken.type != TOK_EOF) {
        switch (currentToken.type)
        {
            case TOK_PRINT:
                currentToken = lexer_next();
                if(currentToken.type == TOK_STRING){
                    printf("%s\n", currentToken.text);
                    currentToken = lexer_next();
                }
                break;
            case TOK_SEMI:
                currentToken = lexer_next();
                break;
            default:
                currentToken = lexer_next();
                break;
        }
        
    }
}