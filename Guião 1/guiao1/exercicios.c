#include "exercicios.h"

void exercicio1(char* filename){

    if(!filename){
        char buf[BUF_SIZE];
        int read_bytes;
        //ssize_t read_bytes;
        while((read_bytes = read(STDIN_FILENO,buf,BUF_SIZE))>0){
            write(STDOUT_FILENO,buf,read_bytes);
        }
    }
    else{
        int fd = open(filename,O_RDONLY);
        if(fd==-1){
            perror("Erro ao abrir o ficheiro");
            return;
        }

        char buf[BUF_SIZE];
        int read_bytes;
        //ssize_t read_bytes;
        while((read_bytes = read(fd, buf, BUF_SIZE))>0){
            write(STDOUT_FILENO,buf,read_bytes);
        }
        close(fd);
    }   
}

void exercicio2(char* original, char* copia){

    int fdOrigem = open(original, O_RDONLY);
    if(fdOrigem==-1){
        perror("Erro ao abrir o ficheiro de origem");
        return;
    }
    int fdDestino = open(copia, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if(fdDestino==-1){
        perror("Erro ao abrir o ficheiro de destino");
        return;
    }

    int read_bytes;
    char buf[BUF_SIZE]; // BUF_SIZE = 20
    while((read_bytes = read(fdOrigem,buf,BUF_SIZE))>0){
        write(fdDestino,buf,read_bytes);
    }

    close(fdOrigem);
    close(fdDestino);
}
