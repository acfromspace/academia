/* 
 * @author Andrew De Leon
 * @authorid 819470542
*/

package dns_resolver;

/**
 * A URL Object is a representation of the URL that we have been giving. 
 * It knows how to compare URLs!
 * 
 * @author redwards
 *
 */

public class URL implements Comparable<URL> {
	String url;
	
	// Intiailizes the url.
	public URL (String url) {
		this.url = url;
	}
	
	// Return compare method.
	public int compareTo(URL obj) {
		return url.compareTo(obj.url);
	}

	// Uses Java's object superclass method for hashCode
	public int hashCode() {
		return url.hashCode();
	}

	// Uses Java's object superclass method for equals
	public boolean equals(Object obj) {
		return url.equals(obj);
	}

	// String url returned.
	public String toString() {
		return this.url;
	}
}

