package dns_resolver;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import data_structures.Hash;
import data_structures.HashI;
import exceptions.FileFormatException;


/**
 * The LoadInternetAddresses class should take a filename as a string, uses BufferedReader
 * to read the file, split the lines into URLs and IPAddresses, and create the appropriate
 * objects. It should add those objects to a hash, and finally, after reading the whole file
 * it should return the instance of the hash.
 * 
 * If there is an error with the file format, you should throw a new FileFormatException error
 * with an appropriate message.
 *  
 * @author kingofthenorth
 *
 */

public class LoadInternetAddresses {
	HashI<URL, IPAddress> storedAddresses;
	
	public LoadInternetAddresses() {
		storedAddresses = new Hash<URL, IPAddress>(50);
	}
	
	/**
	 * loads string directory and parses it into legible string.
	 * @param filename
	 * @return
	 * @throws FileFormatException
	 */	
	
	public HashI<URL, IPAddress> load_addresses(String filename) throws FileFormatException {
		BufferedReader readFile = null;
		try {
			 readFile = new BufferedReader(new FileReader(filename));
		} catch (FileNotFoundException e) {
			System.err.println("File not found.");
		}
		String line;
		try {
			while ((line = readFile.readLine()) != null) {
				String[] values = line.split("\t");
				if (values.length != 2)
					throw new FileFormatException("Incorrect file format.");
				IPAddress ip =  new IPAddress(values[0]);
				URL url = new URL(values[1]);
				storedAddresses.add(url, ip);
			}
		}  catch (IOException e) {
			throw new FileFormatException("Incorrect file format.");
		}
	return storedAddresses;
	}
}
