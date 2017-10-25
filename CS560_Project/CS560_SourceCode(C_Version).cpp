#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#pragma warning(disable:4996)

#define TRUE   1
#define FALSE  0
#define START  226
#define END    8
#define NNODES 233

int main()
{
	/* Read weights from "INPUT.TXT" */
	FILE* file_read = fopen("INPUT.TXT", "r");
	int n, weight;
	int weights[NNODES + 1];
	while (fscanf(file_read, "%d %d", &n, &weight) != EOF)
		weights[n] = weight;
	fclose(file_read);

	/* Initialize 'intree' and 'distances' to determine shortest path from 226 to 8. */
	int intree[NNODES + 1], distance[NNODES + 1], parent[NNODES + 1];
	for (n = 1; n <= NNODES; n++)
	{
		intree[n] = FALSE;
		distance[n] = INT_MAX;
		parent[n] = -1;
	}

	/* 'mask' is a collection of "bit"-masks for 'next' */
	int v, w, m, dist, one, ayt, tix, tee, top, bop, bot, tot, lef, ryt;
	int next[6] = { -15, -7, 8, 15, 7, -8 };
	int mask[11][6] = { { 0,0,1,1,0,0 }, /* 1 */
	{ 0,0,0,1,1,0 }, /* 8 */
	{ 1,1,0,0,0,0 }, /* 226 */
	{ 1,0,0,0,0,1 }, /* 233 */
	{ 0,0,1,1,1,0 }, /* top */
	{ 0,1,1,1,1,1 }, /* bop */
	{ 1,1,1,0,1,1 }, /* tot */
	{ 1,1,1,1,0,0 }, /* lef */
	{ 1,0,0,1,1,1 }, /* ryt */
	{ 1,1,0,0,0,1 }, /* bot */
	{ 1,1,1,1,1,1 } };
	distance[START] = weights[START];
	v = START;
	/* The 'm'th row is a bit-mask designating which of the six possible neighbors exist
	based on 'v'. */
	/* In this way, the adjacent nodes are calculated for each pass of Dijkstra's Shortest
	Path Algorithm */
	while (!intree[v])
	{
		intree[v] = TRUE;
		one = (v == 1);
		ayt = (v == 8);
		tix = (v == 226);
		tee = (v == 233);
		top = (1 < v && v < 8);
		bop = (8 < v && v < 16);
		bot = (226 < v && v < 233);
		tot = (218 < v && v < 226);
		lef = (15 < v && v < 212) && !((v - 16) % 15);
		ryt = (22 < v && v < 219) && !((v - 23) % 15);
		m = (one ? 0 :
			(ayt ? 1 :
			(tix ? 2 :
				(tee ? 3 :
				(top ? 4 :
					(bop ? 5 :
					(tot ? 6 :
						(lef ? 7 :
						(ryt ? 8 :
							(bot ? 9 :
								10))))))))));
		for (n = 0; n < 6; n++)
			if (w = (mask[m][n] ? (v + next[n]) : 0))
				if (distance[w] >(distance[v] + weights[w]))
				{
					distance[w] = distance[v] + weights[w];
					parent[w] = v;
				}
		v = 1;
		dist = INT_MAX;
		for (n = 1; n <= NNODES; n++)
			if (!intree[n] && (dist > distance[n]))
			{
				dist = distance[n];
				v = n;
			}
	}

	/* Print results to "OUTPUT.TXT" */
	int path[NNODES];
	int up;
	int count = 0;
	for (up = END; up != START; up = parent[up])
		path[count++] = up;

	FILE* file_write = fopen("OUTPUT.TXT", "w+");
	fprintf(file_write, "%d\n", START);
	while (0 < count--)
		fprintf(file_write, "%d\n", path[count]);
	fprintf(file_write, "%s%d", "MINIMAL-COST PATH COSTS: ", distance[END]);
	fclose(file_write);

	return 0;
}


//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning(disable:4996)
//
//int main()
//{
//	int d[] = {0,1,2,3,4};
//
//	FILE *file_write = fopen("OUTPUT.TXT", "w+");
//	for (int i = 0; i < 5; i++)
//	{
//		fprintf(file_write, "%d\n", d[i]);
//	}
//	fprintf(file_write, "%s %d", "MINIMAL-COST PATH COSTS:", d[3]);
//	fclose(file_write);
//	return(0);
//}