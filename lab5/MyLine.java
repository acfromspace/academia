package lab5;

// Author: Andrew Christopher De Leon
//Fig. 8.18

import java.awt.Color;
import java.awt.Graphics;

public class MyLine 
{
	// Declarations
	private int x1;
	private int y1;
	private int x2;
	private int y2;
	private Color myColor;
	
	// Constructor
	public MyLine( int x1, int y1, int x2, int y2, Color myColor)
	{
		this.x1 = x1; // Set first X endpoint
		this.y1 = y1; // Set first Y endpoint
		this.x2 = x2; // Set last X endpoint
		this.y2 = y2; // Set last Y endpoint
		this.myColor = myColor; // Setting color
	}
	
	// Draw the line
	public void draw( Graphics g )
	{
		g.setColor( myColor );
		g.drawLine( x1, y1, x2, y2 );
	}
}
