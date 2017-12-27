package lab3part1;

// Author: Andrew Christopher De Leon
// Date : February 27, 2014
// Project: Problem 4.17 Part A
// Description: Input the miles driven and gallons used for each trip.

import java.util.Scanner;

public class GasTank 
{
	// Perform miles-per-gallon calculations
	
	public void calculateMPG() 
	{
		// Able to put inputs
		Scanner input = new Scanner( System.in );
		
		// Declarations
		int miles;
		int gallons;
		int totalMiles = 0;
		int totalGallons = 0;
		
		double milesPerGallon;
		double totalMilesPerGallon;
		
		// Obtain miles from user
		System.out.print( "Please input miles driven (-1 to quit): " );
		miles = input.nextInt();
		
		// Proceeds with program until the input is -1
		while ( miles != -1 )
		{
			// Obtain gallons from user
			System.out.print( "Please input gallons used: " );
			gallons = input.nextInt();
		
			// Add miles and gallons together for total
			totalMiles += miles;
			totalGallons += gallons;
		
			// Calculate miles per gallon for current tank
			if ( gallons != 0 )
			{
				milesPerGallon = (double) miles / gallons;
				
				System.out.printf( "MPG this tankful: %.2f\n", milesPerGallon );
			} // End 'if' statement
			
			// Calculate miles per gallon for the total trip
			if ( totalGallons != 0 )
			{
				totalMilesPerGallon = (double) totalMiles / totalGallons;
				System.out.printf( "Total MPG: %.2f\n", totalMilesPerGallon );
			} // End 'if' statement
			
			// Obtain new value for miles
			System.out.print( "Please input miles driven (-1 to quit): " );
			miles = input.nextInt();
		} // End 'while' loop
		
		// Shuts down 'input' process
		input.close();
	} // End 'method' calculateMPG
} // End 'class' GasTank
