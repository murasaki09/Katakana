#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

// ファイル内の全文字（1文字単位）
static const char *src;
// 文字位置
static size_t pos;

// 文字を格納、文字位置を0に固定
void lexer_init(const char *source) 
{ 
    src = source; 
    pos = 0; 
}

// 空白文字判定
static void skip_ws(void) { 
    // 文字が空白か判定
    while (isspace(src[pos]))
    {
        // 空白のときは１文字進める 
        src[pos++]; 
    }
}

Token lexer_next(void) {
    // 空白の場合、次の文字を取得
    skip_ws();
    // 現在位置を取得
    char c = src[pos];
    // 文字が末端文字の場合
    if (c == '\0') 
    {
        return (Token){TOK_EOF, NULL};
    }

    // 文字がアルファベットの場合
    if (isalpha(c)) {
        char buf[64]; 
        int i=0;
        // 文字がアルファベットor数字の場合
        while (isalnum(src[pos])) 
        {
            // 次の文字を取得
            buf[i++] = src[pos++];
        }
        buf[i] = 0;
        // 文字列を比較して
        if (!strcmp(buf,"print")) 
        {
            return (Token){TOK_PRINT, NULL};
        }
        return (Token){TOK_EOF,NULL};
    }
    // ダブルクォーテーションの場合
    if (c=='"') {
        // 次の文字を取得
        src[pos++];
        char buf[256]; 
        int i=0;
        // 文字がダブルクォーテーションじゃないとき
        while(src[pos] && src[pos]!='"') {
            buf[i++] = src[pos++];
        }
        // 次の文字を取得
        src[pos++];
        buf[i]=0;
        return (Token){TOK_STRING,strdup(buf)};
    }

    // セミコロンの場合
    if (c==';')
    { 
        src[pos++]; 
        return (Token){TOK_SEMI,NULL}; 
    }

    return (Token){TOK_EOF,NULL};
}
