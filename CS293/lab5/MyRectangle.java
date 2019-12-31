package lab5;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;

public class MyRectangle 
{
	// Declarations.
	private Random randomNumbers = new Random();
	private int x1 = randomNumbers.nextInt( 300 );
	private int y1 = randomNumbers.nextInt( 300 );
	private int x2 = randomNumbers.nextInt( 300 );
	private int y2 = randomNumbers.nextInt( 300 );
	private int height = 0;
	private int width = 0;
	private int upperLeftX = 0;
	private int upperLeftY = 0;
	private Color myColor;
	boolean filled;
	
	public MyRectangle(int x, int y, int theHeight, int theWidth, Color myColor, boolean filled)
	{
		setUpperLeftX(x);
		setUpperLeftY(y);
		setHeight(theHeight);
		setWidth(theWidth);
		this.myColor = Color.BLACK;
		this.filled = filled;
	}
	
	public void setUpperLeftX(int x)
	{
		if (x1 < x2)
			upperLeftX = x1;
		else
			upperLeftX = x2;
	}
	
	public int getUpperLeftX()
	{
		return upperLeftX;
	}
	
	public void setUpperLeftY(int y)
	{
		if (y1 < y2)
			upperLeftX = y1;
		else
			upperLeftX = y2;
	}
	
	public int getUpperLeftY()
	{
		return upperLeftY;
	}
	
	public void setWidth(int theWidth)
	{
		width = Math.abs(x1 - x2);
	}
	
	public int getWidth()
	{
		return width;
	}
	
	public void setHeight(int theHeight)
	{
		height = Math.abs(y1 - y2);
	}
	
	public int getHeight()
	{
		return height;
	}
	
	public void draw( Graphics g )
	{
		g.setColor( myColor );
		g.drawRect( upperLeftX, upperLeftY, height, width );
	}
}
