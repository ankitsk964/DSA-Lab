#include <stdio.h>
#include <stdlib.h>

typedef struct singly{ // Created structure of node
	int data;
	struct singly *next;
}sll;
sll *start, *new, *link; // Start is used to store address of starting node of linked list
						 // new is used to store newly created node address
						 // link is used to link 2 nodes

void create();
void count();
void display();
void insert();
void delete();
void main(){
	start = NULL;
	int c;
	do{ // To display the menu to user infinite times
		printf("\n 1. Create Linked list");
		printf("\n 2. Display Linked list");
		printf("\n 3. Count nodes in linked list");
		printf("\n 4. Insert a node");
		printf("\n 5. Delete a node");
		printf("\n 6. Exit ");
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
void create(){ // To create new nodes
	new = NULL;
	char choice = 'y';
	while(choice == 'y' || choice == 'Y'){
		new = (sll*)malloc(sizeof(sll));
		if(new == NULL){ // To check if the new node is created or not
			printf("\n Memory not allocated");
			exit(1);
		}
		printf("\n Node created : ");
		printf("\n Enter data :- ");
		scanf("%d", &new->data); // To enter data in newly created node
		new->next = NULL;
		if(start == NULL){ // To check if the node is first node or not
			start = new;
			link = new;
		}
		else{
			link->next = new;
			link = new;
		}
		// To get  choice of user if he/she wants to create more nodes or not
		printf("\n Do you want to create More nodes ?");
		printf("\n Press 'Y' for Yes and 'N' for No : ");
		scanf("%d", &choice);
	}
}
void display(){ // Display function to display Linked list
	
	link = start;
	while(link != NULL){
		printf("\n Data in node = %d", link->data);
		link = link->next;
	}
}
void count(){ // To count number of nodes in linked list
	int count = 0;
	link = start;
	while(link != NULL){
		count++;
		link = link->next;
	}
	printf("\n Total nodes are :- %d", count);
}
void insert(){ // To insert a new node in linked list
	int count = 1;
	sll *c = start;
	sll *temp;
	int n;
	new = (sll*)malloc(sizeof(sll));
	if(new == NULL){ // To check if new node is created or not
		printf("\n Memory not allocated");
		exit(1);
	}
	printf("\n Enter data :- "); // To enter data in newly created node
	scanf("%d", &new->data);
	new->next = NULL;
	printf("\n Enter the position to insert :- ");
	scanf("%d", &n);
	if(n == 1){ // To enter node at begining
		new->next = start;
		start = new; 
	}
	else{ // To enter node in between 2 nodes
		while(count != (n-1) && temp != NULL){
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
	printf("\n Node Inserted at position  : %d ", n);
}
void delete(){ // To delete a node from linked list
	int count = 1;
	sll *c = start;
	sll *temp;
	int n;
	
	printf("\n Enter the number of node to be deleted :- ");
	scanf("%d", &n);
	if(n==1){ // To delete a node from begining 
		temp = start;
		start = start->next;
		free(temp);
	}
	else{ 	// To delete a node  from between of 2 nodes
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
	printf("\n Node is deleted from position :: %d", n);
}
