#include <stdio.h>
#include <string.h>
#include "DES.h"

int main(){

//    0000 0001 0010 0011 0100 0101 0110 0111
//    1000 1001 1010 1011 1100 1101 1110 1111
    unsigned char output[8]={0};
    //unsigned char MIN[9]={0};
    //unsigned char MI[9]={0};
    unsigned char MIN[9]={0x01, 0x23, 0x45, 0x67,
                          0x89, 0xAB, 0xCD, 0xEF
                         };
    unsigned char MI[9]={0x01, 0x23, 0x45, 0x67,
                          0x89, 0xAB, 0xCD, 0x00
                         };
    unsigned char MIN_OUT[9] = {0};
    //printf("请输入明文\n");
    //gets(MIN);

    //printf("请输入秘钥\n");
    //gets(MI);
    printf("原始明文如下:\n");
    for(int i=0;i<8;i++){
        printf("0x%02x ",MIN[i]);
    }
    printf("\n");
    printf("加密功能\n");
    DES_Efun(MIN,MI,output);
    printf("密文如下:\n");
    for(int i=0;i<8;i++){
        printf("0x%02x ",output[i]);
    }
    printf("\n");
    printf("解密功能\n");
    DES_Dfun(output,MI,MIN_OUT);
    printf("解密明文如下:\n");
    for(int i=0;i<8;i++){
        printf("0x%02x ",MIN_OUT[i]);
    }
    printf("\n");
    printf("==================\n");
    const unsigned char *key = "12345678";
    const unsigned char *plain_text = "Hello world!!";
    unsigned char secret_text[32] = {0};
    unsigned char new_plain_text[32] = {0};
    printf("key:%s;plain_text:%s\n", key, plain_text);

    int length = DES_crypt(DES_CRYPT_ENCRYPT, key,
                           plain_text, strlen(plain_text),
                           secret_text);
    if (length == 0) {
        printf("encrypt fail!!\n");
        return 0;
    }
    printf("secret:\n");
    for (int i = 0; i < length; ++i) {
        printf("%02x ", secret_text[i]);
    }
    printf("\n");
    DES_crypt(DES_CRYPT_DECRYPT, key,
              secret_text, length,
              new_plain_text);
    printf("decrypted text:%s\n", new_plain_text);
    printf("==================\n");


    return 0;
}
