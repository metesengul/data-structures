#include <stdio.h>

#define V 5 
#define INF 10000 
int parent[V]; 
  
int findSet(int i) 
{ 
	while (parent[i] != i) 
		i = parent[i]; 
	return i; 
}

void unionSet(int i, int j) 
{ 
	int a = findSet(i); 
	int b = findSet(j); 
	parent[a] = b; 
} 
  
void kruskalMST(int cost[V][V]) 
{ 

	// Initialize sets of disjoint sets. 
	for (int i = 0; i < V; i++) 
		parent[i] = i; 

	int edge_count = 0, mincost = 0; 
	while (edge_count < V - 1) { 
		int min = INF, a = -1, b = -1; 
		for (int i = 0; i < V; i++) { 
			for (int j = 0; j < V; j++) { 
				if (findSet(i) != findSet(j) && cost[i][j] < min) { 
					min = cost[i][j]; 
					a = i; 
					b = j; 
				} 
			} 
		} 

		if (a != -1 && b != -1) {
			// Union sets of a and b vertecies.
			unionSet(a, b);

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

	kruskalMST(cost); 

	return 0; 
}
