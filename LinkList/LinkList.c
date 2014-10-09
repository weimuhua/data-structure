#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

node* createLinkList(int num);
void deleteNode(node* head,node* toBeDeleted);
void printList(node* head);

int main(int argc,char* argv[])
{
	node* head = createLinkList(10);
	printList(head);
	deleteNode(head,head->next->next);
	printList(head);
	return 0;
}

void printList(node* head)
{
	if(head == NULL || head->next == NULL)
		return;
	head = head->next;
	while(head)
	{
		printf("%d\t",head->data);
		head = head->next;
	}
	printf("\n");
}

//O(1)复杂度删除一个结点，由用户保证链表中包含此结点
void deleteNode(node* head,node* toBeDeleted)
{
	if(!head || !toBeDeleted)
		return;

	if(toBeDeleted->next != NULL)
	{
		node* pNext = toBeDeleted->next;
		toBeDeleted->data = pNext->data;
		toBeDeleted->next = pNext->next;
		free(pNext);
		pNext = NULL;
	}
	else if(head->next == toBeDeleted)
	{
		free(toBeDeleted);
		toBeDeleted = NULL;
		head->next = NULL;
	}
	else
	{
		while(head->next != toBeDeleted)
		{
			head = head->next;
		}
		head->next = NULL;
		free(toBeDeleted);
		toBeDeleted = NULL;
	}
}

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


