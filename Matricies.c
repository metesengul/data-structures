#include <stdio.h>

#define N 16

int main(void) {
  
	printf("\n");

	// Initiate Array
	int arr[N][N];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			arr[i][j] = 0;
		}		
	}
	
	int c = 1;


	//**********************************

	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < i+1; j++){
			arr[i][j] = c;
			c++;
		}		
	}
/*
	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			arr[i][j] = c;
			c++;
		}		
	}*/

	//**********************************

	// Print Array
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (arr[i][j] < 10){
				printf("%d  ", arr[i][j]);
			}
			else{
				printf("%d ", arr[i][j]);
			}
			
		}
		printf("\n");
	}

  return 0;
}
