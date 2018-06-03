#ifndef __DES_H_
#define __DES_H_

typedef enum {
    DES_CRYPT_ENCRYPT = 0,
    DES_CRYPT_DECRYPT = 1,
} des_crypt_mode_t;

/**
 *desc DES crypt agorithom
 *@param mode, en/de, 0 en, 1 de
 *@param key, the key used to en/de, should be 8 bytes
 *@param data, the buffer where input data stores
 *@param data_len, the length of @data, best be time of 8
 *@param output, the buffer has enough space to stores the output data
 *@return lenght of output
 */
int DES_crypt(des_crypt_mode_t mode,
               const unsigned char key[8],
               const unsigned char *data, int data_len,
               unsigned char *output);

/**
 *desc encryption, the lengh for the input param is 8 bytes
 *@param input, the data will be encrypted,
 *@param key_in, the key use to encrypt
 *@param result, the encrypted text
 */
void  DES_Efun(const unsigned char input[8],
               const unsigned char key_in[8],
               unsigned char result[8]);

/**
 *desc decryption, the lengh for the input param is 8 bytes
 *@param data, the enctypted text
 *@param key_in, the key use to decrypt
 *@param output, the plain text
 */
void  DES_Dfun(const unsigned char data[8],
               const unsigned char key_in[8],
               unsigned char output[8]);

#endif // __DES_H_
