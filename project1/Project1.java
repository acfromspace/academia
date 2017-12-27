package project1;

//Author: Andrew Christopher De Leon

public class Project1 
{

	public static void main(String[] args) 
	{
		int row;
		int asterisk;
		int spaces;
		String diamondString = "";
		
		//Top first 5 lines
		for ( row = 1; row <= 5; row++ )
		{
			for ( spaces = 5; spaces > row; spaces-- )
				diamondString += " ";
			
			for ( asterisk = 1; asterisk <= (2 * row) - 1; asterisk++ )
				diamondString += "*";
			
			diamondString += "\n";
		}
		
		//Bottom last 4 lines
		for ( row = 4; row >= 1; row-- )
		{
			for ( spaces = 5; spaces > row; spaces -- )
						diamondString += " ";
					
			for ( asterisk = 1; asterisk <= ( 2 * row ) - 1; asterisk++ )
						diamondString += "*";
					
			diamondString += "\n";
		}
		
		//Output result
		System.out.println ( diamondString );
		
		System.exit(0);
		
	} //End void
	
} //End class project 1
