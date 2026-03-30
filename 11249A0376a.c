#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

  #define V 6

int min_dist(int dist[], bool visited[]);
 void greedy_dijkstra(int graph[V][V], int src);

/* Function to find vertex with minimum distance */
int min_dist(int dist[], bool visited[]) {
    int minimum = INT_MAX;
    int ind = -1;
int i;
    for ( i = 0; i < V; i++) {
        if (visited[i] == false && dist[i] <= minimum) {
            minimum = dist[i];
            ind = i;
        }
    }
    return ind;
}

/* Dijkstra Algorithm */
void greedy_dijkstra(int graph[V][V], int src) {

    int dist[V];
    bool visited[V];
int i;
    for ( i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;
int count ;
    for (count = 0; count < V - 1; count++) {

        int m = min_dist(dist, visited);
        visited[m] = true;
int j;
        for ( j = 0; j < V; j++) {

            if (!visited[j] &&
                graph[m][j] &&
                dist[m] != INT_MAX &&
                dist[m] + graph[m][j] < dist[j]) {

                dist[j] = dist[m] + graph[m][j];
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
int ;
    for (i = 0; i < V; i++) {
        printf("%c\t%d\n", 'A' + i, dist[i]);
    }
}

int main() {

    int graph[V][V] = {
        {0,1,2,0,0,0},
        {1,0,0,5,1,0},
        {2,0,0,2,3,0},
        {0,5,2,0,2,2},
        {0,1,3,2,0,1},
        {0,0,0,2,1,0}
    };

    greedy_dijkstra(graph, 0);

    return 0;
}

