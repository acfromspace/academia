package project1;

public class Project1 
{

	public static void main(String[] args) 
	{
		int row;
		int asterisk;
		int spaces;
		String diamondString = "";
		
		for ( row = 1; row <= 5; row++ )
		{
			for ( spaces = 5; spaces > row; spaces-- )
				diamondString += " ";
			
			for ( asterisk = 1; asterisk <= (2 * row) - 1; asterisk++ )
				diamondString += "*";
			
			diamondString += "\n";
		}
		
		for ( row = 4; row >= 1; row-- )
		{
			for ( spaces = 5; spaces > row; spaces -- )
						diamondString += " ";
					
			for ( asterisk = 1; asterisk <= ( 2 * row ) - 1; asterisk++ )
						diamondString += "*";
					
			diamondString += "\n";
		}
		System.out.println ( diamondString );
		System.exit(0);	
	}
}
