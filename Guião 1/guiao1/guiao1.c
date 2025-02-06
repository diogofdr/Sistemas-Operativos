#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "person.h"
#include "exercicios.h"
/*

    [...] -> Argumentos opcionais
    
    Modo de execução:
    1)    ./guiao1 mycat [ficheiro de texto]
    2)    ./guiao1 mycp ficheiroOriginal ficheiroDestino
    3)    2 opções: ./guiao1 -i [nome] [idade] -> Adiciona pessoa individualmente
                    ./pscript.sh i -> Adiciona i pessoas de uma vez
          ./guiao1 -l n -> Lista as n primeiras pessoas
          ./guiao1 -u nome idade -> Atualiza idade de uma pessoa
    4)    ./guiao1 -o registo idade -> Atualiza idade de uma pessoa pelo registo

*/

int main(int argc, char* argv[]){

    int i=0;
    if(strcmp(argv[1], "mycat")==0) i=1;
    if(strcmp(argv[1], "mycp")==0) i=2;
    if(strcmp(argv[1], "-i")==0) i=3;
    if(strcmp(argv[1], "-l")==0) i=4;
    if(strcmp(argv[1], "-u")==0) i=5;
    if(strcmp(argv[1], "-o")==0) i=6;

    switch (i){
        case 1:
            if(argc<3){
                exercicio1(NULL);
            }
            else{
                exercicio1(argv[2]);
            }
            break;
        case 2:
            if(argc!=4){
                printf("Formato incorreto. -----> './guiao1 mycp 'ficheiro original' 'ficheiro copia'\n");
                return 0;
            }
            exercicio2(argv[2], argv[3]);
            break;
        case 3:
            if(argc<4){
                printf("Formato incorreto. -----> './guiao1 -i 'nome' 'idade'\n");
                return 0;
            }
            adicionaPessoa(argv[2], atoi(argv[3]));
            break;    
        case 4:
            if(argc<3){
                printf("Formato incorreto. -----> './guiao1 -l 'n'\n");
                return 0;
            }
            listaPessoas(atoi(argv[2]));
            break;
        case 5:
            if(argc<4){
                printf("Formato incorreto. -----> './guiao1 -u 'nome' 'idade'\n");
                return 0;
            }
            atualizaIdade(argv[2], NULL, atoi(argv[3]));
            break;
        case 6:
            if(argc<4){
                printf("Formato incorreto. -----> './guiao1 -o 'registo' 'idade'\n");
                return 0;
            }
            atualizaIdade(argv[2], "registo", atoi(argv[3]));
            break;
        default:
            printf("Comando inválido.\n");
    }

    return 0;
}
