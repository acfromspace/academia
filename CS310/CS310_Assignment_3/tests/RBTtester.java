package tests;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import data_structures.RedBlackTree;
import data_structures.LinkedList;
import dns_resolver.IPAddress;
import dns_resolver.URL;

public class RBTtester {

	static boolean error = false;
	static int count = 0;
	static int RESET = 1;
	
	public static void main(String[] args)	{
		String filename = "src/data/ips_small.txt";
		LinkedList<IPAddress> list = new LinkedList<>();
		BufferedReader file;
		String line;
		/**
		 * Populate the LinkedList with all the 21 IP Address in the file.
		 */
		try{
			file = new BufferedReader(new FileReader(filename));
			while((line = file.readLine()) != null)	{
				String[] values = line.split("\t");
				list.add(new IPAddress(values[0]));
			}
			file.close();

			/**
			 * Populate the Tree with Integers and a String as a value for every Key.
			 */
			RedBlackTree<Integer,String> treeTest = new RedBlackTree<>();
			String test = "**HAKUNA MATATA**";
	
			// Simple tree adding to the Right Only
			for (int i = 1; i <= 20; i++)	{
				treeTest.add(i, test);
			}
			
			for (int i = 1; i <= 20; i++)	{
				if (!treeTest.contains(i))	{
					System.err.println("All the numbers from 0 - 19 should be on the Tree but they are not.");
					error = true;
				}
			}
			
			// Use the iterator to get all the keys in the Tree
			count = RESET;
			for (Integer key: treeTest)	{
				if (key != count)	{
					System.err.println("The order your iterator gives is wrong. In this code the order should be from 1-19.");
					error = true;
				}
				count++;
			}
			
			count= RESET;
			treeTest = null;
			treeTest = new RedBlackTree<>();
			
			// Simple tree adding to the Left Only
			for (int i = 20; i > 0; i--)	{
				treeTest.add(i, test);
			}
			
			for (int i = 20; i > 0; i--)	{
				if (!treeTest.contains(i))	{
					System.err.println("All the numbers from 0 - 19 should be on the Tree but they are not.");
					error = true;
				}
			}
			
			treeTest = null;
			
			/**
			 * Populate the Tree with all the 21 IP Address and URLs in the file.
			 */
			RedBlackTree<IPAddress, URL> RBTree = new RedBlackTree<>();
			
			file = new BufferedReader(new FileReader(filename));
			while((line = file.readLine()) != null)	{
				String[] values = line.split("\t");
				RBTree.add(new IPAddress(values[0]), new URL(values[1]));
			}
			
			file.close();

			/**
			 * From here on the Tree Is Tested.
			 */
			
			if (RBTree.size() != 21)	{
				System.err.println("The Size of the Tree should be 21 but it is not.");
				error = true;
			}

			 // Check the contains method in the Tree.
			for (IPAddress ip: list)	{
				if (!RBTree.contains(ip))	{
					System.err.println("All the items in the LinkedList should be on the Tree but they are not.");
					error = true;
				}
			}
			
			if (!RBTree.getValue(new IPAddress("130.191.226.146")).equals(new URL("edwards.sdsu.edu")))	{
				System.err.println("The returned value of 130.191.226.146 should be  edwards.sdsu.edu");
				error = true;
			}
			
			/**
			 * This is the order and the keys' levels that your tree should print.
 			...Key: 130.191.2.15 Value: e2900u.sdsu.edu : Red
			..Key: 130.191.130.7 Value: ads-pkg.ba.sdsu.edu : Black
			.Key: 130.191.27.56 Value: mimas.sdsu.edu : Black
			....Key: 130.191.3.101 Value: studmail.sdsu.edu : Red
			...Key: 130.191.15.220 Value: idmdev.sdsu.edu : Black
			....Key: 130.191.21.176 Value: d4.sdsu.edu : Red
			..Key: 130.191.213.58 Value: ind-tech-1-mac8.sdsu.edu : Red
			....Key: 130.191.226.31 Value: cosdedjowin7.sdsu.edu : Red
			...Key: 130.191.236.89 Value: lif-sci-s1-mac24.sdsu.edu : Black
			....Key: 130.191.241.33 Value: alv6475-1-mac32.sdsu.edu : Red
			Key: 130.191.35.234 Value: malbec1-mgt.sdsu.edu : Black
			...Key: 130.191.37.112 Value: debr.sdsu.edu : Red
			..Key: 130.191.65.172 Value: dyn-65-172.sdsu.edu : Black
			...Key: 130.191.125.121 Value: cpsfa.sdsu.edu : Red
			.Key: 130.191.136.187 Value: dyn-136-187.sdsu.edu : Black
			....Key: 130.191.163.215 Value: ecpc105.sdsu.edu : Red
			...Key: 130.191.165.205 Value: winterm.sdsu.edu : Black
			....Key: 130.191.200.129 Value: jalapeno.sdsu.edu : Red
			..Key: 130.191.224.165 Value: dyn-224-165.sdsu.edu : Red
			....Key: 130.191.226.146 Value: edwards.sdsu.edu : Red
			...Key: 130.191.241.157 Value: bmcgivern.sdsu.edu : Black
			 */
			RBTree.print();
			
			System.out.println("**************************************************************************************");
			System.out.println("This is what your Tree prints (Check in the comments inside the code- \n I wrote the exact order "
					+ "that your tree should print the keys and values \n if the levels or order is not the same, your print is wrong)");
		}
		catch (IOException e)	{
			System.err.println("Your Tree code threw an exception. You need to fix this." +
					" Take a look at this stack trace to see what is wrong:");
			e.printStackTrace();
			System.exit(-1);
		}
		if (error)
			System.out.println("FAIL. There were one or more errors while running the code");
		else
			System.out.println("SUCCESS. All the tests ran");
	}
}