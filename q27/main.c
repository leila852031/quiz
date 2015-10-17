#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 52
void swap(int array[], int i, int j);
int main()
{
    int array[SIZE];   
    int i,j,a;
    for(i=0; i<SIZE; i++){
	array[i]=i+1;
    }
    for(j=0;j<1000;j++){
        for(i=0; i<SIZE; i++){
   	    a = rand()%52;
	    swap(array, i, a);
        }
    }
    for(i=0;i<SIZE;i++){
        printf("%d \n", array[i]);
    }
    return 0;
}

void swap(int array[], int i, int j)
{
    int tmp=*(array+i);
    *(array+i)=*(array+j);
    *(array+j)=tmp;
}

