#include <stdio.h>

void main(){
	int n,i,sl[10],j,temp;
	printf("\n Enter the number elements :- ");
	scanf("%d", &n);
	
	printf("\n Enter elements in array :- ");
	for(i = 0; i<n;i++){
		scanf("%d", &sl[i]);
	}
	for(i=0;i<(n-1);i++){
		for(j=i+1;j<n;j++){
			if(sl[i] > sl[j]){
				temp = sl[j];
				sl[j] = sl[i];
				sl[i] = temp;
			}
		}
	}
	printf("\n Sorted array :- ");
	for(i=0;i<n;i++){
		printf("%d", sl[i]);
	}
}
