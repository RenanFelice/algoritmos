#include <stdio.h>
#include <string.h>
#include <time.h>

    //Insertion sort
    //faz a iteração no array inteiro para encontrar o elemento de valor mínimo, depois insere ele no local correto



    //função algorítimica selectionSorte
void selectionSort (int arr[], int size){
    int i, j, min, temp;
    for(i = 0; i < size; i++){
        min = i;
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}


int userInput(){
    int arrSize;
    int checkNum = scanf("%d", &arrSize);


    while(checkNum  != 1){
        scanf("%*[^\n]");
        getchar();
        printf("\nValor inserido invalido, digite um valor numerico: ");
        checkNum = scanf("%d", &arrSize);
    }

    return arrSize;

}

int main()
{

    //teste do algorítimo com valores estáticos

    int arrayTeste[] = {5, 1, 56, 2, 37, 999, 2, 1, 3,5, 87, 104, 2, -5, 4, -3};
    selectionSort(arrayTeste, 16);
    for(int i = 0; i < 16; i++){
    printf("array sortida indice %d: %d\n", i, arrayTeste[i]);
  }


    //implementação de array dinâmica pegando input do usuário
    printf("\nInforme o tamanho da array: ");
    int arrSize = userInput();

    int *userArray = (int*) malloc(arrSize * sizeof(int));

    for(int i = 0; i < arrSize; i++){
        printf("Digite o valor do indice %d: ", i);
        userArray[i] = userInput();
    }
    printf("\n");
    printf("array do usuario: ");

    for(int i = 0; i < arrSize; i++){
        printf("%d ", userArray[i]);
    }

    printf("\narray do usuario ordenada com insertion sort: ");
    selectionSort(userArray, arrSize);
    for(int i = 0; i < arrSize; i++){
        printf("%d ", userArray[i]);
    }
    printf("\n\n");

    printf("insira um valor para criar uma array dinamica: ");
    int dinamicArraySize = userInput();
    int *dinamicArray = (int*) malloc(dinamicArraySize * sizeof(int));

    printf("criando array de tamanho %d\n", dinamicArraySize);
    for(int i = 0; i < dinamicArraySize; i++){
        dinamicArray[i] = dinamicArraySize - i;
    }
    printf("array criada\n");

    printf("ordenando a array de tamanho %d\n", dinamicArraySize);

    clock_t t;
    t = clock();
    selectionSort(dinamicArray, dinamicArraySize);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("a funcao selectionSort demorou %f segundos para ordenar %d dados \n", time_taken, dinamicArraySize);

    return 0;
}



//notação Big o de Insertion Sort
//tempo:
//cenários pior/médio/melhor  o(n²)

//espaço: o(1))

