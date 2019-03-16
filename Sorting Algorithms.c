#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRSIZE 20000

void insertionSort(int[], int);
void bubbleSort(int[], int);
void selectionSort(int[], int);

void randomizeArray(int[], int);

int main () {

		clock_t start, end;
		double cpu_time_used;

		int randomArray[ARRSIZE];

		// Bubble Sort
    printf("Bubble Sort:\n");
		start = clock();
		bubbleSort(randomArray, ARRSIZE);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Runtime is %f\n\n", cpu_time_used);
		randomizeArray(randomArray, ARRSIZE);


		// Selection Sort
		printf("Selection Sort:\n");
		start = clock();
		selectionSort(randomArray, ARRSIZE);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Runtime is %f\n\n", cpu_time_used);
		randomizeArray(randomArray, ARRSIZE);

		// Insertion Sort
		printf("Insertion Sort:\n");
		start = clock();
		insertionSort(randomArray, ARRSIZE);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Runtime is %f\n\n", cpu_time_used);
    
    return(0);
}


void bubbleSort(int arr[], int n){

	int temp;
	for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
	}
}

void insertionSort(int arr[], int n){
	int value; 
   for (int i = 1; i < n; i++) 
   { 
       value = arr[i]; 
       int j = i-1; 
       while (j >= 0 && arr[j] > value) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = value; 
   } 
}

void selectionSort(int arr[], int n) 
{ 
	int position, temp;
  for (int i = 0; i < (n - 1); i++)
  {
    position = i;  
    for (int j = i + 1; j < n; j++)
    {
      if (arr[position] > arr[j])
        position = j;
    }
		temp = arr[i];
		arr[i] = arr[position];
		arr[position] = temp;
  }
}

void randomizeArray(int arr[], int n){
	srand(time(NULL));
	int range = n;
	for(int i = 0; i < n; i++)
		{
			arr[i] = rand() % range + 1;
		}
}