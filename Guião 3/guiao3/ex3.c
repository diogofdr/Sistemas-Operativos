#include <stdio.h>
#include "mysystem.h"

int exercicio1();
int exercicio2();

int main() {

    //char comando1[] = "ls -l -a -h";
    //char comando2[] = "sleeep 30";
	//char comando3[] = "sleep 10";
	//char comando4[] = "ps";
	//int ret;

	int exercicio;
	printf("Exercício a executar (1-5)\n");
	scanf("%d",&exercicio);

	switch(exercicio){
		case 1:
			if(exercicio1() == -1){
				printf("Erro a executar o comando ls -l \n");
			}
			break;
		case 2:
			if(exercicio2() == -1){
				printf("Erro a executar o comando ls -l \n");
			}
			break;
		default:
		    break;
	}
	/*
	printf("\nCOMANDO 1: a executar mysystem para %s\n",comando1);
	ret = mysystem(comando1);
	printf("COMANDO 1: ret = %d\n",ret);

	printf("\nCOMANDO 2: a executar mysystem para %s\n",comando2);
    ret = mysystem(comando2);
    printf("COMANDO 2: ret = %d\n",ret);

	printf("\nCOMANDO 3: a executar mysystem para %s\n",comando3);
	ret = mysystem(comando3);
    printf("COMANDO 3: ret = %d\n",ret);

    printf("\nCOMANDO 4: a executar mysystem para %s\n",comando4);
	ret = mysystem(comando4);
    printf("COMANDO 4: ret = %d\n",ret);
	*/
    return 0;
}

int exercicio1(){
	// Chamada ao sistema
	execlp("ls", "ls", "-l", NULL);
	return -1;
}

int exercicio2(){

	int pid;
	if((pid=fork())==0){
		printf("Hello from child, before System Call\n");
		execlp("ls", "ls", "-l", NULL);
		return -1; // Não deve aqui chegar 
	}
	else{
		wait(NULL);
		printf("Hello from parent, after System Call\n");
	}
	return 0;
}