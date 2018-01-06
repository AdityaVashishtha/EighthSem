#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc,char *argv[]) {    
    printf("Client Started ... \n");
    if(argc < 3) {
        printf("Some arguments are missing run as::  %s hostname 8888 \n",argv[0]);
        exit(0);
    }
    int hostPort,socFd;
    char *hostName;
    char buffer[256];
    int bufferSize = sizeof(buffer);
    hostPort = atoi(argv[2]);
    hostName = argv[1];

    struct sockaddr_in serverAddress;
    struct hostent *server;
    socFd = socket(AF_INET,SOCK_STREAM,0);
    if(socFd < 0) {
        printf("ERR: Socket not created \n");
        exit(1);
    }
    server = gethostbyname(hostName);
    if (server == NULL) {
        printf("ERR: host not found 404 \n");
        exit(0);
    }
    /* Setting buffer all values to 0s */
    bzero((char *) &serverAddress, sizeof(serverAddress) );

    /* Server address structure value setting */
    serverAddress.sin_family = AF_INET;
    printf("__HOST ADDR__ %s \n",(char *)server->h_addr);
    bcopy( (char *)server->h_addr, (char *) &serverAddress.sin_addr.s_addr, server->h_length);
    serverAddress.sin_port = htons(hostPort);
    printf("Connecting to %s:%d ...\n",hostName,hostPort);
    if( connect(socFd, (struct sockaddr *) &serverAddress, sizeof(serverAddress) ) <0 ) {
        printf("ERR: Could not connect to server \n");
        exit(1);
    }
    printf("Connected to %s:%d ...\n",hostName,hostPort);

    printf("Enter two numbers to add \n");
    int a,b;
    scanf("%d%d",&a,&b);
    sprintf(buffer,"%d %d",a,b);
    printf("BUffer content :: %s\n",buffer);
    write(socFd,buffer,strlen(buffer));
    bzero(buffer,bufferSize);
    read(socFd,buffer,bufferSize);
    printf("Result on client as %s \n",buffer);
    close(socFd);
    return 0;
}