#include <stdio.h>
#include <stdlib.h>
// Created the structure of node
typedef struct doubly{
	struct doubly *back;
	int data;
	struct doubly *next;
}dll;
dll *start, *new, *link; // Initialized the start pointer to hold the starting address of linked list
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
		new = (dll*)malloc(sizeof(dll));
							
		if(new == NULL){ 		// To check if the new node is created or not
			printf("\n Memory not allocated");
			exit(1);
		}
		// Too enter data in node
		printf("\n Enter data in node :- ");
		scanf("%d", &new->data);
		new->back = NULL;
		new->next = NULL;
		
		if(start == NULL){	// To check if the node is first node or not
			start = new;
			link  = new;
		}
		else{
			link->next = new;
			new->back = link;
			link = new;
		}
		// To get  choice of user if he/she wants to create more nodes or not
		printf("\n Do you want to create more nodes ?");
		printf("\n Press 'Y' for Yes and 'N' for NO :- ");
		scanf(" %c", &choice);
	}
}

void display(){	// Display function to display Linked list 
	dll *tempf, *tempb;
	tempb = link;
	tempf = start;
	printf("\n List in forward direction : ");
	while(tempf != NULL){	// To display linked list in forward
		printf("%d", tempf->data);
		tempf = tempf->next;
	}
	printf("\n List in backward direction : ");
	while(tempb != NULL){	// To display linked list in backward direction
		printf("%d", tempb->data);
		tempb = tempb->back;
	}
}
void count(){	// To count number of nodes in linked list
	int count = 0;
	link = start;
	while(link != NULL){
		count++;
		link = link->next;	
	}	
	printf("\n Number of nodes are :- %d", count);
}
void insert(){ // To insert a new node in linked list
	int n,c=1;
	dll *tem = start;
	new = (dll*)malloc(sizeof(dll));
	if(new==NULL){ // To check if new node is created or not
		printf("\n Memory not allocated ");
		exit(1);
	}
	// To enter data in node
	printf("\n Enter data in node :- ");
	scanf("%d", &new->data);
	new->back = NULL;
	new->next = NULL;
	printf("\n Enter the position to insert node :- ");
	scanf("%d", &n);
	if(n==1 && start!=NULL){	// To enter node at begining
		new->next = start;
		start->back = new;
		start=new;
	}
	if(n>1){	// To enter node in between 2 nodes
		while(tem!=NULL && c!=(n-1)){
			c++;
			tem=tem->next;
		}
		new->next = tem->next;
		tem->next->back = new;
		tem->next = new;
		new->back = tem;
	}
}

void delete(){ // To delete a node from linked list
	int n,c=1;
	dll *temp = start, *tempadd;
	printf("\n Enter the node to be deleted :- ");
	scanf("%d", &n);
	if(n==1){	// To delete a node from begining 
		printf("\n Node deleted is %d from position %d", start->data, n);
		tempadd = start;
		start = start->next;
		start->back = NULL;
	
	}
	if(n>1){	// To delete a node  from between of 2 nodes
		while(temp!=NULL && c!=(n-1)){
			c++;
			temp=temp->next;
		}
		printf("\n Node deleted is %d from position %d", temp->next->data, n);
		tempadd = temp->next;
		temp->next = tempadd->next;
		tempadd->next->back = temp;
	}
	free(tempadd);
	
}
