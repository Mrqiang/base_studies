#include "stdio.h"
#include "stdlib.h"


typedef struct node
{
	int data;
	struct node *next;
}linklist_t, *linklist;



linklist Create()
{
	linklist h = (linklist)malloc(sizeof(linklist_t));
	h->next = NULL;

	return h;
}

int Insert_head(linklist h, int Data)
{
	if(!h)
	{
		printf("linklist is NULL\n");
		return -1;
	}

	linklist temp = (linklist)malloc(sizeof(linklist_t));
	temp->data = Data;

	temp->next = h->next;
	h->next = temp;

	return 0;
}

int Insert_tail(linklist h, int Data)
{
	if(!h)
	{
		printf("linklist is NULL\n");
		return -1;
	}

	linklist temp = (linklist)malloc(sizeof(linklist_t));
	temp->data = Data;

	while(h->next != NULL)
		h = h->next;

	h->next = temp;
	temp->next = NULL;

	return 0;
}

int Insert_sort(linklist h, int Data)
{
	if(!h)
	{
		printf("linklist is NULL\n");
		return -1;
	}

	linklist temp = (linklist)malloc(sizeof(linklist_t));
	temp->data = Data;

	while(h->next != NULL && h->next->data < Data)
		h = h->next;

	temp->next = h->next;
	h->next = temp;

	return 0;
}

/*Data为0时, 按顺序删除,不为0时根据取值进行删除*/
int Delete(linklist h, int Data)
{
	if(!h)
	{
		printf("linklist is NULL\n");
		return -1;
	}

	linklist temp = NULL;
	if(!Data)
	{
		temp = h->next;
		h->next = temp->next;
	}
	else
	{
		while(h->next != NULL && h->next->data != Data)
		{
			h = h->next;
		}

		if(h->next != NULL)
		{
			temp = h->next;
			h->next = temp->next;
		}
		else
			return 0;
	}
	free(temp);
	temp = NULL;
	return 0;
}

int Show(linklist h)
{
	if(!h)
	{
		printf("linklist is NULL\n");
		return -1;
	}

	while(h->next != NULL)
	{
		h = h->next;
		printf(" %d", h->data);
	}

	return 0;
}



int main()
{
	linklist node_head = Create();
	linklist node_tail = Create();
	linklist node_sort = Create();

	int i = 0;

	for(i = 0; i < 10; i++)
	{
		Insert_head(node_head, i);
	}

	Show(node_head);
	putchar('\n');
	for(i = 10; i < 20; i++)
	{
		Insert_tail(node_tail, i);
	}

	Show(node_tail);
	putchar('\n');
	Insert_sort(node_sort, 3);
	Insert_sort(node_sort, 1);
	Insert_sort(node_sort, 5);
	Insert_sort(node_sort, 2);
	Insert_sort(node_sort, 10);
	Insert_sort(node_sort, 7);
	Insert_sort(node_sort, 6);
	Insert_sort(node_sort, 4);
	Insert_sort(node_sort, 9);

	Show(node_sort);
	putchar(10);
	Delete(node_sort, 0);
	Show(node_sort);

	getchar();

	return 0;
}
