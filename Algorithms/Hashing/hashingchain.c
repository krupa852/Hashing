#include<stdio.h>
#include<stdlib.h>

#define size 10
struct node{
	int data;
	struct node *next;
};

typedef struct node Node;
Node *Arr[size];

int main()
{ 

	int i;
	for(i=0;i<size;i++)
		Arr[i]=NULL;
	insert(28);
	insert(8);
	insert(3);
	insert(16);
	insert(18);
	insert(10);
	insert(20);
	insert(5);
	insert(6);
	printnum();
}

int insert(int number)
{
	
	struct node *hashnode = malloc(sizeof(struct node));
	hashnode->data = number;
	hashnode->next = NULL;
	
	// compute hash key
	int key= number%size;
	
	if(Arr[key]!=NULL){
		Node *temp = Arr[key];
		while(temp->next != NULL)
		{
    			temp = temp->next;
    		}	
		temp->next=hashnode;
	}
	else{
		Arr[key]=hashnode;
	}
}

int printnum()
{
	int i;
	for(i=0;i<size;i++)
	{
		Node *temp = Arr[i];
		printf("Arr[%d]->",i);
        	while(temp)
        	{	
            		printf("%d ->",temp->data);
            		temp = temp->next;
        	}	
        printf("NULL\n");
	}
}
	
