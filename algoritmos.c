#include <stdio.h>
#include <string.h>
#include <time.h>



char* pickAlgo(bubbleSort, insertionSort, selectionSort){
    printf("Escolha o algoritmo a ser utilizado: \n");
    printf("1 - Bubble Sort\n");
    printf("2 - Insertion Sort\n");
    printf("3 - Selection Sort\n");
    int option, isValid;

    isValid = scanf("%d", &option);
    while(isValid < 1 || (option < 1 || option > 3)){
        scanf("%*[^\n]");
        getchar();
        printf("Informe uma opcao valida: ");
        isValid = scanf("%d", &option);
    }

    switch (option){
   case 1:
     return bubbleSort;
   break;

   case 2:
     return insertionSort;
   break;

   case 3:
     return selectionSort;
   break;

   default:
     return "algo deu errado, reinicie o programa";
    }
}

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

void insertionSort (int arr[], int size){
    int j, i, current;
    for(i = 1; i < size; i++){
        current = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > current; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = current;
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



int main()
{

    algo = pickAlgo();

    //printf("O algoritmo escolhido foi: %s", algo);

    int arrayTeste[] = {5, 1, 56, 2, 37, 999, 2, 1, 3,5, 87, 104, 2, -5, 4, -3};
    algo(arrayTeste, 16);
    for(int i = 0; i < 16; i++){
    printf("array sortida indice %d: %d\n", i, arrayTeste[i]);
  }


    return 0;
}



