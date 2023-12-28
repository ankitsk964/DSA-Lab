#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int cir[MAX], front=-1,rear=-1,element;
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
void insert(){ // To insert an element in circular queue
	if((front == 0 && rear == (MAX-1)) || front == rear + 1){ //Condition to check if the queue is overflow
		printf("\n Queue Overflow ");
		return;
	}
	
	if(rear == -1){ // Initialize front and rear to 0 if the queue is empty
		front = 0;
		rear = 0;
	}
	else{
		if(rear == MAX-1){ // If the queue is full and we deleted an element 
							//then initialize rear to 0 to insert element
			rear = 0;
		}
		else{
			rear++; // Incremented rear after inserting element in queue
		}		
	}
	printf("\n Enter element in queue :- ");
	scanf("%d", &element); // To take input from user 
	cir[rear] = element;
} 
void delete(){ // To delete an element from queue
	if(rear == -1){ // Condition to check if  the queue is underflow
		printf("\n Queue Underflow ");
		return;
	}
	else{
		printf("\n Element deleted is = %d", cir[front]);
		if(front == rear){ // If all elements are deleted so front = rear
							// then initialize front and rear to -1 
			front = -1;
			rear = -1;
		}
		else{
			if(front == MAX-1){ // If all elements are deleted and some elements left at starting of queue
								// then initialize front to 0
				front = 0;
			}
			else{ // Incremented front after deleting the element from queue
				front++;
			}
		}
	}
}
void display(){ // To display elements of queue
	int i;
	if(rear == -1){ // Condition to check if the queue is empty
		printf("\n Queue Empty ");
		return;
	}
	else{
		printf("\n Contents of queue are = ");
		if(front<=rear){ // If no elements are deleted from queue and then inserted into queue
						// then print the queue fromt front to rear
			for(i=front; i<=rear; i++){
				printf("\n Element is = %d", cir[i]);
			}
		}
		else{ // If we deleted elements from queue and then inserted elements
			for(i=front; i<MAX; i++){ // To print the elements from front to max
				printf("\n Element is = %d", cir[i]);
			}
			for(i=0; i<=rear; i++){ // To print the elements from 0 to rear
				printf("\n Element is = %d", cir[i]);
			}
		}
	}
}
