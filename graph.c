#include <stdio.h>
#include <stdlib.h>
#define START 4

int V = START;


int ** init_graph(int **graph) 
{
    graph = malloc(sizeof(int*) * V);

    for (int i = 0; i < V; i++) 
    {
        graph[i] = malloc(sizeof(int) * V);
    }

    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            graph[i][j] = 0;
        }
    }

    return graph;
}


int ** insert_vertex(int **graph) 
{
    V++;

    for (int i = 0; i < V; i++) 
    {
        graph[i] = realloc(graph[i], sizeof(int) * V);
    }

    for (int i = 0; i < V - 1; i++) 
    {
        graph[i][V - 1] = 0;
    }

    graph = realloc(graph, sizeof(int*) * V);
    graph[V - 1] = malloc(sizeof(int) * V);

    for (int j = 0; j < V; j++) 
    {
        graph[V - 1][j] = 0;
    }

    return graph;
}


int ** remove_vertex(int **graph) 
{
    for (int i = 0; i < V; i++) 
    {
        graph[i] = realloc(graph[i], sizeof(int) * (V - 1));
    }

    graph = realloc(graph, sizeof(int *) * (V - 1));
    V--;

    return graph;
}


int ** insert_edge(int **graph, int origin, int destiny, int distance) 
{
    graph[origin][destiny] = distance;
    return graph;
}


int ** remove_edge(int **graph, int origin, int destiny) 
{
    graph[origin][destiny] = 0;
    return graph;
}


int get_entrance_degree(int **graph, int vertex) 
{
    int cont = 0;
    for (int i = 0; i < V; i++) 
    {
        if (graph[i][vertex] != 0) cont++;
    }
    return cont;
}


int get_exit_degree(int **graph, int vertex) 
{
    int cont = 0;
    for (int i = 0; i < V; i++) 
    {
        if (graph[vertex][i] != 0) cont++;
    }
    return cont;
}


int ** destroy_graph(int **graph) 
{
    V = START;

    graph = malloc(sizeof(int*) * V);

    for (int i = 0; i < V; i++) 
    {
        graph[i] = malloc(sizeof(int) * V);
    }

    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            graph[i][j] = 0;
        }
    }

    return graph;
}


void show_graph(int **graph) 
{
    for (int i = 0; i < V; i++) 
    {
        for (int j = 0; j < V; j++) 
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}