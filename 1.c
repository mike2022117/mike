#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 
#include <sys/types.h> 
#if __MINGW32__
#include <winsock2.h>
typedef unsigned int socklen_t;
#else
#include <sys/socket.h> 
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

int main(int argc,char *argv[]){ 
    int sid;
    ssize_t num;
    struct sockaddr_in addr;

#ifdef __MINGW32__ 
    WSADATA wsaData; 
    WSAStartup(MAKEWORD(2 ,0), &wsaData); 
#endif
    if((sid = socket(AF_INET, SOCK_STREAM, 0)) < 0){ 
        perror("Error: socket()");
        exit(-1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2])); 
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sid, (struct sockaddr *)&addr, sizeof(addr)) != 0) { 
        perror("Error: connect()");
        exit(-1);
    }

    char mojiretu[10000];
    char buf[10000];
    printf("チャットを開始します\n");
    printf("番号を入力するとスタンプを送れます\n");
    printf("01:(^O^)ノ\n");
    printf("02:( >_< )\n");
    printf("03:(￣^￣)ゞ\n");
    printf("04:m(*_ _)m\n");
    printf("05:(((;° Д °;)))\n");
    printf("06:_(-ω-`_)⌒ )_\n");
    printf("07:(∩^o^)⊃ ≡≡≡≡≡≡≡≡☆\n");
    printf("byeと入力すると終了します\n");

    while(1){
        memset(mojiretu,0,sizeof(mojiretu));
        fgets(mojiretu,10000,stdin);
        
        int x = atoi(mojiretu);
        char *st;
        switch(x){
            case 01:
                st = "(^O^)ノ\n";
                strcpy(mojiretu,st);
                printf("(^O^)ノを送信しました\n");
                break;
            case 02:
                st = "( >_< )\n";
                strcpy(mojiretu,st);
                printf("( >_< )を送信しました\n");
                break;
            case 03:
                st = "(￣^￣)ゞ\n";
                strcpy(mojiretu,st);
                printf("(￣^￣)ゞを送信しました\n");
                break;
            case 04:
                st = "m(*_ _)m\n";
                strcpy(mojiretu,st);
                printf("m(*_ _)mを送信しました\n");
                break;
            case 05:
                st = "(((;° Д °;)))\n";
                strcpy(mojiretu,st);
                printf("(((;° Д °;)))を送信しました\n");
                break;
            case 06:
                st = "_(-ω-`_)⌒ )_\n";
                strcpy(mojiretu,st);
                printf("_(-ω-`_)⌒ )_を送信しました\n");
                break;
            case 07:
                st = "(∩^o^)⊃ ≡≡≡≡≡≡≡≡☆ \n";
                strcpy(mojiretu,st);
                printf("(∩^o^)⊃ ≡≡≡≡≡≡≡≡☆ を送信しました\n");
                break;
            default:
                break;
        }

        num = send(sid,mojiretu,strlen(mojiretu),0);
        if (num < 0) {
            perror("Error: send()"); 
            exit(-1);
        }

        char BYE[] = "bye\n";
        if(strcmp(BYE,mojiretu)==0){
            return 0;
        }

        memset(buf,0,sizeof(buf));
        num = recv(sid, buf, sizeof(buf), 0);
        if (num < 0) {
            perror("Error: recv()");
            exit(-1);
        }
        printf("%s", buf);

        if(strcmp(BYE,buf)==0){
            return 0;
        }
    }


#ifdef __MINGW32__
    closesocket(sid); 
    WSACleanup(); 
#else
    close(sid);
#endif
    return 0;
}