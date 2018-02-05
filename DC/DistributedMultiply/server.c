#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int handleOp(int socFd);

int main(int argc,char *argv[]) {    
    if(argc < 2) {
        printf("Some arguments are missing run as::  %s 8888 \n",argv[0]);
        exit(1);
    }
    int socFd, newSocFd, clientAddrLength, runPort, flag;
    struct sockaddr_in serverAddress, clientAddress;    
    runPort = atoi(argv[1]);        
    socFd = socket(AF_INET,SOCK_STREAM,0);
    if(socFd < 0) {
        printf("ERR: Socket not created \n");
        exit(1);
    }
    /* Setting buffer all values to 0s */
    bzero((char *) &serverAddress, sizeof(serverAddress) );

    /* Server address structure value setting */
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(runPort);
    
    /* Binding servert to port */
    if( bind(socFd,(struct sockaddr *) & serverAddress, sizeof(serverAddress)) < 0 ) {
        printf("Some error during binding");
        exit(1);
    }
    /* Starting listening on port */
    listen(socFd,5);
    printf("Server Started listing on %d ... \n",runPort);
    while(1) {        
        clientAddrLength = sizeof(clientAddress);
        newSocFd = accept(socFd,(struct sockaddr *) & clientAddress, & clientAddrLength);
        if(newSocFd < 0 ) {
            printf("ERR:: Not able to accept request of client \n");
            exit(1);
        }
        int pId = fork();
        if(pId < 0) {
            printf("ERR:: Not able to fork \n");
            exit(1);
        } else if( pId == 0 ) {
            printf("New Request recived from client \n");
            close(socFd);
            //printf(" test %s \n",(char *) &clientAddress.sin_addr.s_addr);
            handleOp(newSocFd);
            exit(0);
        } else {
            close(newSocFd);
        }                
    }
}

int handleOp(int clientSocFd) {
    char buffer[256];
    int bufferSize = sizeof(buffer);
    printf("Client Connected \n");
    bzero(buffer,bufferSize);
    read(clientSocFd,buffer,bufferSize-1);
    printf("%s",buffer);
    int a ,b;
    sscanf(buffer,"%d %d",&a,&b);
    printf("Number sent %d and %d \n",a,b);
    bzero(buffer,bufferSize);
    sprintf(buffer,"%d",a*b);
    printf("On server result :: %s \n",buffer);    
    write(clientSocFd,buffer,strlen(buffer));
}