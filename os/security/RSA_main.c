#include "RSA.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

int main()
{
	unsigned char* plainText = (unsigned char*)"Hello World!";
	size_t size = strlen((char*)plainText) + 1;
        int* encryptedText = (int*)malloc(size * sizeof(int));
        unsigned char* decryptedText = (unsigned char*)malloc(size);
	memset((char*)encryptedText, 0, size);
	memset((char*)decryptedText, 0, size);
	int e = 10651;
	int d = 23443;
	int n = 117151;
	//RSA_GenKey(&e, &d, &n);
	printf("key pair(e, d, n): (%d, %d, %d)\n", e, d , n);
	rsa_key_t pub_key = {e, n};
	rsa_key_t pri_key = {d, n};
	printf("plainText:%s\n", plainText);
	int en_result = RSA_Encrypt(RSA_USE_PUB_KEY, pub_key, 
                plainText, size, encryptedText);
	int index = 0;
	printf("result:%d, encrypted data:\n", en_result);
	for (index = 0; index < size; ++index) {
		printf("0x%08x ", encryptedText[index]);
	}
	printf("\n");
	int de_result = RSA_Decrypt(RSA_USE_PRI_KEY, pri_key, 
                encryptedText, en_result, decryptedText);
	printf("decryptedText:%s, result:%d\n", decryptedText, de_result);
}
