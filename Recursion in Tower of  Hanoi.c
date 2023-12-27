#include <stdio.h>
int tower(int n, char Beg, char Aux, char End);

void main(){
	int n;
	printf("\n Enter total number of disks :- ");
	scanf("%d", &n);
	tower(n, 'A', 'B', 'C');
}
int tower(int n, char Beg, char Aux, char End){
	if(n==1){
		printf("\n Disk 1 from %c -> %c \n ", Beg , End);
		return;
	}
	tower(n-1, Beg, End, Aux);
	printf("\n Disk %d from %c -> %c \n ",n,  Beg, End);
	tower(n-1, Aux, Beg, End);
}
