#include <stdio.h>
#include "graph.c"

int main(void) 
{
    int **graph = NULL;

    graph = init_graph(graph);
    graph = insert_edge(graph, 0, 3, 1);
    graph = insert_edge(graph, 2, 3, 1);
    graph = insert_edge(graph, 2, 0, 1);
    graph = insert_edge(graph, 3, 1, 1);
    graph = insert_vertex(graph);
    
    graph = reset_graph(graph);

    show_graph(graph);

    return (0);
}
