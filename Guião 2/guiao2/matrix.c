#include "matrix.h"


int **createMatrix() {

    // seed random numbers
    srand(time(NULL));

    // Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d...", MAX_RAND);
    int **matrix = (int **) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand() % MAX_RAND;
        }
    }
    printf("Done.\n");

    return matrix;
}

void printMatrix(int **matrix) {

    for (int i = 0; i < ROWS; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// ex.5
//Fork por cada celula
int valueExists(int **matrix, int value){

    int pid;

    for(int i=0; i<ROWS; i++){
        // Verificação linha a linha
            for(int j=0; j<COLUMNS; j++){
                // Verificação celula a celula
                if((pid=fork())==0){
                    if(matrix[i][j]==value){
                        printf("Valor %d encontrado, na linha %d e coluna %d\n", value, i, j);
                        _exit(1);
                    }
                    _exit(0);
                }
            }
        }
    return 0;
}

//Fork por cada linha da matriz
int valueExists2(int **matrix, int value){

    int pid;

    for(int i=0; i<ROWS; i++){
        // Verificação linha a linha
        if((pid=fork())==0){
            for(int j=0; j<COLUMNS; j++){
                if(matrix[i][j]==value){
                    printf("Valor %d encontrado, na linha %d e coluna %d\n", value, i, j);
                    _exit(1);
                }
            }
            _exit(0);
        }
    }
    return 0;
}


// ex.6
void linesWithValue(int **matrix, int value){
    int pid[ROWS];
    int status;

    for(int i=0; i<ROWS; i++){
        if((pid[i]=fork())==0){
            for(int j=0; j<COLUMNS; j++){
                if(matrix[i][j]==value){
                    printf("Valor %d encontrado, na linha %d e coluna %d\n", value, i, j);
                    _exit(1);
                }
            }
            _exit(0);
        }
    }
    //wait for children to finish
    for(int i=0; i<ROWS; i++){
        waitpid(pid[i], &status, 0);
        if(WIFEXITED(status)){
            printf("Linha %d terminou com status %d\n", i, WEXITSTATUS(status));
        }
        else{
            printf("Linha %d não terminou\n", i);
        }
    }
}