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
    printf("ƒ`ƒƒƒbƒg‚ðŠJŽn‚µ‚Ü‚·\n");
    printf("”Ô†‚ð“ü—Í‚·‚é‚ÆƒXƒ^ƒ“ƒv‚ð‘—‚ê‚Ü‚·\n");
    printf("01:(^O^)ƒm\n");
    printf("02:( >_< )\n");
    printf("03:(P^P)U\n");
    printf("04:m(*_ _)m\n");
    printf("05:(((;‹ „D ‹;)))\n");
    printf("06:_(-ƒÖ-`_)Ü )_\n");
    printf("07:(¿^o^)½ ßßßßßßßß™\n");
    printf("bye‚Æ“ü—Í‚·‚é‚ÆI—¹‚µ‚Ü‚·\n");

    while(1){
        memset(mojiretu,0,sizeof(mojiretu));
        fgets(mojiretu,10000,stdin);
        
        int x = atoi(mojiretu);
        char *st;
        switch(x){
            case 01:
                st = "(^O^)ƒm\n";
                strcpy(mojiretu,st);
                printf("(^O^)ƒm‚ð‘—M‚µ‚Ü‚µ‚½\n");
                break;
            case 02:
                st = "( >_< )\n";
                strcpy(mojiretu,st);
                printf("( >_< )‚ð‘—M‚µ‚Ü‚µ‚½\n");
                break;
            case 03:
                st = "(P^P)U\n";
                strcpy(mojiretu,st);
                printf("(P^P)U‚ð‘—M‚µ‚Ü‚µ‚½\n");
                break;
            case 04:
                st = "m(*_ _)m\n";
                strcpy(mojiretu,st);
                printf("m(*_ _)m‚ð‘—M‚µ‚Ü‚µ‚½\n");
                break;
            case 05:
                st = "(((;‹ „D ‹;)))\n";
                strcpy(mojiretu,st);
                printf("(((;‹ „D ‹;)))‚ð‘—M‚µ‚Ü‚µ‚½\n");
                break;
            case 06:
                st = "_(-ƒÖ-`_)Ü )_\n";
                strcpy(mojiretu,st);
                printf("_(-ƒÖ-`_)Ü )_‚ð‘—M‚µ‚Ü‚µ‚½\n");
                break;
            case 07:
                st = "(¿^o^)½ ßßßßßßßß™ \n";
                strcpy(mojiretu,st);
                printf("(¿^o^)½ ßßßßßßßß™ ‚ð‘—M‚µ‚Ü‚µ‚½\n");
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