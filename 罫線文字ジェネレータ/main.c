//ライブラリ
#include <stdio.h>
#include <string.h>
#include "dict.h"

//本体
int main(void){
    
    init_dict();

    //入力
    char mode[4] = {}, inst[100] = {};
    scanf("%s", mode);
    getchar();
    fgets(inst, sizeof(inst), stdin);
    inst[strcspn(inst, "\n")] = '\0';
    
    if(strcmp(mode, "横") == 0){
        for(int cnt = 1; cnt <= 8; cnt++){
            for(int cnt2 = 0; cnt2 < strlen(inst); cnt2++){
                char cnts =inst[cnt2];
                char cnt2s = '0' + cnt;
                printf("%s ", dict[0][(unsigned char)cnts][(unsigned char)cnt2s]);
            }
            printf("\n");
        }
    } else if(strcmp(mode, "縦") == 0){
        int num = strlen(inst);
        for(int cnt = 0; cnt < num; cnt++){
            unsigned char ch = inst[cnt];
            for(int cnt2 = 1; cnt2 <= 4; cnt2++){
                char line = '0' + cnt2;   // ★ 文字キーに変換
                const char *p = dict[1][ch][line];
                if(p != NULL && p[0] != '\0'){printf("%s\n", p);}
            }
        }
    }

 else printf(" 入力形式に誤りがあります。入力は次の形式で表記してください。\n   [縦 or 横]\n   [変換したい文字列]\n入力に括弧は不要です。");
    return 0;
}