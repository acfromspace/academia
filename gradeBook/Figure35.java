package gradeBook;

// Fig. 3.5: GradeBookTest.java
// Create GradeBook object and pass a String to
// its displayMessage method.

import java.util.Scanner; // program uses Scanner

public class Figure35 
{
	private static Scanner input;

	// main method begins program execution
	public static void main(String[] args) 
	{
		input = new Scanner ( System.in );
		
		// create a Figure 34 object and assign it to myGradeBook
		Figure34 myGradeBook = new Figure34();
		
		//prompt for and input course name
		System.out.println( "Please enter the course name:");
		String nameOfCourse = input.nextLine(); // read a line of text
		System.out.println(); // outputs a blank line
		
		// call myGradeBook's displayMessage method
		// and pass nameOfCourse as an argument
		myGradeBook.displayMessage( nameOfCourse );
	} // end main
} // end class GradeBookTest
