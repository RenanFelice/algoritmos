#include <stdio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>

    //quickSort
    //determina um pivot, todos os elementos de menor valor são movidos para a esquerda e os de maior valor para direita
    //
void quickSort(int vetor[],int first,int last){
    int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(vetor[i]<=vetor[pivot]&&i<last)
                i++;
            while(vetor[j]>vetor[pivot])
                j--;
            if(i<j)
            {
                temp=vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=temp;
            }
        }
        temp=vetor[pivot];
        vetor[pivot]=vetor[j];
        vetor[j]=temp;
        quickSort(vetor,first,j-1);
        quickSort(vetor,j+1,last);
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
    quickSort(arrayTeste, 0, arrayTesteSize - 1);
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
    quickSort(userArray,0, userArrSize -1);
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
    for(int i = 0; i < dinamicArraySize; i++){
        dinamicArray[i] = rand();
    }
    printf("array criada\n");

    printf("ordenando a array de tamanho %d\n", dinamicArraySize);


    clock_t t;
    t = clock();
    quickSort(dinamicArray, 0, dinamicArraySize -1);
    printf("finalizado\n");
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("a funcao quickSort demorou %f segundos para ordenar %d dados \n", time_taken, dinamicArraySize);

    for(int i = 0; i < dinamicArraySize; i++){
        free(dinamicArray[i]);
    }
    free(dinamicArray);

    return 0;
}


//time complexity:
//Melhor/Médio: O(n log n)
//Pior: O(n²) // caso a array já esteja sortida, deve-se fazer n decomposições e n comparações


//space complexity:
//O (log n)
