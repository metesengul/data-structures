#include <stdio.h>

#define V 5
#define INF 10000
int inMST[V];

// Returns 1 if edge u-v is a valid edge to be 
// include in MST. An edge is valid if one end is 
// already included in MST and other is not in MST. 
int isValidEdge(int u, int v) 
{ 
	if (u == v) 
		return 0; 
	if (inMST[u] == 0 && inMST[v] == 0) 
		return 0; 
	else if (inMST[u] == 1 && inMST[v] == 1) 
		return 0; 
	return 1;
} 


void primMST(int cost[V][V]) 
{ 
	
	// Initilize inMST and include first vertex.
	for(int i = 0; i < V; i++){
		inMST[i] = 0;
	}
	inMST[0] = 1; 

	int edge_count = 0, mincost = 0; 
	while (edge_count < V - 1) { 	
		int min = INF, a = -1, b = -1; 
		for (int i = 0; i < V; i++) { 
			for (int j = 0; j < V; j++) {			 
				if (isValidEdge(i, j) && cost[i][j] < min) { 
					min = cost[i][j]; 
					a = i; 
					b = j; 		
				} 
			} 
		} 

		if (a != -1 && b != -1) {
			// Include both a and b verticies in MST.
			inMST[b] = inMST[a] = 1;

			edge_count++;
			mincost += min; 

			printf("Edge %d:(%d, %d) cost: %d \n", edge_count, a, b, min); 
		}

	} 
	printf("\n Minimum cost= %d \n", mincost); 
} 

int main() 
{ 
	int cost[V][V] = { 
		{ INF, 2, INF, 6, INF }, 
		{ 2, INF, 3, 8, 5 }, 
		{ INF, 3, INF, INF, 7 }, 
		{ 6, 8, INF, INF, 9 }, 
		{ INF, 5, 7, 9, INF }, 
	}; 

	primMST(cost); 

	return 0; 
}