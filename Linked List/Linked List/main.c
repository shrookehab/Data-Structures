
//=======================Shrook Ehab Attia - G1 - AI Nasr City======================
#include <stdio.h>
#include <stdlib.h>


typedef struct LinkedListEntry {
	int data;
}LinkedListEntry;

typedef struct Node {
	LinkedListEntry data;
	struct Node *next;
}Node;

typedef struct LinkedList {
	Node *head;
	int lsize;
}LinkedList;

void createLinkedList(LinkedList *);
int lenghtLinkedList(LinkedList *);
int insertLinkedList(LinkedList *, LinkedListEntry);
int removeLinkedList(LinkedList *, LinkedListEntry);
int removeFromEndLinkedList(LinkedList *, int);
int searchLinkedList(LinkedList *, LinkedListEntry);
//void merge2LinkedList(LinkedList *, LinkedList *);
void displayLinkedList(LinkedList *);

int main()
{




	int num, num2, indx;;
	char c;
	LinkedListEntry lle;
	LinkedList lls;

	createLinkedList(&lls);

	do {
		printf("[1] Insert the linked list values.\n");
		printf("[2] Display the linked list values.\n");
		printf("[3] Delete value from the linked list.\n");
		printf("[4] Delete value from the end of linked list.\n");
		printf("[5] Search for a value in the linked list.\n");
		printf("[6] Display the size of the linked list.\n");
		printf("==============================================\n");
		printf("Choose the number of test case you want:");
		scanf_s("%d", &num);
		printf("\n==============================================\n");

		switch (num) {
			case 1:
				printf("Please enter the value :");
				scanf_s("%d", &lle.data);
				insertLinkedList(&lls, lle);
				printf("\n");
				break;
			case 2:
				displayLinkedList(&lls);
				break;
			case 3:
				printf("Please enter the value you want to delete :");
				scanf_s("%d", &lle.data);
				removeLinkedList(&lls, lle);
				printf("\n");
				break;
			case 4:
				printf("Please enter the position you want to delete :");
				scanf_s("%d", &indx);
				removeFromEndLinkedList(&lls, indx);
				printf("\n");
				break;
			case 5:
				printf("Please enter the value you want to search for :");
				scanf_s("%d", &lle.data);
				printf("The position of %d is in : %d\n", lle.data, searchLinkedList(&lls, lle));
				break;
			case 6:
				printf("The Total number of elements = %d \n", lenghtLinkedList(&lls));
				break;

			default:
				printf("INVALID OPTION!!!\n");
				break;
		}

		printf("\n==============================================\n");
		printf("Do yo want to choose another option(1 or 0) :");
		scanf_s("%d", &num2);
		printf("\n==============================================\n");
	} while (num2 == 1);

	printf("\tEnd Of Program :)\n");

	/*lle[0].data = 10;
	insertLinkedList(&lls, lle[0]);

	lle[1].data = 20;
	insertLinkedList(&lls, lle[1]);*/

	//lle[2].data = 30;
	//insertLinkedList(&lls, lle[2]);

	//lle[3].data = 40;
	//insertLinkedList(&lls, lle[3]);

	//lle[4].data = 50;
	//insertLinkedList(&lls, lle[4]);

	//LinkedListEntry lle;
	//LinkedList lls;

	//createLinkedList(&lls);

	//lle.data = 10;
	//insertLinkedList(&lls, lle);
	//insertLinkedList(&lls, lle);
	//insertLinkedList(&lls, lle);
	//insertLinkedList(&lls, lle);


	//displayLinkedList(&lls);
	//printf("size = %d \n", lenghtLinkedList(&lls));

	//lle[5].data = 30;
	//removeLinkedList(&lls, lle[1]);

	//removeFromEndLinkedList(&lls, 2);
	//displayLinkedList(&lls);

	//printf("The position of %d is : %d\n", lle[1].data,searchLinkedList(&lls, lle[1]));
	return 0;
}

void createLinkedList(LinkedList *lls) {

	lls->head = NULL;
	lls->lsize = 0;

}
int lenghtLinkedList(LinkedList *lls) {
	Node *tmp = lls->head;
	int tsize = 0;


	if (lls->head == NULL)
		return 0;

	while (tmp != NULL) {
		tsize++;
		tmp = tmp->next;
	}
	return tsize;
}

int insertLinkedList(LinkedList *lls, LinkedListEntry data) {
	Node *newNode, *tmp;

	tmp = lls->head;

	if (newNode = (Node *)malloc(sizeof(Node))) {
		newNode->data = data;
		newNode->next = NULL;
		if (lls->head == NULL) {
			newNode->next = lls->head;
			lls->head = newNode;
			lls->lsize++;
			return 1;
		}
		while (tmp->next != NULL) {
			tmp = tmp->next;

		}
		newNode->next = tmp->next;
		tmp->next = newNode;
		lls->lsize++;
		return 1;
	}


	return 0;
}

int removeLinkedList(LinkedList *lls, LinkedListEntry data) {
	Node *delNode, *current, *previous;

	current = NULL;
	previous = NULL;
	delNode = NULL;

	if (lls->head == NULL)
		return 0;

	current = lls->head->next;
	previous = lls->head;

	if (lls->head->data.data == data.data)
	{
		delNode = lls->head;
		lls->head = lls->head->next;
		free(delNode);
		lls->lsize--;
		return 1;
	}
	while (current != NULL)
	{
		if (current->data.data == data.data)
		{
			delNode = current;
			previous->next = current->next;
			lls->lsize--;
			free(delNode);
			return 1;
		}
		previous = current;
		current = current->next;
	}
	return 0;



}

int removeFromEndLinkedList(LinkedList *lls, int num) {
	Node *delNode, *current, *previous;

	current = lls->head;
	previous = lls->head;
	delNode = NULL;

	int	i = 1, count = (lls->lsize - num + 1);

	if (count == 1) {
		lls->head = current->next;
		delNode = current;
		lls->lsize--;
		free(delNode);
		return 1;
	}

	while (i < count && current != NULL) {
		previous = current;
		current = current->next;
		i++;
	}

	previous->next = current->next;
	delNode = current;
	lls->lsize--;
	free(delNode);
	return 1;
}

int searchLinkedList(LinkedList *lls, LinkedListEntry data) {
	Node  *current, *previous;

	current = NULL;
	previous = NULL;

	if (lls->head == NULL)
		return -1;

	current = lls->head->next;
	previous = lls->head;

	if (lls->head->data.data == data.data)
		return 1;
	int i = 2;
	while (current != NULL)
	{
		if (current->data.data == data.data)
		{
			return i;
		}
		previous = current;
		current = current->next;
		i++;
	}
	return i;

}

//void merge2LinkedList(LinkedList *lls, LinkedList *lls2) {
//
//
//}

void displayLinkedList(LinkedList *lls) {

	Node *tmp = lls->head;
	int i = 1;

	while (tmp != NULL) {
		printf("Element number %d = %d\n", i, tmp->data);
		tmp = tmp->next;
		i++;
	}


}
