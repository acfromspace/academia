package lab2part1;

import lab2part1.Invoice;

public class InvoiceTest 
{

public static void main(String[] args) 
	{
	// declare local variables/references
	Invoice invoice1, invoice2;
	
	//create the objects
	invoice1 = new Invoice();
	invoice2 = new Invoice("B", "Shield", 1, 10.00);
	
	//display the invoice amounts
	System.out.printf ("Invoice1: Item-%s, Amount Due: $%.2f\n",invoice1.getPartDescription(),invoice1.getInvoiceAmount());
	System.out.printf ("Invoice2: Item-%s,Amount Due: $%.2f\n", invoice2.getPartDescription(),invoice2.getInvoiceAmount());
	}
}