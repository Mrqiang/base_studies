#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}doublelist_t, *doublelist;

doublelist Initlist()
{
	doublelist node = (doublelist)malloc(sizeof(doublelist_t));
	if(node == NULL)
		return NULL;
	node->prev = NULL;
	node->next = NULL;

	return node;
}


int Insert_tail(doublelist h, int n)
{
	doublelist temp = (doublelist)malloc(sizeof(doublelist_t));
	if(temp == NULL)
		return -1;
	temp->data = n;
	temp->next = NULL;

	h->next = temp;
	temp->prev = h;
	h = temp;

	return 0;
}

int Show_list(doublelist h)
{
	if(h->next == NULL)
		return -1;

	while(h->next != NULL)
	{
		printf("%d ", h->data);
		h = h->next;
	}
	putchar(10);
	return 0;
}

int main()
{
	doublelist Node = Initlist();

//	printf("Node->data:%p, Node->prev:%p, Node->next:%p,Node:%p\n", &Node->data, Node->prev, Node->next, Node);
	int i = 0;
	for(i = 0; i < 8; i++)
		Insert_tail(Node, i);

	Show_list(Node);

	return 0;
}
