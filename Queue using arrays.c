#include <stdio.h>
#include <stdlib.h>
#define MAX 3 // Preprocessor directive to define MAX to 3
int que[MAX], front=-1,rear=-1,element;
void insert();
void delete();
void display();
void main(){
	
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
	if(rear==(MAX-1)){ // condition to check whether the queue is Overflow
		printf("\n Queue Overflow ");
		return;	
	}
	else{
		printf("\n Enter element :- ");
		scanf("%d", &element);
		if(front == -1){ // if the queue is empty initialize front and rear with 0
			front = 0;
			rear = 0;
		}
		else{
			rear++; // Incremented rear after inserting element
		}
		que[rear] = element;
	}
	
}
void delete(){ // To delete an element from queue
	if(rear==-1){ // Condition to check whether the queue is Underflow
		printf("\n Queue Underflow ");
		return;
	}
	else{
		printf("\n Element Deleted is %d ", que[front]);
		if(front==rear){ // To check if the element we want to delete is last element
						 //if yes then initialized front and rear to -1
			front = -1;
			rear = -1;
		}
		else{
			front++;	// Incremented front after deleting element
		}
		
	}
}
void display(){ // To display the queue elements
	int i;
	if(rear == -1){ // Condition to check whether the queue is empty or not
		printf("\n Queue Empty ");
		return;
	}
	else{
		for(i=front;i<=rear;i++){ //  To print queue elements
			printf("\n Element in queue = %d", que[i]);
		}
	}
}
