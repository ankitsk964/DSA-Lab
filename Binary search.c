#include <stdio.h>

int main(){
	
	int n, i, j, tag = 0, first, mid, last;
	
	printf("Enter number of elements :- ");
	scanf("%d", &n);
	int bin[n];
	printf("Enter elements :- ");
	for(i = 0 ; i < n ; i++){
		scanf("%d", &bin[i]);
	}
	printf("Enter the element to search :- ");
	scanf("%d", &j);
	
	first = 0;
	last = n - 1;
	while(first <= last){
		mid = (first + last) / 2;
		
		if(j < bin[mid]){
			last = mid - 1;
		}
		else if(j > bin[mid]){
			first = mid + 1;
		}
		else if(j == bin[mid]){
			tag = 1;
			break;
		}
	}
	if(tag == 1){
		printf("The number %d found at position %d ", j, mid + 1);
	}
	else{
		printf("Unsuccessful");
	}
	return 0;
}
