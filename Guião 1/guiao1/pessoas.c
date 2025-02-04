#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "person.h"


int main(int argc, char* argv[]){

    // Ex 1
    /*char buf[20];
    int read_bytes;
    while((read_bytes= read(0,buf,20))>0){
        write(1,buf,read_bytes);
    }*/

    // Ex 2
    if(argc<3){
        printf("Usage: ./pessoas [orig] [dest]\n");
        return 1;
    }
    char* orig = argv[1];
    int fd1 = open(orig,O_RDONLY);
    //char* dest = argv[2];
    //int fd2 = open(dest, O_CREAT | O_WRONLY, 0644);
    ssize_t bytes_read;
    byt
    char buf[20];
    while()

    close(fd1);
    close(fd2);
    /*
    if ( argc < 3 )
    {
        printf("Usage:\n");
        printf("Add new person: ./pessoas -i [name] [age]\n");
        printf("List N persons: ./pessoas -l [N]\n");
        printf("Change person age: ./pessoas -u [name] [age]\n");
        printf("Change person age (v2): ./pessoas -o [position] [age]\n");
        return 1;
    }

    if ( strcmp(argv[1],"-i") == 0 )
    {
        // TO DO
    }

    if ( strcmp(argv[1],"-l") == 0 )
    {
        // TO DO
    }

    if ( strcmp(argv[1],"-u") == 0 )
    {
        // TO DO
    }

    if ( strcmp(argv[1],"-o") == 0 )
    {
        // TO DO
    }*/

    return 0;
}
