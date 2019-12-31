// Fig. 2.28: Diameter, Circumference and Area of a Circle.

package lab1part4;

import java.util.Scanner;

public class Figure228CSIS293
{
	private static Scanner input;

	public static void main(String[] args) 
	{
		input = new Scanner( System.in );
		
		int radius;
		
		System.out.println( "Enter a radius please cool guy: " );
		radius = input.nextInt();
		
		System.out.printf( "\nDiameter is %d", ( 2 * radius) );
		System.out.printf( "\nCircumference is %f", ( 2 * Math.PI * radius) );
		System.out.printf( "\nArea is %f", ( Math.PI * radius * radius ) );
	}

}
