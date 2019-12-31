/*
 * @author kingofthenorth
 * @authorid 123456789
 * 
 * For null pointer exceptions use:
 * 
 * 		try {
 * 			System.out.println("Testing.");
 *		} catch (Exception e) {
 *			e.printStackTrace();
 *		}
*/

package timeDataStructures;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.TreeMap;

import data_structures.Hash;
import data_structures.HashI;
import data_structures.LinkedList;
import data_structures.RedBlackTree;
import dns_resolver.IPAddress;
import dns_resolver.URL;

public class TimeHashRBTree {

	public static void main(String[] args) {
		
		LinkedList<IPAddress> list = new LinkedList<>();
		HashI<IPAddress, URL> hash = new Hash<IPAddress, URL>(250000);
		RedBlackTree<IPAddress, URL> rbt = new RedBlackTree<IPAddress, URL>();
		HashMap<IPAddress, URL> javahash = new HashMap<IPAddress, URL>();
		TreeMap<IPAddress, URL> javarbt = new TreeMap<IPAddress, URL>();
		BufferedReader input = null;
		String line;
		
		System.out.println("*TIME USED FOR THE IP ADDRESSES*\n");
		
		long start = System.currentTimeMillis();
		
		// Add LinkedList
		try {
			input = new BufferedReader(new FileReader("src/data/top-250k.ip"));
			while((line = input.readLine()) != null) {
				String[]values = line.split("\t");
				list.add(new IPAddress(values[1]));
			}
		}
		
		catch(Exception e) {
			System.err.println(e);
		}
		
		// Add Hash
		long startSweetHashAdd = System.currentTimeMillis();
		
		try {
			input = new BufferedReader(new FileReader("src/data/top-250k.ip"));
			while((line = input.readLine()) != null) {
				String[]values = line.split("\t");
				IPAddress ipAddress = new IPAddress(values[1]);
				URL url = new URL(values[0]);
				hash.add(ipAddress, url);
			}
		}
		
		catch(Exception e) {
			System.err.println(e);
		}
		
		long stopSweetHashAdd = System.currentTimeMillis();
		
		System.out.println("Add with hash: " + (stopSweetHashAdd - startSweetHashAdd) + " milliseconds");
		
		// Search hash
		long startSweetHashSearch = System.currentTimeMillis();
		
		for(IPAddress ip:list)
			hash.contains(ip);
		
		long stopSweetHashSearch = System.currentTimeMillis();
		
		System.out.println("Search with hash: " + (stopSweetHashSearch - startSweetHashSearch) + " milliseconds\n");
		
		// Clear memory
		hash = null;
		
		// Add RBT
		long startSweetRBTAdd = System.currentTimeMillis();
		
		try {
			input = new BufferedReader(new FileReader("src/data/top-250k.ip"));
			while((line = input.readLine()) != null) {
				String[]values = line.split("\t");
				IPAddress ipAddress = new IPAddress(values[1]);
				URL url = new URL(values[0]);
				rbt.add(ipAddress, url);
			}
		}
		
		catch(Exception e) {
			System.err.println(e);
		}
		
		long stopSweetRBTAdd = System.currentTimeMillis();
		
		System.out.println("Add with RBT: " + (stopSweetRBTAdd - startSweetRBTAdd) + " milliseconds");
		
		// Search RBT
		long startSweetRBTSearch = System.currentTimeMillis();
		
		for(IPAddress ip : list)
			rbt.getValue(ip);

		long stopSweetRBTSearch = System.currentTimeMillis();
		
		System.out.println("Search with RBT: " + (stopSweetRBTSearch - startSweetRBTSearch) + " milliseconds\n");

		// Add Java's hash
		long startJavaHashAdd = System.currentTimeMillis();
		
		try {
			input = new BufferedReader(new FileReader("src/data/top-250k.ip"));
			while((line = input.readLine()) != null) {
				String[]values = line.split("\t");
				IPAddress ipAddress = new IPAddress(values[1]);
				URL url = new URL(values[0]);
				javahash.put(ipAddress, url);
			}
		}
		
		catch(Exception e) {
			System.err.println(e);
		}
		
		long stopJavaHashAdd = System.currentTimeMillis();
		
		System.out.println("Add with Java's hash: " + (stopJavaHashAdd - startJavaHashAdd) + " milliseconds");
		
		// Search Java's Hash
		long startJavaHashSearch = System.currentTimeMillis();
		
		for(IPAddress ip:list)
			javahash.get(ip);
		
		long stopJavaHashSearch = System.currentTimeMillis();
		
		System.out.println("Search with Java's hash: " + (stopJavaHashSearch - startJavaHashSearch) + " milliseconds\n");
		
		// Add Java's RBT
		long startJavaRBTAdd = System.currentTimeMillis();
		
		try {
			input = new BufferedReader(new FileReader("src/data/top-250k.ip"));
			while((line = input.readLine()) != null) {
				String[]values = line.split("\t");
				IPAddress ipAddress = new IPAddress(values[1]);
				URL url = new URL(values[0]);
				javarbt.put(ipAddress, url);
			}
		}
		
		catch(Exception e) {
			System.err.println(e);
		}
		
		long stopJavaRBTAdd = System.currentTimeMillis();
		
		System.out.println("Add with Java's RBT: " + (stopJavaRBTAdd - startJavaRBTAdd) + " milliseconds");
		
		// Search Java's RBT
		long startJavaRBTSearch = System.currentTimeMillis();
		
		for(IPAddress ip:list)
			javarbt.get(ip);
		
		long stopJavaRBTSearch = System.currentTimeMillis();
		
		System.out.println("Search with Java's RBT: " + (stopJavaRBTSearch - startJavaRBTSearch) + " milliseconds\n");
		
		long stop = System.currentTimeMillis();
		
		System.out.println("PROGRAM FINISHED. NO ERRORS.\n");
		
		System.out.println("Total time for program: " + (stop - start) + " milliseconds");
	}
}
