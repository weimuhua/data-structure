#include "LinkList.h"

int main(int argc,char* argv[])
{
	node* head;
	head = (node*)createLinkList(10);
	head = head->next;
	while(head)
	{
		printf("%d\t",head->data);
		head = head->next;
	}
	printf("\n");
	return 0;
}
