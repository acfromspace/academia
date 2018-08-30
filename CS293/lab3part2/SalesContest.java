package lab3part2;

//Author: Andrew Christopher De Leon
//Date : February 27, 2014
//Project: Problem 4.21
//Description: Write a pseudocode program, then a Java application 
//	that inputs a series of 1- integers and determines and prints the largest integer.

import java.util.Scanner;

public class SalesContest 
{
	public static void main(String[] args) 
	{
		// Able to put inputs
		Scanner input = new Scanner(System.in);	
		
		// Declarations
		int number;
		int counter;
		int largest;
		
		// Initialize the control variable and largest
		counter = 1;
		largest = Integer.MIN_VALUE;
		
		// Perform 'while' statement
		while (counter <=10)
		{
			System.out.printf("Enter #%d: ", counter);
			number = input.nextInt();
			
			if (number > largest)
				largest = number;
			
			counter += 1;
		} // End 'while' statement
		// Display 'largest'
		System.out.printf("\nThe largest value is: %d\n", largest);
		
		// Shuts down 'input' process
		input.close();
	} // End 'method'
} // End 'class'
