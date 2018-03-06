package tests;

import java.io.BufferedReader;
import java.io.FileReader;

import data_structures.*;
import dns_resolver.*;

public class HashTester {
	static HashI<URL,IPAddress> llist = null;

	/**
	 * @param args
	 * The main method. In this case, we don't accept any arguments. We create a new linked list object
	 * and fill it with Integers.
	 */
	public static void main(String[] args) {

		BufferedReader file;
		String filename = "src/data/ips_small.txt"; //we load the easiest .txt for testing
		String line;
		boolean error = false;
		int n;
		
		try {
			llist = new Hash<URL,IPAddress>(10);
			file = new BufferedReader(new FileReader(filename));	//file with different URLs
			n = 0;
			
			// load the 21 different URLs to the LinkedList
			while((line = file.readLine()) != null)	{
				String[] value = line.split("\t");
				llist.add(new URL(value[1]), new IPAddress(value[0]));
				n++;
			}

			file.close();
			// the last thing in the list should be the URL edwards.sdsu.edu
			if (!llist.contains(new URL("edwards.sdsu.edu"))) {
				System.err.println("Come on man!. The URL edwards.sdsu.edu should be on the List but it ain't!");
				error = true;
			}
			
			// the size should be n
			if (llist.size() != n) {
				System.err.println("Yo, You added " + n + " stuffs to the list, but the size is " + llist.size());
				error = true;
			}

			// check the list with the iterator. 
			System.out.println("Using the cool iterator to print the whole shit from on Hash");
			int x=0;
			for (URL url : llist)	{
				x++;
				System.out.print(x+". "+url.toString()+" ");
				if (x%5 == 0)	{
					System.out.println("");
				}
			}
			System.out.println();
			
			//Change one value on the hash
			llist.changeValue(new URL("edwards.sdsu.edu"), new IPAddress("192.168.1.2"));
			if (!llist.getValue(new URL("edwards.sdsu.edu")).equals(new IPAddress("192.168.1.2")))	{
				System.err.println("All right, all right. Don't panick. Check your getValue/changeValue methods or your equals() in your IPAdress.");
				error = true;
			}	

			file = new BufferedReader(new FileReader(filename));
			// remove from  list ... 
			while ((line = file.readLine()) != null) {
				String[] valueToRemove = line.split("\t");
				if ( !llist.remove(new URL(valueToRemove[1]))) {
					System.err.println("No way, A remove method that does not remove? are you serious?");
					error = true;
				}
			}

			// the size should be 0
			if (llist.size() != 0) {
				System.err.println("All right, The hash should be empty bro, but the size is " + llist.size());
				error = true;
			}

		}
		catch (Exception e) {
			System.err.println("OMG, You better fix your code quick man because the due date is around the corner." +
					" Take a look at this stack trace to see what is wrong:");
			e.printStackTrace();
			System.exit(-1);
		}
		if (error)
			System.out.println("SHIT!. You have tons of errors in your code yo");
		else
			System.out.println("HELL YEAH!. You, nerd, are ready to impress edwards");
	}
}