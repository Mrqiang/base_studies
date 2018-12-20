#include "stdio.h"
#include "stdlib.h"


typedef struct node
{
	int data;
	struct node *next;
}looplist_t, *looplist;


looplist Create()
{
	looplist h = (looplist)malloc(sizeof(looplist_t));
	h->next = h;

	return h;
}

int Insert_head(looplist h, int Data)
{
	
	looplist temp = (looplist)malloc(sizeof(looplist_t));
	temp->data = Data;

	temp->next = h->next;
	h->next = temp;

	return 0;
}

int Insert_tail(looplist h, int Data)
{
	looplist temp = (looplist)malloc(sizeof(looplist_t));
	temp->data = Data;

	looplist p = h;
	while(h->next != p)
		h = h->next;

	h->next = temp;
	temp->next = p;

	return 0;
}

int Insert_sort(looplist h, int Data)
{
	looplist temp = (looplist)malloc(sizeof(looplist_t));
	temp->data = Data;

	looplist p = h;
	while(h->next != p && h->next->data < Data)
		h = h->next;

	temp->next = h->next;
	h->next = temp;

	return 0;
}

/*Data为0时, 按顺序删除,不为0时根据取值进行删除*/
int Delete(looplist h, int Data)
{
	looplist temp = NULL;
	looplist p = h;
	if(!Data)
	{
		temp = h->next;
		h->next = temp->next;
	}
	else
	{
		while(h->next != p && h->next->data != Data)
			h = h->next;

		if(h->next != p)
		{
			temp = h->next;
			h->next = temp->next;
		}
		else
			return -1;
	}
	free(temp);
	temp = NULL;
	return 0;
}

looplist cut_head(looplist h)
{
	looplist p = h;

	while(h->next != p)
		h = h->next;

	h->next = p->next;
	free(p);
	p = NULL;

	return h->next;
	
}

int Show(looplist h, int no_head)
{
	if(h->next == h)
	{
		printf("looplist is NULL\n");
		return -1;
	}

	looplist p = h;
	if(no_head)
	{
		while(h->next != p)
		{
			printf("%d ", h->data);
			h = h->next;
		}
		printf("%d ", h->data);
	}
	else
	{
		while(h->next != p)
		{
			h = h->next;
			printf("%d ", h->data);
		}
	}
	putchar(10);

	return 0;
}



int main()
{
	looplist node_head = Create();
	looplist node_tail = Create();
	looplist node_sort = Create();

	int i = 0;

	for(i = 0; i < 10; i++)
	{
		Insert_head(node_head, i);
	}
	Show(node_head, 0);

	for(i = 10; i < 20; i++)
	{
		Insert_tail(node_tail, i);
	}
	Show(node_tail, 0);

	Insert_sort(node_sort, 3);
	Insert_sort(node_sort, 1);
	Insert_sort(node_sort, 5);
	Insert_sort(node_sort, 2);
	Insert_sort(node_sort, 10);
	Insert_sort(node_sort, 7);
	Insert_sort(node_sort, 6);
	Insert_sort(node_sort, 4);
	Insert_sort(node_sort, 9);
	printf("cut head before:");
	Show(node_sort, 0);

//	if(Delete(node_sort, 11) < 0)
//		printf("delete fail\n");
	looplist _node = cut_head(node_sort);
	printf("cut head later:");
	Show(_node, 1);

	return 0;
}
