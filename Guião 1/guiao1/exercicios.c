#include "exercicios.h"

void exercicio1(){

    int exercicio;
    printf("1.Leitura a partir do stdin.\n2.Leitura de um ficheiro.\n");
    scanf("%d",&exercicio);
    if(exercicio==1){
        char buf[BUF_SIZE];
        int read_bytes;
        //ssize_t read_bytes;
        while((read_bytes = read(STDIN_FILENO,buf,BUF_SIZE))>0){
            write(STDOUT_FILENO,buf,read_bytes);
        }
    }
    else if(exercicio==2){
        printf("Nome do ficheiro:\n");
        char* nomeFicheiro = malloc(MAX_FILENAME*sizeof(char));
        scanf("%s",nomeFicheiro);
        //printf("%s\n",nomeFicheiro);

        int fd = open(nomeFicheiro,O_RDONLY);
        if(fd==-1){
            perror("Erro ao abrir o ficheiro");
            return;
        }

        char buf[BUF_SIZE];
        int read_bytes;
        //ssize_t read_bytes;;
        while((read_bytes = read(fd, buf, BUF_SIZE))>0){
            write(STDOUT_FILENO,buf,read_bytes);
        }
        close(fd);
    }
    else    printf("Opção inválida.\n");    
}

void exercicio2(){
    /*if(argc<3){
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
    */
}

void exercicio3(){
    
}

void exercicio4(){
    
}