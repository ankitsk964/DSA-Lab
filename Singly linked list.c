#include <stdio.h>
#include <stdlib.h>

typedef struct singly{
	int data;
	struct singly *next;
}sll;
sll *start, *new, *link;

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
		new = (sll*)malloc(sizeof(sll));
		if(new == NULL){
			printf("\n Memory not allocated");
			exit(1);
		}
		printf("\n Enter data :- ");
		scanf("%d", &new->data);
		new->next = NULL;
		if(start == NULL){
			start = new;
			link = new;
		}
		else{
			link->next = new;
			link = new;
		}
		printf("\n Do you want to create More nodes ?");
		printf("\n Press 'Y' for Yes and 'N' for No : ");
		choice = getche();
	}
}
void display(){
	
	link = start;
	while(link != NULL){
		printf("\n Data in node = %d", link->data);
		link = link->next;
	}
}
void count(){
	int count = 0;
	link = start;
	while(link != NULL){
		count++;
		link = link->next;
	}
	printf("\n Total nodes are :- %d", count);
}
void insert(){
	int count = 1;
	sll *c = start;
	sll *temp;
	int n;
	new = (sll*)malloc(sizeof(sll));
	if(new == NULL){
		printf("\n Memory not allocated");
		exit(1);
	}
	printf("\n Enter data :- ");
	scanf("%d", &new->data);
	new->next = NULL;
	printf("\n Enter the position to insert :- ");
	scanf("%d", &n);
	if(n == 1){
		new->next = start;
		start = new; 
	}
	else{
		while(count != (n-1)){
			count++;
			c = c -> next;
			if(count == (n-1)){
				temp = c->next;
				c->next = new;
				new->next = temp;
				break;
			}
		}
	}
}
void delete(){
	int count = 1;
	sll *c = start;
	sll *temp;
	int n;
	
	printf("\n Enter the number of node to be deleted :- ");
	scanf("%d", &n);
	if(n==1){
		temp = start;
		start = start->next;
		free(temp);
	}
	else{
		while(count != (n-1)){
			count++;
			c = c -> next;
			if(count == (n-1)){
				temp = c->next;
				c->next = temp->next;
				free(temp);	
			}
		}	
	}
}
