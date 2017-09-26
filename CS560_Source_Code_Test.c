#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE   1
#define FALSE  0
#define START  226
#define END    8
#define NNODES 233
#define LOOP_NODES for(n = 1; n <= NNODES; n++)

typedef struct
{
  int y, weight;
  struct edgenode* next[3]; /* pointers to next node adjacent to yth node */
} edgenode;

int main(int argc, char* argv[])
{
  FILE* file_read = fopen("INPUT.TXT", "r");
  char line[8];
  char* c;

  /* Initialize edges from file */
  edgenode* edges[NNODES+1];
  int n;
  while (fgets(line, sizeof(line), file_read))
    {
      while ( (c = strtok(line," \n")) != NULL )
	{
	  n = atoi(c);
	  edges[n]->y = n;
	  edges[n]->weight = atoi(c = strtok(line," \n"));
	}
    }
  fclose(file_read);

  /* Adjacent nodes */
  edgenode* p;
  int not_right_edge;
  LOOP_NODES
    {
      not_right_edge = (0 < ((n-23)%15));
      p = edges[n];
      p->next[0] = (15 < n) ? edges[n-15] : NULL;
      p->next[1] = ((8 < n && n < 23) || (22 < n && not_right_edge)) ? edges[n-7] : NULL;
      p->next[2] = (n < 226 && not_right_edge && n != 8) ? edges[n+8] : NULL;
    }

  /* Dijkstra Shortest Path */
  int intree[NNODES+1], distance[NNODES+1], parent[NNODES+1];
  LOOP_NODES
    {
      intree[n] = FALSE;
      distance[n] = INT_MAX;
      parent[n] = -1;
    }

  int v, w, weight, dist;
  distance[START] = edges[START]->weight;
  v = START;
  while ( !intree[v] )
    {
      intree[v] = TRUE;
      p = edges[v];
      for (n = 0; n < 3; n++)
	{
	  if (p->next[n] != NULL)
	    {
	    w = ((edgenode*) p->next[n])->y;
	    weight = ((edgenode*) p->next[n])->weight;
	    if ( distance[w] > (distance[v] + weight) )
	      {
		distance[w] = distance[v] + weight;
		parent[w] = v;
	      }
	    }
	}

      v = 1;
      dist = INT_MAX;
      LOOP_NODES /* guarantees v is lowest distance node */
	{
	  if ( !intree[n] && (dist > distance[n]) )
	    {
	      dist = distance[n];
	      v = n;
	    }
	}
    }

  /* Print results */
  int path[NNODES];
  int up;
  int count = 0;
  for (up = END; up == START; up = parent[up])
    {
      path[count++] = up;
    }
  FILE* file_write = fopen("OUTPUT.txt", "w+");
  char out[4];
  while (count--)
    {
      snprintf(out,"%d", path[count]);
      fputs(out, file_write);
      fputs("\n", file_write);
    }
  fputs("MINIMAL-COST PATH COSTS: ", file_write);
  snprintf(out, "%d", distance[END]);
  fputs(out, file_write);
  fclose(file_write);

  return 0;
}
