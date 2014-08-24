#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;
node* createLinkList(int num)
{
	node *p,*q;
	int i;
	node* head = (node*)malloc(sizeof(node));
	head->next = NULL;
	p = head;
	for(i = 0;i<num;i++)
	{
		q = (node*)malloc(sizeof(node));
		q->data = i+1;
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return head;
}

int main(int argc,char* argv[])
{
	node* head = createLinkList(10);
	head = head->next;
	while(head)
	{
		printf("%d\t",head->data);
		head = head->next;
	}
	printf("\n");
	return 0;
}
