package lab4part1;

import java.text.DecimalFormat;
import java.util.Scanner;

public class Figure622CSIS293 
{
	private static Scanner input;

	public static void main(String[] args) 
	{
		input = new Scanner(System.in);

		int decision;
		double inputF;
		double inputC;
		double outputF;
		double outputC;
		
		DecimalFormat df = new DecimalFormat(".#");
		
		System.out.println
		(
			"Temperature Conversion Program\n\n" +
			"1. Change Farenheit to Celsius.\n" +
			"2. Change Celsius to Farenheit.\n" +
			"3. Quit.\n\n" +
			"Please choose an option (1-3)."
		);

		decision = input.nextInt();
		
		if (decision == 1)
		{
			System.out.println("Please put in temperature of Farenheit: ");
			inputF = input.nextInt();
			outputC = 5.0 / 9.0 * (inputF - 32);
			System.out.printf("Converted temperature of Farenheit to Celsius is " + df.format(outputC) + ".");
		}
		else
			if (decision == 2)
			{
				System.out.println("Please put in temperature of Celsius: ");
				inputC = input.nextInt();
				outputF = 9.0 / 5.0 * inputC + 32;
				System.out.printf("Converted temperature of Celsius to Farenheit is " + df.format(outputF) + ".");
			}
			else
				if (decision ==3)
					System.out.print("Have a good day!");
				else
					System.out.println("ERROR: INVALID INPUT, PLEASE RESTART PROGRAM.");
	}
}
