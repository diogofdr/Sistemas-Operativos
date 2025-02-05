#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "person.h"
#include "exercicios.h"


int main(int argc, char* argv[]){

    int exercicio;
    printf("Escolha o exercício:\n1- mycat\n2-mycpus\n3-...\n0 para sair\n");
    scanf("%d",&exercicio);

    while(exercicio!=0){
        switch(exercicio){
            case 1:
                // Ex 1
                exercicio1();
                break;
            case 2:
                // Ex 2
                exercicio2();
                break;
            case 3:
                // Ex 3
                break;
            case 4:
                // Ex 4
                break;
            default:
                printf("Opção inválida.\nInsira novamente:  ");
                scanf("%d",&exercicio);
        }
        printf("\nEscolha o próximo exercício:\n");
        scanf("%d",&exercicio);
    }
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
