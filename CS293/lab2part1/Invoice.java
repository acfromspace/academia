package lab2part1;

// Exercise 3.13: Invoice
// By Andrew Christopher De Leon.

public class Invoice 
{
	//instance variables
	private String partNumber;
	private String partDescription;
	private int quantity;
	private double price;

	//methods, constructor first
	
	public Invoice () {
		//use the 'set' methods
		setPartNumber ("A");
		setPartDescription ("Sword");
		setQuantity (100);
		setPrice (0.05);
		
	} //end default/no argument constructor
	public Invoice (String partNumber, String partDescription, int quantity, double price) {
		setPartNumber (partNumber);
		setPartDescription(partDescription);
		setQuantity (quantity);
		setPrice(price);
	} // end constructor to 'initialize' objects
	
	// set methods
	public void setPartNumber (String partNumber) {
		this.partNumber = partNumber;
	}
	public void setPartDescription (String partDescription) {
		this.partDescription = partDescription;
	}
	public void setQuantity (int quantity) {
		//check to make sure the quantity is positive
		if (quantity > 0)
			this.quantity = quantity;
		else
			this.quantity = 0;
	}
	public void setPrice (double price) {
		if (price > 0)
			this.price = price;
		else
			this.price = 0.0;
	}
	// get methods
	public String getPartNumber () {
		return partNumber;
	}
	public String getPartDescription () {
		return partDescription;
	}
	public int getQuantity () {
		return quantity;
	}
	public double getPrice () {
		return price;
	}
	// do invoice calculation
	public double getInvoiceAmount() {
		return getQuantity () * getPrice();
	} //end method getInvoiceAmount
} //end class Invoice