#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define PORT 7000

#define QUEUE 20

int conn = -1;

int main() {
    //printf("%d\n",AF_INET);
    //printf("%d\n",SOCK_STREAM);
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    //printf("%d\n",ss);
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    printf("port:%d\n", PORT);
    server_sockaddr.sin_port = htons(PORT);
    //printf("%d\n",INADDR_ANY);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr))==-1) {
        perror("bind");
        exit(1);
    }
    if(listen(ss, QUEUE) == -1) {
        perror("listen");
        exit(1);
    }

    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);

    char buffer[1024];
    //创建另外一个线程
    //std::thread t(thread_task);
    //t.join();
    //char buf[1024];
    //主线程
    while(1) {
		///成功返回非负描述字，出错返回-1
        if (conn == -1) {
            conn = accept(ss, (struct sockaddr*)&client_addr, &length);
            if( conn < 0 ) {
                perror("connect");
                exit(1);
            }
        }

        // memset(buf, 0 ,sizeof(buf));
        // if(fgets(buf, sizeof(buf),stdin) != NULL) {
        //     send(conn, buf, sizeof(buf), 0);
        // }

        memset(buffer, 0 ,sizeof(buffer));
        int len = recv(conn, buffer, sizeof(buffer), 0);
        printf("%s\n", buffer);
        if(strcmp(buffer, "exit\n") == 0) {
            printf("close and exit\n");
			close(conn);
            conn = -1;
			continue;
		}
        //必须要有返回数据， 这样才算一个完整的请求
        send(conn, buffer, len , 0);
    }
    close(ss);
    return 0;
}
