// Exercise 3.13: Invoice.

package lab2part1;

public class Invoice
{
	// Instance variables.
	private String partNumber;
	private String partDescription;
	private int quantity;
	private double price;
	
	public Invoice () 
	{
		setPartNumber ("A");
		setPartDescription ("Sword");
		setQuantity (100);
		setPrice (0.05);
	}
	public Invoice (String partNumber, String partDescription, int quantity, double price)
	{
		setPartNumber (partNumber);
		setPartDescription(partDescription);
		setQuantity (quantity);
		setPrice(price);
	}
	
	public void setPartNumber (String partNumber)
	{
		this.partNumber = partNumber;
	}
	public void setPartDescription (String partDescription)
	{
		this.partDescription = partDescription;
	}
	public void setQuantity (int quantity)
	{
		if (quantity > 0)
			this.quantity = quantity;
		else
			this.quantity = 0;
	}
	public void setPrice (double price)
	{
		if (price > 0)
			this.price = price;
		else
			this.price = 0.0;
	}

	public String getPartNumber ()
	{
		return partNumber;
	}
	public String getPartDescription ()
	{
		return partDescription;
	}
	public int getQuantity ()
	{
		return quantity;
	}
	public double getPrice ()
	{
		return price;
	}
	public double getInvoiceAmount()
	{
		return getQuantity () * getPrice();
	}
}