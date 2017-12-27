package lab1part3;

// Fig. 2.7: Addition.java
import java.util.Scanner;

public class Figure27CSIS293 {

	private static Scanner input;

	public static void main(String[] args)
	{
		input = new Scanner( System.in );
		
		int number1;
		int number2;
		int sum;
		
		System.out.print( "Enter first integer: " );
		number1 = input.nextInt();
		
		System.out.print( "Enter second integer: " );
		number2 = input.nextInt();
		
		sum = number1 + number2;
		
		System.out.printf( "Sum is %d\n", sum);
	}
}
