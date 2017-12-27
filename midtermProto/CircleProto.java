package midtermProto;

// Author: Andrew Christopher De Leon
// Date: 28 March 2014
// Project: Midterm
// Description: Circle

import java.util.Scanner;

public class CircleProto
{
	private Scanner input;
	public void CircleProgram()
	{
		input = new Scanner (System.in);
		double radius = 0;
		System.out.print("Enter the radius (negative to quit): ");
		
		while (radius >= 0)
		{
			radius = input.nextDouble();
			
			System.out.println("Area is "+circleArea(radius));
			System.out.print("Please enter the radius (negative to quit): ");
		}
		
	}
	public double circleArea(double radius)
	{
		return Math.PI*radius*radius;
	}
}

	
