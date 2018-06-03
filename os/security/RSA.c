#include "RSA.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

//#define RSA_DEBUG

//二进制转换
static int BianaryTransform(int num, int bin_num[])
{
    int i = 0,  mod = 0;

    //转换为二进制，逆向暂存temp[]数组中
    while(num != 0)
    {
        mod = num%2;
        bin_num[i] = mod;
        num = num/2;
        i++;
    }

    //返回二进制数的位数
    return i;
}

//反复平方求幂
static long long Modular_Exonentiation(long long a, int b, int n)
{
    int c = 0, bin_num[1000];
    long long d = 1;
    int k = BianaryTransform(b, bin_num)-1;

    for(int i = k; i >= 0; i--)
    {
        c = 2*c;
        d = (d*d)%n;
        if(bin_num[i] == 1)
        {
            c = c + 1;
            d = (d*a)%n;
        }
    }
#ifdef RSA_DEBUG
    cout << "value a:" << a << "->" << d << endl;
#endif
    return d;
}

//RSA加密
int RSA_Encrypt(rsa_key_e key_type, rsa_key_t key, 
                const unsigned char* data, int data_len, int* output)
{
    int e = 0;
    int n = 0;
    if (key_type == RSA_USE_PRI_KEY) {
  	e = key.key.pri.pri;  
        n = key.key.pri.n;
    } else if (key_type == RSA_USE_PUB_KEY) {
  	e = key.key.pub.pub;  
        n = key.key.pub.n;
    } else {
        return 0;
    }
    int i = 0;
    for(i = 0; i < data_len; i++) {
        output[i] = Modular_Exonentiation(data[i], e, n);
    }
#ifdef RSA_DEBUG
    cout<<"Use the key (e, n) to encrypt:"<< "(" << e << ", " << n << ")" << endl;
    for(i = 0; i < data_len; i++)
        cout<<output[i]<<" ";
    cout<<'\n'<<'\n';
#endif
    return data_len;
}

//RSA解密
int RSA_Decrypt(rsa_key_e key_type, rsa_key_t key, 
                const int* data, int data_len, unsigned char* output)
{
    int d = 0;
    int n = 0;
    if (key_type == RSA_USE_PRI_KEY) {
  	d = key.key.pri.pri;  
        n = key.key.pri.n;
    } else if (key_type == RSA_USE_PUB_KEY) {
  	d = key.key.pub.pub;  
        n = key.key.pub.n;
    } else {
        return 0;
    }
    int i = 0;
    for(i = 0; i < data_len; i++) {
        output[i] = Modular_Exonentiation(data[i], d, n);
    }
#ifdef RSA_DEBUG
    cout <<"Use the key (d, n) to decrypt:"<< "(" << d << ", " << n << ")" << endl;
    for(i = 0; i < data_len; i++)
        cout<<output[i]<<" ";
    cout<<'\n'<<'\n';
#endif
    return data_len;
}

#ifdef RSA_DEBUG
//生成1000以内素数
int ProducePrimeNumber(int prime[])
{
    int c = 0, vis[1001];
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i <= 1000; i++)if(!vis[i])
    {
        prime[c++] = i;
        for(int j = i*i; j <= 1000; j+=i)
            vis[j] = 1;
    }

    return c;
}


//欧几里得扩展算法
int Exgcd(int m,int n,int &x)
{
    int x1,y1,x0,y0, y;
    x0=1; y0=0;
    x1=0; y1=1;
    x=0; y=1;
    int r=m%n;
    int q=(m-r)/n;
    while(r)
    {
        x=x0-q*x1; y=y0-q*y1;
        x0=x1; y0=y1;
        x1=x; y1=y;
        m=n; n=r; r=m%n;
        q=(m-r)/n;
    }
    return n;
}

//RSA初始化
void RSA_GenKey(int *e, int *d, int *n)
{
    //取出1000内素数保存在prime[]数组中
    int prime[5000];
    int count_Prime = ProducePrimeNumber(prime);

    //随机取两个素数p,q
    srand((unsigned)time(NULL));
    int ranNum1 = rand()%count_Prime;
    int ranNum2 = rand()%count_Prime;
    int p = prime[ranNum1], q = prime[ranNum2];

    *n = p*q;

    int On = (p-1)*(q-1);


    //用欧几里德扩展算法求e,d
    for(int j = 3; j < On; j+=1331)
    {
        int gcd = Exgcd(j, On, *d);
        if( gcd == 1 && *d > 0)
        {
            *e = j;
            break;
        }

    }

}
#endif
