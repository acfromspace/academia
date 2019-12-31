package lab3part2;

// Date : February 27, 2014
// Project: Problem 4.21
// Description: Write a pseudocode program, then a Java application 
// that inputs a series of integers and determines and prints the largest integer.

import java.util.Scanner;

public class SalesContest 
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);	
		
		int number;
		int counter;
		int largest;
		
		counter = 1;
		largest = Integer.MIN_VALUE;
		
		while (counter <= 10)
		{
			System.out.printf("Enter #%d: ", counter);
			number = input.nextInt();
			
			if (number > largest)
				largest = number;
			
			counter += 1;
		}
		System.out.printf("\nThe largest value is: %d\n", largest);
		input.close();
	}
}
