#include <stdio.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    struct hostent *hp = gethostbyname("device.iot.baidu.com");
    if (!hp) {
        herror("error");
    } else {
        printf("got ip!!\n");
    }
    return 0;
}
