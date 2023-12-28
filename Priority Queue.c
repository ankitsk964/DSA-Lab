#include <stdio.h>
#include <stdlib.h>
typedef struct priorityque{ // Created structure of node in queue
	int data;
	int priority;
	int order;
	struct priorityque *next;
}pri;
pri *front, *rear, *new, *temp, *temp1, *dis;
void insert();
void delete();
void display();
void main(){
	front=rear=NULL;
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
void insert(){
	new = NULL;
	new = (pri*)malloc(sizeof(pri)); // To allocate memory for a node
	if(new==NULL){
		printf("\n Memory not allocated ");
		exit(1);
	}
	printf("\n Enter element in queue :- ");
	scanf("%d", &new->data); // To get input from user 
	
	new->order = 1; // setting order of new node to 1
	new->next = NULL;
	if(rear == NULL){ // Condition to check if it is the 1st element in queue
		front = new;
		rear = new;
		new->order = 1;
		new->priority = 1;
	}
	else{ 
		printf("\n Enter priority of the  elemennt :- ");
		scanf("%d", &new->priority); // To get priority of new element from user
		temp = front;
		while(temp!=NULL){ 
			
			if(temp->priority == new->priority){ // To check if the new element have same priority 
												 // as other element in queue
				temp1 = temp;
				while(temp1->next!=NULL && temp1->priority == temp1->next->priority){ // To go to the last element with same priority in queue
					temp1 = temp1->next;	
				}
				new->order = temp1->order + 1; // Initialized new element order by 
											   // incremented order of last queue element with same priority
				dis = temp1->next;
				temp1->next = new;
				new->next = dis;
				break;
			}
			temp = temp->next;
		}
		if(temp == NULL){ // If there is no element with same priority as new element in queue
			rear->next = new;
			rear = new;
		}
		
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
void display(){ // To display elements of priority queue
	dis = front; 
	if(rear == NULL){ // Condition to check  if the queue is empty 
		printf("\n Queue is empty ");
		return;
	}
	else{
		while(dis != NULL){ // To print the elements of queue
			printf("\n Element is = %d  Priority = %d  Order = %d", dis->data, dis->priority, dis->order);
			dis = dis->next;
		}
	}
}
