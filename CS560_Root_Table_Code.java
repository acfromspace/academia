package thisIsWhere;

import java.util.Scanner;

public class ToTest {
	
	public static void main(String[] args) {
		
	int maxnodes = 31;
	Scanner keyboard = new Scanner(System.in);
	int h, i, j, k, m, n;
	double min;
	double[] p = new double[maxnodes+1];
	double[] q = new double[maxnodes+1];
	double[][] cost = new double[maxnodes+1][maxnodes+1];
	double[][] weight = new double[maxnodes+1][maxnodes+1];
	int[][] root = new int[maxnodes+1][maxnodes+1];
	
	// User input f6or number of nodes
	System.out.print("Enter number of nodes: ");
	n = keyboard.nextInt();
	
	// Create empty tables
	for(i = 0; i <= n; i++)
		for(j = 0; j <= n; j++)
		{ cost[i][j] = 0.0; weight[i][j] = 0.0; root[i][j] = 0; }
	
	for(i = 1; i <= n; i++)
	{ System.out.print("Enter prob node["+i+"]: "); p[i] = keyboard.nextDouble(); }
	
	for(i = 0; i <= n; i++)
	{ System.out.print("Enter prob gap["+i+"]: "); q[i] = keyboard.nextDouble(); }
	
	for(i = 0; i <= n; i++)
		weight[i][i] = q[i];
	
	for(i = 0; i < n; i++)
	{
		j 				= i + 1;
		weight[i][j] 	= q[i] + p[j] + q[j];
		cost[i][j] 		= weight[i][j];
		root[i][j] 		= j;
	}
	
	for(h = 2; h <= n; h++)
		for( i = 0; i <= n-h; i++)
		{
			j = i + h;
			weight[i][j] = weight[i][j-1] + p[j] + q[j];
			k = root[i][j-1];
			min = cost[i][k-1] + cost[k][j];
			for(m = k+1; m <= root[i+1][j]; m++)
				if(cost[i][m-1] + cost[m][j] < min)
				{
					k = m;
					min = cost[i][m-1] + cost[m][j];
				}
			cost[i][j] = weight[i][j] + min;
			root[i][j] = k;
		}
	
	System.out.println(" ROOT ");
	for(i = 0; i <= n; i++)
		{
			for(j = 0; j <= n; j++) System.out.print(root[i][j] + " ");
			System.out.println();
		}
	
	System.out.println(" COST ");
	for(i = 0; i <= n; i++)
		{
			for(j = 0; j <= n; j++) System.out.print(cost[i][j] + " ");
			System.out.println();
		}
	
	System.out.println(" WEIGHT ");
	for(i = 0; i <= n; i++)
		{
			for(j = 0; j <= n; j++) System.out.print(weight[i][j] + " ");
			System.out.println();
		}
	
	}
}
