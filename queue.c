#include <stdio.h>
#include <stdlib.h>



//Fila
//primeiro a entrar primeiro a sair

//Big o
// inserir e remover o(1)
// acesso e busca o(n)


//ListaLigada ligada para armazenar entradas da fila
struct QNode {
    int key;
    struct QNode* next;
};

//fila
//front armazena o primeiro node da LL
//rear armazena o ultimo node da LL
struct Queue {
    struct QNode *front, *rear;
};

// Cria um novo node na LL
struct QNode* newNode(int k){
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->key = k;
    temp->next = NULL;
    return temp;
}

// Cria uma fila vazia
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Adiciona um item a uma fila
void enQueue(struct Queue* q, int k){
    // Create a new LL node
    struct QNode* temp = newNode(k);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Função que remove o primeiro item da fila;
void deQueue(struct Queue* q){
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
    struct QNode* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Desaloca memória
void freeList(struct QNode* head){
   struct QNode* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

int main(){
    struct Queue* q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    deQueue(q);

    printf("inicio fila : %d\n", q->front->key);
    printf("final fila : %d\n", q->rear->key);


    printf("Insira o tamanho da fila que deseja criar: ");
    int queueSize;
    scanf("%d", &queueSize);
    struct Queue* userQueue = createQueue();

    for(int i = 1; i <= queueSize; i++){
        enQueue(userQueue, i);
    }

    printf("inicio fila usuario: %d\n", userQueue->front->key);
    printf("final fila usuario: %d\n", userQueue->rear->key);

    struct QNode * node;
    node = userQueue->front;
    freeList(node);

    return 0;
}
