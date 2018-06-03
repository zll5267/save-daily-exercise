#ifndef __RSA_H_
#define __RSA_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _rsa_pub_key {
    int pub;
    int n;
} rsa_pub_key_t;

typedef struct _rsa_pri_key {
    int pri;
    int n;
} rsa_pri_key_t;

typedef enum _rsa_key_enum {
    RSA_USE_PUB_KEY = 0,
    RSA_USE_PRI_KEY = 1,
} rsa_key_e;

typedef struct _rsa_key {
    union {
        rsa_pub_key_t pub;
        rsa_pri_key_t pri;
    }key;
} rsa_key_t;

int RSA_Encrypt(rsa_key_e key_type, rsa_key_t key, 
                const unsigned char* data, int data_len, int* output);

int RSA_Decrypt(rsa_key_e key_type, rsa_key_t key, 
                const int* data, int data_len, unsigned char* output);

void RSA_GenKey(int*, int*, int*);

#ifdef __cplusplus
}
#endif

#endif // __RSA_H_
