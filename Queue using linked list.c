#include <stdio.h>
#include <stdlib.h>
typedef struct que{ // Created structure of node in queue
	int data;
	struct que *next;
}que;
que *front, *rear, *new, *temp;
void insert();
void delete();
void display();
void main(){
	front = NULL;
	rear = NULL;
	int ch;
	do{ // To print menu infinite times for user
		printf("\n 1. Insert ");
		printf("\n 2. Delete ");
		printf("\n 3. Display ");
		printf("\n 4. Exit ");
		printf("\n Enter your choice :- ");
		scanf("%d", &ch);
		
		switch(ch){
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			default:
				exit(0);
		}
	}while(1);
}
void insert(){ // To insert an element in queue
	new =  NULL;
	new = (que*)malloc(sizeof(que)); // Memory allocation for node 
	if(new == NULL){
		printf("\n Memory not allocated ");
		exit(1);
	}
	printf("\n Enter element in queue :- ");
	scanf("%d", &new->data); // To get input from user
	new->next = NULL;
	if(rear == NULL){ // Condition to checl=k whether the queue is empty
		front = new;
		rear = new;
	}
	else{
		rear->next = new;
		rear = new; // Pushed rear to next node after inserting element
	}
}
void delete(){ // To delete an element from queue
	if(rear == NULL){ // Condition to check if  queue is underflow
		printf("\n Queue Underflow ");
		return;
	}
	else{
		temp = front;
		printf("\n Element deleted is = %d", temp->data);
		if(front == rear){ // To check if the element we want to delete is last element
						 //if yes then initialized front and rear to NULL
			front = NULL;
			rear = NULL;
		}
		else{ 
			front = front->next; // Pushed front to next node after deleting element
		}
	}
	free(temp); // To free allocated memory to node
}
void display(){ // To display queue elements
	temp = front; 
	if(rear == NULL){ 
		printf("\n Queue Empty ");
		return;
	}
	else{
		while(temp!=NULL){ 
			printf("\n Element in queue is = %d ", temp->data);
			temp = temp->next;
		}
	}
}
