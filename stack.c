#include <limits.h>
#include <stdio.h>
#include <stdlib.h>


//Pilha
//ultimo a entrar primeiro a sair

//Big o
// inserir e remover o(1)
// acesso e busca o(n)

// A structure to represent a stack
struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data){
    struct StackNode* stackNode =
      (struct StackNode*)
      malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root){
    return !root;
}

void push(struct StackNode** root, int data){
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(struct StackNode** root){
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(struct StackNode* root){
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

void freeList(struct StackNode* head){
   struct StackNode* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

int main()
{
    struct StackNode* root = NULL;

    printf("10 inserido na pilha\n");
    push(&root, 10);
    printf("20 inserido na pilha\n");
    push(&root, 20);
    printf("30 inserido na pilha\n");
    push(&root, 30);

    printf("insira o tamanho da pilha que deseja criar: ");
    int stackSize;
    scanf("%d", &stackSize);
    for(int i = 1; i <= stackSize; i++){
        push(&root, i);
    }


    printf("%d retirado da pilha\n", pop(&root));

    printf("Elemento no topo da pilha: %d\n", peek(root));

    freeList(root);

    return 0;
}
