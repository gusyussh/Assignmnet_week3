/*====================================
File name: exerc_3_1.c
Date: 2014‐02‐10
Group Number: 9
Members that contributed:
Shireen Yusur
Saulius Eidukas
Hristo Spilkov
Demonstration code:
======================================*/
#include <stdio.h>

//Function declaration
//search function takes arugments:
//number - number you looking, tab[] - array of int, size - size of array
int search_number(int number, int tab[], int size);
void sort(int number,int tab[]);
int find_min(int tab[], int size);




int main(){
	int test[]={1,2,34,5,67,3,23,12,13,10};
	int lenght = sizeof(test)/sizeof(test[0]);
	int result = search_number(12,test,lenght);
	int minRes = find_min(test, lenght);
	printf("a) position of %d is %d\n",12,result);
	sort(lenght,test);
	return 0;
}

//searches number in the list, and if it found it returns possition of that number
//otherwise it returns -1
int search_number(int number,int tab[],int size){
	int i = 0;
	while (i<=size){
		if(number == tab[i])
			return i;
		i++;
	}
	return -1;
}


//find lowest value in the array list
int find_min(int tab[], int size){
	int i;
	int min = tab[0];
	for(i = 0; i<size;i++){
		if (min > tab[i]){
			min =  tab[i];
		}
	}
	return min;
}

//swap the minimum with the first in the list
void sort(int number,int tab[]){
	int i,n;
	int min;
	int temp;
	int minL;
	for(i=0;i<number;i++){
		//find minimum value and arrays start position increased by i
		//size of array decreased by i
		 min = find_min(tab+i,number-i);
		 minL = search_number(min,tab,number);
		 //swapping places
		 temp = tab[i];
		 tab[i] = min;
		 tab[minL] = temp;

	}
	printf("sorted list: \n");
	for(n=0;n<number;n++){
		printf("%d ",tab[n]);
	}
}
