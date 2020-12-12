#include <stdio.h>
#include <stdlib.h>



//Binary Tree
//Big o
//inserir e procurar dados o(log n)



struct node{
    int key;
    struct node *left, *right;
};

struct node* newNode(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

int treeIsEmpty(struct node* t){
    // Retorna 1 se a árvore for vazia e 0 caso contrário
    return t == NULL;
}

void inorder(struct node* no){
    if (no != NULL) {
        inorder(no->left);
        printf("%d ", no->key);
        inorder(no->right);
    }
}


//explora primeiro as raizes
void showTreePreOrder(struct node* t){
        if(!treeIsEmpty(t)){
        printf("%d ", t->key);
        showTreePreOrder(t->left);
        showTreePreOrder(t->right);
        }
}


//explora primeiro as folhas
void showTreePosOrder(struct node* t){
        if(!treeIsEmpty(t)){
        showTreePosOrder(t->left);
        showTreePosOrder(t->right);
        printf("%d ", t->key);
    }
}

void deallocate(struct node* t){
        if(!treeIsEmpty(t)){
        showTreePosOrder(t->left);
        showTreePosOrder(t->right);
        free(t);
    }
}

struct node* insert(struct node* node, int key){
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

struct node* findMinValue(struct node *currentNode){
    if(currentNode->left==NULL)
        return currentNode;

    return findMinValue(currentNode->left);
}

struct node* findMaxValue(struct node *currentNode){
    if(currentNode->right==NULL)
        return currentNode;

    return findMaxValue(currentNode->right);
}

void insertTree(struct node** t, int num){
    if(*t == NULL){
        *t = (struct node*)malloc(sizeof(t));
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->key = num;
    }
    else
    {
        if(num < (*t)->key) /* Se o número for menor então vai pra subTreeLeft */
        {
            insertTree(&(*t)->left, num);
        }
        if(num > (*t)->key) /* Se o número for maior então vai pra subTreeRight */
        {
            insertTree(&(*t)->right, num);
        }
    }
}


// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node* root = NULL;
    root = insert(root, 8);
    insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    insert(root, 7);
    insert(root, 12);
    insert(root, 10);
    insert(root, 9);
    insert(root, 11);
    insert(root, 14);
    insert(root, 13);
    insert(root, 15);

    // imprima a árvore binária em ordem
    printf("arvore em ordem\n");
    inorder(root);
    printf("\narvore pre ordem\n");
    showTreePreOrder(root);
    printf("\narvore pos ordem\n");
    showTreePosOrder(root);






    printf("\ninforme o tamanho da arvore binaria: ");
    int bstSize;
    scanf("%d", &bstSize);

    for(int i = 0; i < bstSize; i++){
        insert(root, rand());
    }

    printf("arvore criada\n");
    //inorder(root);



    printf("menor valor: %d\n", findMinValue(root)->key);

    printf("maior valor: %d\n", findMaxValue(root)->key);



    return 0;
}
