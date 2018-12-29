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

/*头插法*/
int Insert_head(doublelist h, int n)
{
	doublelist temp = (doublelist)malloc(sizeof(doublelist_t));

	if(temp == NULL)
		return -1;


	temp->data = n;
	if(h->next == NULL)	//if is head , insert the behind
	{
		temp->next = NULL;
		h->next = temp;
		temp->prev = h;
	}
	else				//insert the first behind
	{
		h->next->prev = temp;
		temp->prev = h;

		temp->next = h->next;
		h->next = temp;

	}

	return 0;
}


int Insert_Sort(doublelist h, int n)
{
	doublelist temp = (doublelist)malloc(sizeof(doublelist_t));
	if(temp == NULL)
		return -1;

	temp->data = n;

	while(h->next != NULL && h->next->data < n )
		h = h->next;

	if(h->next == NULL)
	{
		temp->next = NULL;
		h->next = temp;
		temp->prev = h;
	}
	else
	{
		h->next->prev = temp;
		temp->prev = h;

		temp->next = h->next;
		h->next = temp;
	}
	return 0;
}

/*尾插法*/
int Insert_tail(doublelist h, int n)
{
	doublelist temp = (doublelist)malloc(sizeof(doublelist_t));
	if(temp == NULL)
		return -1;
	temp->data = n;
	temp->next = NULL;

	while(h->next != NULL)
		h = h->next;

	h->next = temp;
	temp->prev = h;
#if 0
	h->next = temp;
	temp->prev = h;
	h = temp;
#endif
	return 0;
}


doublelist Find_node(doublelist h, int data)
{
	
	if(h->next == NULL)
		return NULL;

	while(h->next != NULL)
	{
		if(h->next->data == data)
			return h;
		h = h->next;
	}

	printf("not found\n");
	return NULL;
}


int Show_list(doublelist h)
{
	if(h->next == NULL)
		return -1;

	while(h->next != NULL)
	{
		h = h->next;
		printf("%d ", h->data);
	}
	putchar(10);
	return 0;
}

int main()
{
	doublelist Node = Initlist();
	doublelist Node2 = Initlist();
	doublelist Node3 = Initlist();

//	printf("Node->data:%p, Node->prev:%p, Node->next:%p,Node:%p\n", &Node->data, Node->prev, Node->next, Node);
	int i = 0;
	for(i = 0; i < 8; i++)
		Insert_tail(Node, i);
	
	Show_list(Node);
	
	for(i = 10; i < 18; i++)
		Insert_head(Node2, i);

	Show_list(Node2);


	Insert_Sort(Node3, 8);
	Insert_Sort(Node3, 3);
	Insert_Sort(Node3, 5);
	Insert_Sort(Node3, 4);
	Insert_Sort(Node3, 9);
	Insert_Sort(Node3, 1);

	Show_list(Node3);

	Node3 = Find_node(Node3, 5);

	Show_list(Node3);

	return 0;
}
