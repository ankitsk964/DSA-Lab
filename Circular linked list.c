#include <stdio.h>
#include <stdlib.h>
// Created the structure of node of circular linked list
typedef struct circular{
	int data;
	struct circular *next;
}cll;
cll *start, *new, *link; // Initialized the start pointer to hold the starting address of linked list
						 // new pointer to hold the address of newly created node
						 // link pointer to link two nodes 

void create();
void count();
void display();
void insert();
void delete();
void main(){
	start = NULL;
	int c;
	// To Show the Choice menu Infinite times
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
int counting = 0; // Variable to count the number of nodes in the Circular linked list
void create(){
	new = NULL;
	char choice = 'y';
	while(choice == 'y' || choice == 'Y'){
		new = (cll*)malloc(sizeof(cll));
		if(new==NULL){
			printf("\n Memory not allocated");
			exit(1);
		}
		printf("\n Enter data in node :- ");
		scanf("%d", &new->data);
		new->next = NULL;
		
		if(start == NULL){
			start = new;
			link = new;
		}
		else{
			link->next = new;
			link = new;
			link->next = start;
		}
		counting++;
		printf("\n Do you want to create more nodes ?");
		printf("\n Enter Y for Yes and N for No :- ");
		scanf(" %c", &choice);
	}
}
void display(){	// To print Circular linked list
	int i=1,c;
	if(counting==0){
		printf("\n Linked list is empty");
		return;
	}
	printf("\n Enter the number of times you want to print the list :- ");
	scanf("%d", &c);
	cll *temp;
	temp = start;
	while(i<=c*counting){ 
		printf("\n Data in node = %d", temp->data);
		temp = temp->next;
		i++;
	}
	
}
void count(){
	printf("\n The total numeber of nodes = %d", counting);
}
void insert(){
	int n,c=1;
	cll *temp = start;
	
	
	new = (cll*)malloc(sizeof(cll));
	if(new == NULL){
		printf("\n Memory not allocated");
		exit(1);
	}
	printf("\n Enter data in node :- ");
	scanf("%d", &new->data);
	printf("\n Enter the position to insert node :- ");
	scanf("%d", &n);
	new->next = NULL;
	
	if(n==1 && start != NULL){
		new->next = start;
		start = new;
	}
	else if(start==NULL){
		start = new;
		link = new;
	}
	if(n>1){
		if(n>counting){
			printf("\n Enter a value from 1 to %d", counting);
			return;
		}
		while(c!=(n-1)){
			c++;
			temp = temp->next;
		}
		new->next = temp->next;
		temp->next = new;
		
		
	}
	counting++;
}
void delete(){
	cll *temp, *tempadd;
	int n,c=1;
	printf("\n ENter the position of node to be deleted :- ");
	scanf("%d", &n);
	
	if(n==1 && start!= NULL){
		printf("\n The node %d is deleted from position %d", start->data, n);
		temp = start;
		start = start->next;
		free(temp);	
	}
	else if(start==NULL){
		printf("\n Linked list Underflow");
		return;
	}
	if(n>1){
		tempadd = start;
		while(c!=(n-1)){
			c++;
			tempadd = tempadd->next;
		}
		printf("\n Tne node %d is deleted from position %d ", tempadd->data, n);
		temp = tempadd->next;
		tempadd->next = temp->next;
		free(temp);
	}
	counting--;
	
}
