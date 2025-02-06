#include "person.h"

struct pessoa{
    char nome[100];
    int idade;
};

void adicionaPessoa(char* nome, int idade){
    Pessoa p;
    strcpy(p.nome,nome);
    p.idade = idade;
    int registo = 0;
    int fd = open("ficheiroBinario", O_CREAT | O_APPEND | O_WRONLY, 0644);
    registo = lseek(fd,0,SEEK_END);
    registo += write(fd,&p,sizeof(Pessoa));
    printf("%s -> %d\nRegisto %d\n", p.nome, p.idade, registo);
    close(fd);
}

void listaPessoas(int n){
    Pessoa pessoa;
    int bytes_read;
    int fd = open("ficheiroBinario", O_RDONLY);
    while(n>0 && (bytes_read = read(fd,&pessoa,sizeof(Pessoa)))>0){
        printf("'Nome: %s    Idade:%d'\n",pessoa.nome,pessoa.idade);
        n--;
    }
    close(fd);
}

void atualizaIdade(char* referencia, char* tipo, int idade){

    int fd = open("ficheiroBinario", O_RDWR);
    Pessoa pessoa;

    if(!tipo){
        int bytes_read;
        int total_bytes = 0;
    
        while((bytes_read = read(fd,&pessoa,sizeof(Pessoa)))>0){
            if(strcmp(pessoa.nome, referencia)==0){
                break;
            }
            total_bytes += bytes_read;
        }
        //Caso não se encontre no ficheiro
        if(strcmp(pessoa.nome, referencia)!=0){
            adicionaPessoa(referencia, idade);
            return;
        }

        lseek(fd, total_bytes, SEEK_SET);
        pessoa.idade = idade;
        write(fd,&pessoa,sizeof(Pessoa));
    }
    else if(strcmp(tipo,"registo")==0){
        int registo = atoi(referencia);
        registo -= sizeof(Pessoa);
        lseek(fd, registo, SEEK_SET);

        read(fd,&pessoa,sizeof(Pessoa));
        pessoa.idade = idade;
        
        lseek(fd, registo, SEEK_SET);
        write(fd,&pessoa,sizeof(Pessoa));
    }
    else printf("Erro de tipo de dado.\n");

    close(fd);
}