package test;

public class Boon1{
	//declare instance variables 
	
	private double radius;
	private double area;
	//methods, constructors first
	
	public Boon1() {
		radius =(10);
		area =(10*10*Math.PI);
	}
	public Boon1(double newRadius){
		radius = newRadius;
		area = (newRadius*newRadius*Math.PI);
	}
	//set/get methods
	public void setRadiusNumber (double radiusNumber){
		radius = radiusNumber;
		area = (radius*radius*Math.PI);
	}
	public void setAreaNumber (double areaNumber){
		area = (radius*radius*Math.PI);
	}
	
	
	//get method
	public double getRadius() {
		return radius;
	}
	public double getArea() {
		return area;
	}
	
	
	
	public void displayMessage() {
		System.out.printf("The radius is %.2f\nThe area of the circle is %.2f\n\n",radius, area);
	}
	

}
