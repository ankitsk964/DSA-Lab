#include <stdio.h>
#include <stdlib.h>

typedef struct doubly{
	struct doubly *back;
	int data;
	struct doubly *next;
}dll;
dll *start, *new, *link;

void create();
void count();
void display();
void insert();
void delete();
void main(){
	start = NULL;
	int c;
	do{
		printf("\n 1. Create Linked list");
		printf("\n 2. Display Linked list");
		printf("\n 3. Count nodes in linked list");
		printf("\n 4. Insert a node");
		printf("\n 5. Delete a node");
		printf("\n Enter you choice :- ");
		scanf("%d", &c);
		
		switch(c){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				count();
				break;
			case 4:
				insert();
				break;
			case 5:
				delete();
				break;
			default:
				exit(0);
				break;
			
		}
	}while(1);
}
void create(){
	new = NULL;
	char choice = 'y';
	while(choice == 'y' || choice == 'Y'){
		new = (dll*)malloc(sizeof(dll));
		if(new == NULL){
			printf("\n Memory  ot allocated");
			exit(1);
		}
		printf("\n Enter data in node :- ");
		scanf("%d", &new->data);
		new->back = NULL;
		new->next = NULL;
	
		if(start == NULL){
			start = new;
			link  = new;
		}
		else{
			link->next = new;
			new->back = link;
			link = new;
		}
		printf("\n Do you want to create more nodes ?");
		printf("\n Press 'Y' for Yes and 'N' for NO :- ");
		choice = getche();
	}
}
void display(){
	dll *temp;
	temp = link;
	link = start;
	printf("\n List in forward direction : ");
	while(link != NULL){
		printf("%d", link->data);
		link = link->next;
	}
	printf("\n List in backward direction : ");
	while(temp != NULL){
		printf("%d", temp->data);
		temp = temp->back;
	}
}
void count(){
	int count = 0;
	link = start;
	while(link != NULL){
		count++;
		link = link->next;	
	}	
	printf("\n Number of nodes are :- %d", count);
}
void insert(){
	int n,c=1;
	dll *temp;
	new = (dll*)malloc(sizeof(dll));
	if(new == NULL){
		printf("\n Memory not allocated");
		exit(1);
	}
	printf("\n Enter data in node :- ");
	scanf("%d", &new->data);
	printf("\n Enter the position to add node :- ");
	scanf("%d", &n);
	new->back = NULL;
	new->next = NULL;
	if(n==1){
		new->next = start;
		start->back = new;
		start = new;
	}
	if(n>1){
		temp = start;
		while(c != (n-1)){
			c++;
			temp = temp->next;
			if(c== (n-1)){ 
				
				new->next = temp->next;
				temp->next = new;
				temp->next->back = new;
				new->back = temp;
				break;
			}
			
		}
	}
}
void delete(){
	printf("not completed");
}
