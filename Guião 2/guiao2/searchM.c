#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <string.h>

void exercicio1();
void exercicio2();
void exercicio3();
void exercicio4();
void exercicio5();
void exercicio6();
void exercicio7();

int main(int argc, char *argv[]) {

    int i=0;
    while(i<=0 || i>7){
        printf("Insira o numero do exercício (1-7)\n");
        scanf("%d", &i);
    }

    switch(i){
        case 1:
            exercicio1();
            break;
        case 2:
            exercicio2();
            break;
        case 3:
            exercicio3();
            break;
        case 4:
            exercicio4();
            break;
        case 5:
            exercicio5();
            break;
        case 6:
            exercicio6();
            break;
        case 7:
            exercicio7();
            break;
        default:
            break;
    }
    return 0;
}
    
void exercicio1(){
    printf("Exercício 1\n");
    printf("Meu PID: %d\n", getpid());
    printf("PID do meu pai: %d\n", getppid());
}

void exercicio2(){
    printf("Exercício 2\n");

    pid_t pid = fork();  // Cria um processo filho

    if (pid < 0) {
        // Erro ao criar o processo filho
        fprintf(stderr, "Fork falhou!\n");
        _exit(1);
    } else if (pid == 0) {
        // Código executado pelo processo filho
        printf("Processo filho:\n");
        printf("PID filho: %d\n", getpid());
        printf("PID do pai do filho: %d\n", getppid());
    } else {
        // Código executado pelo processo pai
        printf("Processo pai:\n");
        printf("PID Pai: %d\n", getpid());
        printf("PID do pai do pai: %d\n", getppid());
        printf("PID do filho do pai: %d\n", pid);
    }
}

void exercicio3(){
    printf("Exercicio 3\n");
    int n = 10;
    // Ciclo 10 vezes
    for(int i = 0; i < n; i++){
        // Criar processo filho
        int pid;
        if((pid = fork())==0){
            printf("Hello from child %d\n", i);
            _exit(0);
        }

        //Espera pelo processo filho terminar
        int status;
        wait(&status);
        if(WIFEXITED(status)){
            printf("Child %d exited with status %d\n", i, WEXITSTATUS(status));
        }
        
    }
}
    

void exercicio4(){
    printf("Exercicio 4\n");
    
    int n=10;
    int pids[n];

    for(int i = 0; i < n; i++){
        // Criar processo filho
        if((pids[i] = fork())==0){
            printf("Hello from child %d\n", i);
            _exit(i);
        }
    }
    //sleep(1); //Para evitar exits antes de todos os prints dos forks 
    for(int i=0;i<n;i++){
        // Criar processo filho
        int status;
        waitpid(pids[i], &status, 0);
        if(WIFEXITED(status)){
            printf("Child %d exited with status %d\n", i, WEXITSTATUS(status));
        }
        else{
            printf("Child %d did not exit properly\n", i);
        }
    }
}

void exercicio5(){

    printf("Exercicio 5\n");

    int** matriz = createMatrix();
    printMatrix(matriz);

    clock_t start = clock();
    valueExists(matriz, 0);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo fork() por célula: %f\n", time_spent);
    
    start = clock();
    valueExists2(matriz, 0);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo fork() por linha: %f\n", time_spent);

    for (int i = 0; i < ROWS; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void exercicio6(){

    printf("Exercicio 6\n");

    int** matriz = createMatrix();
    printMatrix(matriz);

    clock_t start = clock();
    linesWithValue(matriz, 0);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo fork() por linha ex6): %f\n", time_spent);
    
    for (int i = 0; i < ROWS; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void exercicio7() {
    printf("Exercicio 7\n");
    int number;
    printf("Digite o número a ser pesquisado: ");
    scanf("%d", &number);

    // Gera a matriz e salva em arquivo
    int **matriz = createMatrix();
    printMatrix(matriz);
    FILE *file = fopen("matriz.bin", "wb");
    if (!file) {
        perror("fopen");
        return;
    }
    for (int i = 0; i < ROWS; i++) {
        fwrite(matriz[i], sizeof(int), COLUMNS, file);
    }
    fclose(file);

    // Cria processos filhos para pesquisar o número
    for (int i = 0; i < ROWS; i++) {
        int pid = fork();
        if (pid == 0) {
            // Processo filho
            FILE *file = fopen("matriz.bin", "rb");
            if (!file) {
               perror("fopen");
                _exit(1);
            }
            fseek(file, i * COLUMNS * sizeof(int), SEEK_SET);
            int row[COLUMNS];
            fread(row, sizeof(int), COLUMNS, file);
            fclose(file);

            // Pesquisa o número na linha
            int found = 0;
            for (int j = 0; j < COLUMNS; j++) {
                if (row[j] == number) {
                    printf("Número %d encontrado na linha %d, posição %d\n", number, i, j);
                    found = 1;
                    //_exit(0);  // Termina o processo filho
                }
            }
            if(found!=0) _exit(0); // Cenario de numero encontrado
            printf("Número %d não encontrado na linha %d\n", number, i);
            _exit(0);  // Termina o processo filho
        }
    }

    // Processo pai espera todos os filhos terminarem
    for (int i = 0; i < ROWS; i++) {
        wait(NULL);
    }

    for (int i = 0; i < ROWS; i++) {
        free(matriz[i]);
    }
    free(matriz);
}