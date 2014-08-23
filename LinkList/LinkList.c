#include "LinkList.h"

//创建一个带头指针的链表
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
