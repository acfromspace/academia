package midterm2014;

//Author: Andrew Christopher De Leon
//Date: 28 March 2014
//Project: Midterm
//Description: Circle

public class Circle 
{
	// Declare instance variables
	private double radius;
	private double area;
	
	// Two constructors that calculate the area of the circle
	
	// Default constructor
	public Circle()
	{
		radius = 5;
		area = (5*5*Math.PI);
	}
	
	// Input constructor
	public Circle(double newRadius)
	{
		radius = newRadius;
		area = (newRadius*newRadius*Math.PI);
	}
	
	// Set/Get methods
	
	// Set method
	public void setRadiusNumber (double radiusNumber)
	{
		radius = radiusNumber;
		area = (radius*radius*Math.PI);
	}
	public void setAreaNumber (double areaNumber)
	{
		area = (radius*radius*Math.PI);
	}
	
	// Get method
	public double getRadius() 
	{
		return radius;
	}
	public double getArea()
	{
		return area;
	}

	// Print the radius and area values
	public void displayMessage()
	{
		System.out.printf("The radius inputted is %.2f\nThe area of the ricle is %.2f\n\n", radius, area);
	}
	
}
