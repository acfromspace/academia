// Fig. 8.19

package lab5;

import java.awt.Color;
import java.awt.Graphics;
import java.util.Random;
import javax.swing.JPanel;

public class DrawPanel extends JPanel
{
	private Random randomNumbers = new Random();
	private MyLine lines[]; // Array of lines.
	private MyRectangle rectangles[]; // Array of rectangles.
	private MyOval ovals[]; // Array of rectangles.
	
	// Constructor, creates a panel with random shapes.
	public DrawPanel()
	{
		setBackground( Color.WHITE );
		
		// Amount of shapes 5 + random.
		lines = new MyLine[ 5 + randomNumbers.nextInt( 5 ) ];
		rectangles = new MyRectangle[ 5 + randomNumbers.nextInt( 5 )];
		ovals = new MyOval[ 5 + randomNumbers.nextInt( 5 )];
		
		// Create lines.
		for ( int count = 0; count < lines.length; count++ )
		{
			// Generate random coordinates.
			int x1 = randomNumbers.nextInt( 300 );
			int y1 = randomNumbers.nextInt( 300 );
			int x2 = randomNumbers.nextInt( 300 );
			int y2 = randomNumbers.nextInt( 300 );
			
			// Generate a random color.
			Color myColor = new Color( randomNumbers.nextInt( 256 ),
				randomNumbers.nextInt( 256 ), randomNumbers.nextInt( 256 ) );
			
			// Add the line to the list of lines to be displayed.
			lines[ count ] = new MyLine( x1, y1, x2, y2, myColor);
		}
		
		// Create rectangles.
		for (int count = 0; count < rectangles.length; count++)
		{
			// Generate random coordinates.
			int x1 = randomNumbers.nextInt( 300 );
			int y1 = randomNumbers.nextInt( 300 );
			int x2 = randomNumbers.nextInt( 300 );
			int y2 = randomNumbers.nextInt( 300 );
			
			// Generate a random color.
			Color myColor = new Color( randomNumbers.nextInt( 256 ),
				randomNumbers.nextInt( 256 ), randomNumbers.nextInt( 256 ) );
			
			// Add the rectangles to the list of rectangles to be displayed.
			rectangles[count] = new MyRectangle( x1, y1, x2, y2, myColor, true);
		}
		
		// Create rectangles.
		for (int count = 0; count < ovals.length; count++)
		{
			// Generate random coordinates.
			int x1 = randomNumbers.nextInt( 300 );
			int y1 = randomNumbers.nextInt( 300 );
			int x2 = randomNumbers.nextInt( 300 );
			int y2 = randomNumbers.nextInt( 300 );
					
			// Generate a random color.
			Color myColor = new Color( randomNumbers.nextInt( 256 ),
				randomNumbers.nextInt( 256 ), randomNumbers.nextInt( 256 ) );
					
			// Add the rectangles to the list of rectangles to be displayed.
			ovals[count] = new MyOval( x1, y1, x2, y2, myColor, true );
		}
				
	} // End 'constructor'.
	
	// For each shape array, draw the individual shapes.
	public void paintComponent( Graphics g )
	{
		super.paintComponent( g );
		
		// Draw the shapes.
		for ( MyLine line : lines)
			line.draw( g );
		
		for ( int count = 0; count < rectangles.length; count++)
			rectangles[count].draw( g );
		
		for ( int count = 0; count < ovals.length; count++)
			ovals[count].draw( g );
	} // End 'method'.
	
} // End 'class'.
