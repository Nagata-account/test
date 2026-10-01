/*定義*/
#include <stdio.h>
#include <string.h>
#include "dict.h"

/*スペース変換関数 (half to full)*/
const char* converter(const char *src);
const char* converter(const char *src) {
    static char buf[512];
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == ' ') {
            buf[j++] = 0xE3;
            buf[j++] = 0x80;
            buf[j++] = 0x80;
        } else {buf[j++] = src[i];}
    }
    buf[j] = '\0';
    return buf;
}

/*本体*/
int main(void){
    init_dict();
    char mode[4] = {}, hof[4] = {}, inst[100] = {};
    scanf("%s %s", mode, hof);
    getchar();
    fgets(inst, sizeof(inst), stdin);
    inst[strcspn(inst, "\n")] = '\0';
    if(strcmp(mode, "横") == 0){
        for(int cnt = 1; cnt <= 8; cnt++){
            for(int cnt2 = 0; cnt2 < strlen(inst); cnt2++){
                char cnts = inst[cnt2];
                char cnt2s = '0' + cnt;
                const char *raw = dict[0][(unsigned char)cnts][(unsigned char)cnt2s];
                if(strcmp(hof, "半") == 0){
                    printf("%s ", raw);
                } else if(strcmp(hof, "全") == 0){
                    printf("%s ", converter(raw));
                } else {
                    printf(" 入力形式に誤りがあります。入力は次の形式で表記してください。\n   [縦 or 横] [半 or 全]\n   [変換したい文字列]\n入力に括弧は不要です。");
                    return 0;
                }
            }
            printf("\n");
        }
    } else if(strcmp(mode, "縦") == 0){
        int num = strlen(inst);    
        for(int cnt = 0; cnt < num; cnt++){    
            unsigned char ch = inst[cnt];    
            for(int cnt2 = 1; cnt2 <= 4; cnt2++){
                char line = '0' + cnt2;
                const char *p = dict[1][ch][line];    
                if(p != NULL && p[0] != '\0'){
                    if(strcmp(hof, "半") == 0){
                        printf("%s\n", p);
                    } else if(strcmp(hof, "全") == 0){
                        printf("%s\n", converter(p));
                    } else {
                        printf(" 入力形式に誤りがあります。入力は次の形式で表記してください。\n   [縦 or 横] [半 or 全]\n   [変換したい文字列]\n入力に括弧は不要です。");
                        return 0;
                    }
                }
            }
        }
    } else {
        printf(" 入力形式に誤りがあります。入力は次の形式で表記してください。\n   [縦 or 横] [半 or 全]\n   [変換したい文字列]\n入力に括弧は不要です。");
    }
    return 0;
}