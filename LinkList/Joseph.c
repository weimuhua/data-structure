#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

node* createLinkList(int n);
void Joseph(int len,int n);
void delete(node* p);

int main(int argc,char** argv)
{
	int len,n;
	scanf("%d %d",&len,&n);
	Joseph(len,n);
	return 0;
}

void Joseph(int len,int n)
{
	int i = 0;
	node* head = createLinkList(len);
	while(len != 1)
	{
		for(i = 0;i < n;i++)
		{
			head = head->next;
		}
		delete(head);
		len--;
	}
	printf("%d",head->data);
	printf("\n");
}

void delete(node* p)
{
	if(p->next != NULL)
	{
		printf("%d\t",p->data);
		node *q = p->next;
		p->data = q->data;
		p->next = q->next;
		q->next = NULL;
		free(q);
	}
}

node* createLinkList(int n)
{
	node *head,*p,*q;
	int i = 0;
	head = (node*)malloc(sizeof(node));
	head->data = 1;
	head->next = NULL;
	p = head;
	for(i = 1;i < n;i++)
	{
		q = (node*)malloc(sizeof(node));
		q->data = i + 1;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	q->next = head;
	return head;
}
