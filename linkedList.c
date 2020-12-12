#include <stdio.h>
#include <stdlib.h>


//big o
//inserir, remover no início ou fim - o(1)
//inserir, remover no meio da lista - o(n)
// acessar e procurar - o(n)

//Self referential structure to create node.
typedef struct tmp{
	int 	item;
	struct tmp *  next;
}Node;

//structure for create linked list.
typedef struct{
	Node * head;
	Node * tail;

}List;

//Initialize List
void initList(List * lp){
	lp->head = NULL;
	lp->tail = NULL;
}

//Create node and return reference of it.
Node * createNode(int item){
	Node * nNode;

	nNode = (Node *) malloc(sizeof(Node));

	nNode->item = item;
	nNode->next = NULL;

	return nNode;
}

//Add new item at the end of list.
void addAtTail(List * lp,int item){
	Node * node;
	node = createNode(item);

	//if list is empty.
	if(lp->head == NULL)
	{
		lp->head = node;
		lp->tail = node;
	}
	else
	{
		lp->tail->next  = node;
		lp->tail 	= lp->tail->next;
	}
}

//Delete item from the end of list.
int delFromTail(List * lp){
	Node * temp;
	int i = 0;

	int item = 0;


	if(lp->tail == NULL)
	{
		printf("\nList is Empty ...");
		return -1;
	}
	else
	{
		temp = lp->head;

		while(temp->next != lp->tail)
		{ temp = temp->next;}

		item = lp->tail->item;

		lp->tail = temp;
		lp->tail->next = NULL;
	}

	return item;
}

//Add new item at begning of the list.
void addAtHead(List * lp,int item){
	Node * node;
	node = createNode(item);

	//if list is empty.
	if(lp->head == NULL)
	{
		lp->head = node;
		lp->tail = node;
	}
	else
	{
		node->next 	= lp->head	;
		lp->head 	= node		;
	}
}

//Delete item from Start of list.
int delFromHead(List * lp){
	int item = 0;

	if(lp->head == NULL)
	{
		printf("\nList is Empty ...");
		return -1;
	}
	else
	{
		item = lp->head->item;
		lp->head = lp->head->next;
	}

	return item;
}

//To print list from start to end of the list.
void printList(List *lp){
	Node * node;

	if(lp->head == NULL)
	{
		printf("\nEmpty List");
		return;
	}

	node = lp->head;

	printf("\nList: \n\n\t");
	while(node != NULL)
	{
		printf("| %05d |",node->item);
		node = node->next;

		if(node !=NULL)
			printf("--->");
	}
	printf("\n\n");
}

Node * find_node(Node * head, int item){
    Node *tmp = head;
    while(tmp != NULL){
        if(tmp->item == item) return tmp;
        tmp = tmp->next;

    }
    return NULL;
}


//Main function to execute program.
int main(){
    Node * node;
	List *lp;

	int item = 0;

	lp = (List *) malloc(sizeof(List));

	initList(lp);

	addAtTail(lp,110);
	addAtTail(lp,20);
	addAtHead(lp,30);
	addAtHead(lp,40);
	addAtTail(lp,5420);

	printList(lp);

	item = delFromTail(lp);

	if(item >= 0)
		printf("\nItem deletado : %d",item);
	printList(lp);

    item = delFromHead(lp);

	if(item >= 0)
		printf("\nItem deletado is : %d",item);
	printList(lp);


	int listSize;
	printf("insira uma quantidade de items a serem adicionados: ");
	scanf("%d", &listSize);


	for(int i = 0; i < listSize; i++){
        addAtTail(lp,i);
	}

	item = delFromTail(lp);
	if(item >= 0)printf("\nTail deletado : %d",item);


	item = delFromHead(lp);
	if(item >= 0) printf("\nHead deletado : %d",item);


    node = lp->head;
    printf("\nHead Node: %d", node->item);
    Node * foundNode;
	foundNode = find_node(node, 500000);
	printf("\nitem encontrado : %d", foundNode->item);


	return 0;
}



