// Date : February 27, 2014
// Project: Problem 4.17 Part A
// Description: Input the miles driven and gallons used for each trip.

package lab3part1;

import java.util.Scanner;

public class GasTank 
{
	public void calculateMPG() 
	{
		Scanner input = new Scanner( System.in );
		
		int miles;
		int gallons;
		int totalMiles = 0;
		int totalGallons = 0;
		
		double milesPerGallon;
		double totalMilesPerGallon;
		
		System.out.print( "Please input miles driven (-1 to quit): " );
		miles = input.nextInt();
		
		while ( miles != -1 )
		{
			System.out.print( "Please input gallons used: " );
			gallons = input.nextInt();
			totalMiles += miles;
			totalGallons += gallons;
		
			if ( gallons != 0 )
			{
				milesPerGallon = (double) miles / gallons;
				
				System.out.printf( "MPG this tankful: %.2f\n", milesPerGallon );
			}
			
			if ( totalGallons != 0 )
			{
				totalMilesPerGallon = (double) totalMiles / totalGallons;
				System.out.printf( "Total MPG: %.2f\n", totalMilesPerGallon );
			}
			
			System.out.print( "Please input miles driven (-1 to quit): " );
			miles = input.nextInt();
		}
		input.close();
	}
}
