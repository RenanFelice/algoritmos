#include <stdio.h>
#include <string.h>
#include <time.h>

    //Bubble sort
    //Percorre a array comparando o ind�ce atual com o seguinte, se o �ndice atual for maior, � feita a troca de posi��o.
    //na primeira passagem, teremos o �ltimo �ndice da array j� com o valor correto na sua posi��o, na segunda passagem teremos o penultimo e assim por diante.


    //{1, 5, 2, 56, 37, 999, 2, 1, 3,5, 87, 104, 2, -5, 4, 999}
    //fun��o algor�timica bubbleSort
void bubbleSort (int arr[], int size){
    int noSwaps, i, j, temp;
    for(i = size - 1; i >= 0; i--){
            noSwaps = 1;
        for(j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                noSwaps = 0;
      }
    }
    if(noSwaps) break;
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

    //teste do algor�timo com valores est�ticos

    int arrayTeste[] = {5, 1, 56, 2, 37, 999, 2, 1, 3,5, 87, 104, 2, -5, 4, -3};
    bubbleSort(arrayTeste, 16);
    for(int i = 0; i < 16; i++){
    printf("array sortida indice %d: %d\n", i, arrayTeste[i]);
  }


    //implementa��o de array din�mica pegando input do usu�rio
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

    printf("\narray do usuario ordenada com bubble sort: ");
    bubbleSort(userArray, arrSize);
    for(int i = 0; i < arrSize; i++){
        printf("%d ", userArray[i]);
    }

    for(int i = 0; i < arrSize; i++){
        free(userArray[i]);
    }
    free(userArray);

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
    bubbleSort(dinamicArray, dinamicArraySize);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

    printf("a funcao bubbleSort demorou %f segundos para ordenar %d dados \n", time_taken, dinamicArraySize);

    for(int i = 0; i < dinamicArraySize; i++){
        free(dinamicArray[i]);
    }
    free(dinamicArray);

    return 0;
}






//nota��o Big o de bubble sort
//tempo:
//pior cen�rio/m�dia  o(n�)
//melhor cen�rio(dados quase ordenados) o(n)

//espa�o: o(1))

