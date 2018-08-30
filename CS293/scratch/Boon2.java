package test;

import java.util.Scanner;

public class Boon2 {

	private static Scanner input;

	public static void main(String[] args) {
		
		//create the objects
		Boon1 myRadius = new Boon1(10);
		Boon1 yourRadius = new Boon1();
		
		
		input = new Scanner (System.in);
		System.out.print ("Please enter a radius: ");
		double newRadius = input.nextDouble();
		yourRadius.setRadiusNumber(newRadius);
		
		
		
		
		//display the invoice 
		yourRadius.displayMessage();
		myRadius.displayMessage();
		
	}

}
