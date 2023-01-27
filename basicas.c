#define vertex int

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A estrutura graph representa um grafo. O campo adj � um ponteiro para a matriz de adjac�ncias do grafo. O campo V cont�m o n�mero de v�rtices e o campo A cont�m o n�mero de arcos do grafo. */
struct graph {
   int V; 
   int A; 
   int **adj; 
};
/* Um Graph � um ponteiro para um graph, ou seja, um Graph cont�m o endere�o de um graph. */
typedef struct graph *Graph;

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHinit() constr�i um grafo com v�rtices 0 1 .. V-1 e nenhum arco. */
Graph GRAPHinit( int V) { 
   Graph G = malloc( sizeof *G);
   G->V = V; 
   G->A = 0;
   G->adj = MATRIXint( V, V, 0);
   return G;
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o MATRIXint() aloca uma matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe valor val. */
static int **MATRIXint( int r, int c, int val) { 
   int **m = malloc( r * sizeof (int *));
   for (vertex i = 0; i < r; ++i) 
      m[i] = malloc( c * sizeof (int));
   for (vertex i = 0; i < r; ++i)
      for (vertex j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHinsertArc() insere um arco v-w no grafo G. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se o grafo j� tem um arco v-w, a fun��o n�o faz nada. */
void GRAPHinsertArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 0) {
      G->adj[v][w] = 1; 
      G->A++;
   }
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHremoveArc() remove do grafo G o arco v-w. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se n�o existe arco v-w, a fun��o n�o faz nada. */
void GRAPHremoveArc( Graph G, vertex v, vertex w) { 
   if (G->adj[v][w] == 1) {
      G->adj[v][w] = 0; 
      G->A--;
   }
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o GRAPHshow() imprime, para cada v�rtice v do grafo G, em uma linha, todos os v�rtices adjacentes a v. */
void GRAPHshow( Graph G) { 
   for (vertex v = 0; v < G->V; ++v) {
      printf( "%2d:", v);
      for (vertex w = 0; w < G->V; ++w)
         if (G->adj[v][w] == 1) 
            printf( " %2d", w);
      printf( "\n");
   }
}
