#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"

char *read_file(const char *path){
    // ファイルオープン（バイナリで読み込む）
    FILE *f = fopen(path,"rb");
    // ファイルポインタの最後の位置を取得
    fseek(f,0,SEEK_END);
    // ファイルのサイズを取得
    long sz = ftell(f);
    // ファイルポインタを最初に戻す
    rewind(f);
    // ファイルサイズ +1(文字列終端(\0)分) バイトのメモリを確保
    char *buf = malloc(sz+1);
    // ファイルからファイルサイズ分データを取得
    fread(buf,1,sz,f);
    // 末尾に0を格納 → 生データしか読み込めないため末端文字を格納する
    buf[sz]=0;
    // ファイルを閉じる
    fclose(f);
    return buf;
}

int main(int argc,char **argv){
    char *text = read_file(argv[1]);
    // 文字を取得
    lexer_init(text);
    // 構文解析
    parser_run();
    return 0;
}
