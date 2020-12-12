#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>

    //mergeSort
    //vai dividindo as arrays no meio até chegar no caso base e retorna fundindo elas de forma recursiva


    //função auxiliar para fundir 2 arrays
void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}


int printArray(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int userInput(){
    int userArrSize;
    int checkNum = scanf("%d", &userArrSize);


    while(checkNum  != 1){
        scanf("%*[^\n]");
        getchar();
        printf("\nValor inserido invalido, digite um valor numerico: ");
        checkNum = scanf("%d", &userArrSize);
    }

    return userArrSize;

}

int main()
{

    //teste do algorítimo com valores estáticos

    int arrayTeste[] = {5, 1, 56, 2, 37, 999, 2, 1, 3,5, 87, 104, 2, -5, 4, -3};
    int arrayTesteSize = sizeof(arrayTeste) / sizeof(arrayTeste[0]);
    mergeSort(arrayTeste, 0, arrayTesteSize - 1);
    printArray(arrayTeste, arrayTesteSize);

    //implementação de array dinâmica pegando input do usuário
    printf("\nInforme o tamanho da array: ");
    int userArrSize = userInput();

    int *userArray = (int*) malloc(userArrSize * sizeof(int));

    for(int i = 0; i < userArrSize; i++){
        printf("Digite o valor do indice %d: ", i);
        userArray[i] = userInput();
    }

    printf("\n");
    printf("array do usuario: ");
    printArray(userArray, userArrSize);
    printf("\narray do usuario ordenada com merge sort: ");
    mergeSort(userArray,0, userArrSize - 1);
    printArray(userArray, userArrSize);

    for(int i = 0; i < userArrSize; i++){
        free(userArray[i]);
    }
    free(userArray);

    printf("\n\n");

    printf("insira um valor para criar uma array dinamica: ");
    int dinamicArraySize = userInput();

    //ponteiro do tipo inteiro que aponta para um bloco de memória do tamanho especificado
    int *dinamicArray = (int*) malloc(dinamicArraySize * sizeof(int));

    printf("criando array de tamanho %d\n", dinamicArraySize);
    srand(time(NULL));

    for(int i = 0; i < dinamicArraySize; i++){
        dinamicArray[i] = dinamicArraySize - i;

    }
    printf("array criada\n");

    printf("ordenando a array de tamanho %d\n", dinamicArraySize);


    clock_t t;
    t = clock();
    mergeSort(dinamicArray, 0, dinamicArraySize - 1);
    printf("finalizado\n");
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("a funcao mergeSort demorou %f segundos para ordenar %d dados \n", time_taken, dinamicArraySize);

    for(int i = 0; i < dinamicArraySize; i++){
        free(dinamicArray[i]);
    }
    free(dinamicArray);

    return 0;
}



//notação Big o de mergeSort
//tempo: o(n log n) em todos os casos
//explicação: conforme a array cresce, são feitas log n decomposições
//caso a array tenha 8 elementos, serão feitas 3 decomposições, 2³ = 0
// como são feitas n comparações para cada decomposição, chegamos a O (n log n)

//espaço: o(n)

