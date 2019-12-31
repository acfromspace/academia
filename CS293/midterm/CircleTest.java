package midterm2014;

// Date: 28 March 2014
// Project: Midterm
// Description: Circle.

import java.util.Scanner;

public class CircleTest 
{
	private static Scanner input;
	public static void main() 
	{
		Circle myRadius = new Circle(5);
		Circle yourRadius = new Circle();
		
		input = new Scanner (System.in);
		System.out.print ("Please enter a radius: ");
		double newRadius = input.nextDouble();
		yourRadius.setRadiusNumber(newRadius);
		
		yourRadius.displayMessage();
		myRadius.displayMessage();
	}
}
