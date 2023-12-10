#include <stdio.h>

int main(){
	
	int n, i, j, tag;
	printf("Enter the number of elements :- ");
	scanf("%d", &n);
	int linear[n];
	printf("Enter the elements :- ");
	for(i = 0 ; i < n ; i++){
		scanf("%d", &linear[i]); 
	}
	
	printf("Enter the element to search :- ");
	scanf("%d", &j);
	
	for(i = 0 ; i < n ; i++){
		if(j == linear[i]){
			tag = 1;
			break;
		}
		else{
			tag = 0;
		}
	}
	
	if(tag == 1){
		printf("The number %d found at position %d", j, i+1);
	}
	else{
		printf("Unsuccessful");
	}
	return 0;
}
