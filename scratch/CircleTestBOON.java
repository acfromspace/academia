package test1;

import java.util.Scanner;

public class CircleTest {

	public static void main(String[] args) {
		
		//create the objects
		Circle myRadius = new Circle(10);
		Circle yourRadius = new Circle();
		
		
		//read a value for yourRadius
		Scanner input = new Scanner (System.in);
		System.out.print ("Please enter a radius: ");
		double newRadius = input.nextDouble();
		yourRadius.setRadiusNumber(newRadius);
		
		
		
		
		//display the invoice 
		yourRadius.displayMessage();
		myRadius.displayMessage();
		
	}

}
