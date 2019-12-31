/* 
 * @author kingofthenorth
 * @authorid 123456789
*/

package dns_resolver;

/**
 * The IPAddress is using iIPv4 and has dotted-decimal notation, with the network, two subnets, 
 * and host separated by periods. For example, the IP address 130.191.226.146 has 
 * a network of 130, a subnet of 191, the second subnet is 226, and the host address is 146.
 * 
 * Your IPAddress class should accept a string of dotted-decimal IPAddresses in the constructor
 * and separate them into the components. 
 * 
 * @see <a href="https://en.wikipedia.org/wiki/IP_address#IPv4_addresses">Wikipedia IPv4 addresses</a>
 * @author redwards
 *
 */

public class IPAddress implements Comparable<IPAddress> {

	int network;
	int subnet;
	int subnet2;
	int host;
	String IP;

	/**
	 * The constructor for the IPAddress class.
	 * 
	 * @param ip (xxx.xxx.xx.xx)
	 */
	public IPAddress(String ip) {
		//this.IP = IP;
		String data[] = ip.split("\\.");
		network = Integer.parseInt(data[0]);
		subnet = Integer.parseInt(data[1]);
		subnet2 = Integer.parseInt(data[2]);
		host = Integer.parseInt(data[3]);
	}


	// Returns a unique integer.
	@Override
	public int hashCode() {
		final int prime = 19;
		int result = 1;
		result = prime * result + host;
		result = prime * result + network;
		result = prime * result + subnet;
		result = prime * result + subnet2;
		return result;
	}

	// Compares the IP class.
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		IPAddress other = (IPAddress) obj;
		if (host != other.host)
			return false;
		if (network != other.network)
			return false;
		if (subnet != other.subnet)
			return false;
		if (subnet2 != other.subnet2)
			return false;
		return true;
	}

	// Prints said network, subnet, subnet2, & host.
	@Override
	public String toString() {
		return "IPAddress (Network, subnet, subnet2, host):" + network + "." + subnet + "." + subnet2 + "." + host;
	}

	// Compares IP.
	@Override
	public int compareTo(IPAddress o) {
		if(Integer.compare(this.network, o.network) != 0)
			return Integer.compare(this.network, o.network);
		
		if(Integer.compare(this.subnet, o.subnet) != 0)
			return Integer.compare(this.subnet, o.subnet);
		
		if(Integer.compare(this.subnet2, o.subnet2) != 0)
			return Integer.compare(this.subnet2, o.subnet2);
		
		return Integer.compare(this.host, o.host);
	}
}
